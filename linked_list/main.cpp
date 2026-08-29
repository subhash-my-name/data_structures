#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(){
	List list;
	double inp;
	cout << "Enter key (or 0 to stop taking inputs): ";

	while(cin >> inp && inp != 0){
		list.insert(inp);
		cout << "inserted: " << inp << '\n';
	}

	int ch;
	cout << "1. Delete" << '\n' << "2. Search" << '\n' << "3. Quit" << '\n';
	while(true){
		cin >> ch;
		switch(ch){
			case 1:{
				double d;
				cout << "Enter key to delete: ";
				cin >> d;
				list.remove(d);
				break;
			}
			
			case 2:{
				double d;
				cout << "Enter element to search: ";
				cin >> d;
				list.search_user(d);
				break;
			}

			case 3:
			return 0;
			
			default:
			cout << "Weird input" << '\n';
			break;
		}
	}
}
