//
//
// Task 11.8. Write a simplified version of the standard 'list' class and its associated iterator.

// Copy-pasted-modified code from Task 10.4.

#include "stdafx.h"
#include <stdexcept>
#include <iostream>

template <typename T> class list
{
private:
	typedef class Node {
	public:
		Node* next;
		Node* prev;
		T data;
		Node() { }
		Node(const Node* n) {
			next = n->next;
			prev = n->prev;
			data = n->data;
		}
		Node(const T& val, Node* prevn = NULL) {
			next = NULL;
			prev = prevn;
			data = val;
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
	list() { first_node_ptr = last_node_ptr = NULL; }
	list(const T& val) {
		first_node_ptr = new Node(val);
		last_node_ptr = first_node_ptr;
	}
	void push_back(const T& val) {
		if (!first_node_ptr) { 
			first_node_ptr = new Node(val);
			last_node_ptr = first_node_ptr;
		}
		else {
			last_node_ptr->next = new Node(val, last_node_ptr);
			last_node_ptr = last_node_ptr->next;
		}
	}
	T pop_back() {
		if (!last_node_ptr) throw domain_error("Nothing to pop!");
		if (last_node_ptr == first_node_ptr) {
			string ret(last_node_ptr->data);
			delete last_node_ptr;
			last_node_ptr = first_node_ptr = NULL;
			return ret;
		}
		T ret(last_node_ptr->data);
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
		T& operator* () {
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


int _tmain(int argc, _TCHAR* argv[])
{
	list<int> intlist;
	list<std::string> strlist("aaa");
	
	intlist.push_back(10);
	list<int>::iterator it = intlist.begin();
	std::cout << *it << std::endl;

	list<std::string>::iterator it2 = strlist.begin();
	strlist.push_back("bbb");

	std::cout << (*it2).c_str() << std::endl;
	std::cout << (*(++it2)).c_str() << std::endl;
	return 0;
}


