#include "bst.h"
#include <iostream>

Tree::node::node(int k) : left(nullptr), right(nullptr), parent(nullptr), key(k) {}

Tree::Tree() : root(nullptr) {}

void Tree::tree_insert(int key){
	node *y = nullptr;
	node *x = root; 
	node *toBeInserted = new node(key);

	while(x != nullptr){
		y = x;
		if(toBeInserted->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	toBeInserted->parent = y;
	if(y == nullptr)
		root = toBeInserted;
	else if(toBeInserted->key < y->key)
		y->left = toBeInserted;
	else
		y->right = toBeInserted;
}

void Tree::inorder_walk(node *x){
	if(x != nullptr){
		inorder_walk(x->left);
		std::cout << x->key << " ";
		inorder_walk(x->right);
	}
}

Tree::node* Tree::tree_search(int key){
	node* x = root;
	while(x != nullptr && x->key != key){
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

void Tree::print_for_search(int key){
	node* y = tree_search(key);
	if(y != nullptr)
		std::cout << "found!" << '\n';
	else
		std::cout << "not found." << '\n';
	std::cout << '\n';
}

void Tree::user_inorder_walk(){
	inorder_walk(root);
	std::cout << '\n';
}
