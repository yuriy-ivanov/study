//
//
// Task 10.4. - Write class that will implement 'list' containing 'string' objects.
// Task 10.5. - Write bidirectional iterator for 'String_list' class.
// Task 10.6. - Reimplement split() function so it's results will be stored in 'String_list'.

#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

class String_list
{
private:
	typedef class Node {
	public:
		Node* next;
		Node* prev;
		string data;
		Node() { }
		Node(const Node* n) {
			next = n->next;
			prev = n->prev;
			data = n->data;
		}
		Node(const string& str, Node* prevn = NULL) {
			next = NULL;
			prev = prevn;
			data = str;
		}
		
	} Node;
	
	size_t getsize(Node *nxt) {
		if (!nxt) return 0;
		if (!nxt->next) return 1;
		return getsize(nxt->next) + 1;
	}	
	
	Node* first_node_ptr;
	Node* last_node_ptr;

public:
	String_list() {	first_node_ptr = last_node_ptr = NULL; }
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
			last_node_ptr = first_node_ptr = NULL;
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
	typedef class iterator {
	public:
		iterator(Node* n): node(n) { }
		iterator& operator++ () {
			node = node->next;
			return *this;
		}
		iterator operator++ (int) {
			iterator result(node);
			++(*this);
			return result;
		}
		iterator& operator-- () {
			node = node->prev;
			return *this;
		}
		iterator operator-- (int) {
			iterator result(node);
			--(*this);
			return result;
		}
		string& operator* () {
			return node->data;
		}
		bool operator!= (const iterator& rhs) {
			return node != rhs.node;
		}
		operator bool() const {
			return node != NULL;
		}
	private:
		Node* node;

	} iterator;
	
const iterator begin() const {
	return first_node_ptr;
}
	
const iterator end() const {
	return last_node_ptr;
}
	
};

String_list split_10_6(const string& s)
{
	String_list ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()){
		while (i != s.size() && isspace(s[i]))
		++i;

		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
		++j;

		if (i != j){
			ret.push(s.substr(i, j - i));
			i = j;
		}

	}
	return ret;
}

int main()
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
	} catch (domain_error& e) {
		cout << e.what() << endl;
	}
	
	data.push("1");
	data.push("2");
	data.push("3");
	data.push("4");
	data.push("5");
	data.push("6");
	
	String_list::iterator it(data.begin());
	String_list::iterator begin = it;
	String_list::iterator end(data.end());
	
	for (; it != end; ++it) *it = "new_val";
	for (; it != begin; --it) *it = "new_val2";

	String_list data2 = split_10_6("split me please !");
			
	return 0;
}

