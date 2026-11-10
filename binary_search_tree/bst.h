#pragma once

class Tree{
	struct node{
		node* left;
		node* right;
		node* parent;
		int key;

		node(int k = 0);
	};
	node* root;
	void inorder_walk(node*);
	node* tree_search(int);

public:
	Tree();
	void tree_insert(int);
	void user_inorder_walk();
	void print_for_search(int);
};
