#pragma once

class List{
	struct Node{
		double key;
		Node *next;
		Node *prev;
	};

	Node* search(double k);
	void del(Node* k);

	Node sen;

public:
	List();
	void search_user(double k);
	void insert(double k);
	void remove(double k);
};

