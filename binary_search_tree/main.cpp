#include "bst.h"
#include <iostream>

using namespace std;

int main(){
	int amt_of_nodes;
	Tree T;
	cout << "Enter the amount of nodes in the tree: ";
	cin >> amt_of_nodes;

	cout << "Enter " << amt_of_nodes << " node(s): ";
	for(int i = 0; i < amt_of_nodes; i++){
		int x;
		cin >> x;
		T.tree_insert(x);
	}

	cout << "Inorder walk is: ";
	T.user_inorder_walk();

	cout << "Enter element to search: ";
	cin >> amt_of_nodes;
	T.print_for_search(amt_of_nodes);
}
