//
//
// Task 10.4. - Write class that will implement 'list' containing 'string' objects.
// Task 10.5. - Write bidirectional iterator for 'String_list' class.

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

class String_list
{
public:
	String_list(const string& str) {
		first_node_ptr = new Node(str);
		last_node_ptr = first_node_ptr;
	}
	void push(const string& str) {
		if (!first_node_ptr) { 
			first_node_ptr = new Node(str);
			last_node_ptr = first_node_ptr;
		}
		else {
			last_node_ptr->next = new Node(str, last_node_ptr);
			last_node_ptr = last_node_ptr->next;
		}
	}
	string pop() {
		if (!last_node_ptr) throw domain_error("Nothing to pop!");
		if (last_node_ptr == first_node_ptr) {
			string ret(last_node_ptr->data);
			delete last_node_ptr;
			last_node_ptr = NULL;
			first_node_ptr = NULL;
			return ret;
		}
		string ret(last_node_ptr->data);
		last_node_ptr = last_node_ptr->prev;
		delete last_node_ptr->next;
		last_node_ptr->next = NULL;
		return ret;
	}
	size_t size() {
		return getsize(first_node_ptr);
	}
	
	
private:
	String_list() {}
	typedef struct Node {
		Node* next;
		Node* prev;
		string data;
		Node() { }
		Node(const string& str, Node* prevn = NULL) {
			next = NULL;
			prev = prevn;
			data = str;
		}
	} Node;
	Node* first_node_ptr;
	Node* last_node_ptr;
	
	size_t getsize(Node *nxt) {
		if (!nxt) return 0;
		if (!nxt->next) return 1;
		return getsize(nxt->next) + 1;
	}

public:
	typedef Node* iterator;
	
	const iterator begin() const {
		return first_node_ptr;
	}
	
	const iterator end() const {
		return last_node_ptr;
	}
	
};



int _tmain(int argc, _TCHAR* argv[])
{
	String_list data("aaa");
	cout << data.size() << endl;
	data.push("bbb");
	cout << data.size() << endl;
	data.push("ccc");
	cout << data.size() << endl;
	
	try {
		while(true) {
			data.pop();
			cout << data.size() << endl;
		}
	} catch (domain_error e) {
		cout << e.what() << endl;
	}
	
	data.push("1");
	data.push("2");
	data.push("3");
	data.push("4");
	data.push("5");
	data.push("6");


	String_list::iterator it = data.begin();
	
	//for (; it != data.end(); ++it) {
	//	it->data = "new_val";
	//}

	//it = data.end();
	//
	//for (; it != data.begin(); --it) {
	//	it->data = "new_val";
	//}

	return 0;
}

