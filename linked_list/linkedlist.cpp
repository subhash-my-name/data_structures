#include "linkedlist.h"
#include <iostream>

List::List(){
	sen.next = &sen;
	sen.prev = &sen;
}

void List::insert(double k){ // passing the pointer of the node to be inserted cause better memory management and allat
	Node *x = new Node;
	x->key = k;
	x->next = sen.next; // since x is pointer, x->next is the same as (*x).next, and since next is also a pointer, there is no type error
	sen.next->prev = x; // sen.next is a pointer, so sen.next->prev is the same as (*sen.next).prev. since both prev and x store addresses, no type errors exist.
	sen.next = x;
	x->prev = &sen;
}

void List::remove(double k){
	Node* target = search(k);
	if(target != &sen)
		del(target);
	else
		std::cout << "Key not found" << '\n';
}

List::Node* List::search(double k){
	Node *x = sen.next;
	while(x != &sen && x->key != k)
		x = x->next;
	return x;
}

void List::search_user(double k){
	Node *x = search(k);
	if(x == &sen){
		std::cout << "Not found" << '\n';
		return;
	}
	std::cout << "Found." << '\n';
	return;
}

void List::del(Node *x){
	(x->prev)->next = x->next;
	(x->next)->prev = x->prev;
	delete x;
}
