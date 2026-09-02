#include "linkedlist.h"
#include <iostream>

List::List(){
	sen.next = &sen;
	sen.prev = &sen;
}

void List::insert(double k){ 
	Node *x = new Node;
	x->key = k;
	x->next = sen.next; 
	sen.next->prev = x; 
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
	sen.key = k; // to avoid adding x != &sen in while loop
	// cause like, that condition is true for all cases except at tail
	// then to verify whether the returned x is the sentinel or the element has been found, we can simply refer to x's address.
	while(x->key != k)
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
