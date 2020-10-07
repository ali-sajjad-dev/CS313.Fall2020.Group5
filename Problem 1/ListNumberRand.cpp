#include<iostream>
#include<time.h>
#include<chrono>
using namespace std;
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

class node 
{
    public:
    int value;
    node* next;
};

node* randomList();
void printList(node* val);

int main()
{
    auto begin = steady_clock::now();

    node* test = randomList();
    printList(test);

    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - begin);
    cout << duration.count() << " milliseconds";
}

node* randomList()
{
    node *first, *last, *newNode;
    first  = last = nullptr;

    srand(time(NULL));
    for(int i = 0; i < 1000; i++)
    {
    newNode = new node;
    newNode->value = rand() % 1000;
    newNode->next = nullptr;

    if(first == nullptr)
        {
        first = last = newNode;
     }
    else 
     {
        last->next = newNode;
        last = newNode;
        }
    }
    return first;
    
}

void printList(node* val)
{
    
    node* current = val;
     while (current != nullptr)
     {
         cout << current->value <<" -> " <<  " ";
         current = current->next;
     }
     cout << endl << endl;
     
}