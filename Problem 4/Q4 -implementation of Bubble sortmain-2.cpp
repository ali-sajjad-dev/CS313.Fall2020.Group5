/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

void print_list(Node *head)		//constructor
{
	Node *start = head;

	while(start)
	{
		cout<<start->data<<" -> ";
		start = start->next;
	}
	cout<<"\n\n";
}

void my_swap (Node *node_1, Node *node_2)
{
	int temp = node_1->data;
	node_1->data = node_2 -> data;
	node_2 -> data = temp;
}

void bubble_sort(Node *head){
	int swapped;

	Node *lPtr; 			// left pointer will always point to the start of the list
	Node *rPrt = NULL; 		// right pointer will always point to the end of the list
	do
	{	
		swapped = 0;
		lPtr = head;
		while(lPtr->next != rPrt)
		{
			if (lPtr->data > lPtr->next->data) 
			{
				my_swap(lPtr, lPtr->next); 
                swapped = 1; 
			}
			lPtr = lPtr->next;
		}

//as the largest element is at the end of the list, assign that to rPtr as there is no need to
//check already sorted list

		rPrt = lPtr;
	}while(swapped);
}

int main()
{
    float a; 
    clock_t time_req; 
	Node *head = new Node(2);
	head -> next = new Node(1);
	head -> next -> next = new Node(4);
	head -> next -> next -> next = new Node(3);
	head -> next -> next -> next  -> next = new Node(6);
	head -> next -> next -> next  -> next -> next = new Node(5);

	cout<<"The original list = "<<endl;
	print_list(head);

	bubble_sort(head);

	cout<<"The Sorted list = "<<endl;
	print_list(head);
 
  time_req = clock(); 
    for(int i=0; i<200000; i++) 
    { 
        a = log(i*i*i*i); 
    } 
    time_req = clock()- time_req; 
    cout << "Processor time taken: "
        << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl; 
  
        
	return 0;
}
