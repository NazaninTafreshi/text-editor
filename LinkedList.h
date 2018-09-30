/*
 * Link.h
 *
 *  Created on: Dec 10, 2015
 *      Author: Nazanin
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template<class type>
class List {
public:
	
	List();
	
	Node<type>* insert(Node<type>* prev, type data);
	
	void deleteNode(Node<type>* p);
	
	Node<type>* search(type key);
	
	template<class T>
	friend ostream& operator<<(ostream& output, List<T>& n);
	
	string& toString();
	
	Node<type>* first;
	
	Node<type>* last;

};
template<class type>
List<type>::List() {
	first = NULL;
	last = NULL;
}
template<class type>
Node<type>* List<type>::insert(Node<type>*prev,type data) {
	Node<type>*p = new Node<type>;
	p->data = data;

	if (first == NULL || last == NULL) {
		first = p;
		last = p;
		p->prev = NULL;
		p->next = NULL;
	} else if (prev == NULL && first != NULL) {
		p->next = first;
		p->prev = NULL;
		first->prev = p;
		first = p;
	} else {
		if (prev == last) {
			p->prev = prev;
			p->next = NULL;
			last->next = p;
			last = p;
		} else {
			p->prev = prev;
			p->next = prev->next;
			prev->next->prev = p;
			prev->next = p;
		}
	}

	return p;
}
template<class type>
void List<type>::deleteNode(Node<type>* p) {
	if (first == NULL || p == NULL || last == NULL)
		return;
	if (p == first) {
		first->next->prev = NULL;
		first = first->next;
	} else if (p == last) {
		last->prev->next = NULL;
		last = last->prev;
	} else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	delete p;

}
template<class type>
Node<type>* List<type>::search(type key) {
	Node<type>* cur = first;
	if (cur == NULL) {
		return NULL;
	}
	do {
		if (cur->data == key) {
			return cur;
		}
		cur = cur->next;
	} while (cur != NULL);
	return NULL;

}
template<class T>
ostream &operator<<(ostream &output, List<T> &n) {
	Node<T>*cur = n.first;

	if (cur == NULL) {
		output << "";
		return output;
	}
	do {
		output << cur->data << " ";
		cur = cur->next;
	} while (cur != NULL);
	output << endl;
	return output;
}
template<class type>
string& List<type>::toString() {
	string* a = new string();
	Node<type>*cur = first;
	if (cur == NULL)
		return *a;
	do {
		*a += cur->data;
		cur = cur->next;
	} while (cur != NULL);
	return *a;
}

#endif /* LIST_H_ */
