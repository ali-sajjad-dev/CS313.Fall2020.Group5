/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include<ctime>
#include<bits/stdc++.h>

using namespace std;

int rand_0toN1(int n);
int hits[10];

int main()
{
     float a; 
    clock_t time_req; 
	int n=0;		//Number of trials
	int r=0;		//Holds a random value 

	srand(time(nullptr));		//set seed for randomizing

	cout<<"Enter how many trials and press enter: ";
cin>>n;

//Run n trials. For each trial, get  a num 0 to 9
//and then increment the corresponding element 
//in the hits array

for(int i=0; i<n; ++i){
	r=rand_0toN1(10);
	++hits[r];
}

//Print all elements in the hits array, along
//with ratio of hits to expected hits (n/10)   

	for(int i=0; i<10; i++){
	cout<< i << ": " << hits[i];
	double results = hits[i];
	cout << results / (n/10.0) <<endl;
}
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

//Random 0-to-N1 function.
//Generate a random integer from 0 to N1

int rand_0toN1(int n){
	return rand() % n;
}

