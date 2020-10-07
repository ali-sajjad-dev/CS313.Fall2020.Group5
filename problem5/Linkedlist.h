#pragma once
struct Node
{
	int data;
	struct Node* next;
};

class Linkedlist
{
public:
	Node* head;
	Node* tail;
	int length;

	// constructor
	Linkedlist();

	/* add to the head of the list
		O(1);
	*/
	void push(int data);

	// display data to console
	void display();
	
	// add to the end of the list
	void append(int data);

	// keep track of length
	int size();

	void insert(int index, int data);

	int search(int data);

	// remove front of list O(1)
	void pop();

	// remove from end of list O(n) for singly-linkedlist
	void deletion();

	// remove from specified index O(n) unless head node
	void remove(int index);

	//delete the list w/o leaking memory
	void deleteList();

	// reverse the linked list
	void reverse();

	// sort list using.....
	void sort();
};