#include <iostream>
using namespace std;

class node {
public:
	int info;
	node* link;
};

// print the list
void printList(node* nodei) {
	node* current = new node;
	current = nodei;
	while (current != nullptr) {
		cout << current->info << endl;
		current = current->link;
	}
}

//The sorting function
void sortList(node* nodei) {
	node* current = new node;
	node* c = new node;
	c = nodei;
	current = nodei;

	int size = 0;

	//sets the size of the list
	while (c != nullptr) {
		size++;
		c = c->link;
	}

	if (size == 1) return;

	//The sorting is done by overriding the values based on the size of the list

	//sorting for an odd number of nodes
	if ((size % 2) != 0) {
		//overrides the first half + 1 of the values to odd numbers
		for (int i = 0; i < (size / 2) + 1; i++) {
			nodei = current;
			current->link->info = current->info + 2;
			current = current->link;
		}
		//overrides the rest of the values to even numbers
		current->info = 2;
		while (current->link != nullptr) {
			nodei = current;
			current->link->info = current->info + 2;
			current = current->link;
		}
	}

	//sorting for an even number of nodes
	else {
		//overrides the first half of the values to odd numbers
		for (int i = 0; i < (size / 2); i++) {
			current->link->info = current->info + 2;
			current = current->link;
		}
		//overrides the rest of the values to even numbers
		current->info = 2;
		while (current->link != nullptr) {
			current->link->info = current->info + 2;
			current = current->link;
		}
	}
}

int main() {

	// Tests the sorting function with an odd size of nodes
	node* node1 = new node;
	node* node2 = new node;
	node* node3 = new node;
	node* node4 = new node;
	node* node5 = new node;
	node* node6 = new node;
	node* node7 = new node;

	node1->info = 1;
	node2->info = 2;
	node3->info = 3;
	node4->info = 4;
	node5->info = 5;
	node6->info = 6;
	node7->info = 7;

	node1->link = node2;
	node2->link = node3;
	node3->link = node4;
	node4->link = node5;
	node5->link = node6;
	node6->link = node7;
	node7->link = nullptr;

	sortList(node1);
	printList(node1);

	// Tests the sorting function with an even size of nodes
	node* n1 = new node;
	node* n2 = new node;
	node* n3 = new node;
	node* n4 = new node;

	n1->info = 1;
	n2->info = 2;
	n3->info = 3;
	n4->info = 4;

	n1->link = n2;
	n2->link = n3;
	n3->link = n4;
	n4->link = nullptr;

	cout << endl;
	sortList(n1);
	printList(n1);

}




