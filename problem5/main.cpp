#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono> 
#include "Multilevelsort.h"
#include "insertionsort.h"

int main()
{
	int array3[100000];

	srand(time(nullptr));

	for (int i = 0; i < 100000; i++)
	{
		array3[i] = rand() % 100000 + 1;
	}

  // print array
	for (int i = 0; i < 100; i++)
	{
		cout << array3[i] << " ";
	}
	cout << endl;
	
	// sort 1
	auto t1 = chrono::high_resolution_clock::now();
	insertionSort(array3, 100000);
	auto t2 = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "sorting took " << duration1 << " microseconds" << endl;

	// sort 2
	auto t3 = chrono::high_resolution_clock::now();
	mergesort(array3, 0, 99999);
	auto t4 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::microseconds>(t4 - t3).count();
	cout << "sorting took " << duration2 << " microseconds" << endl;

	// custom sort 3
	auto t5 = chrono::high_resolution_clock::now();
	multiLevelSort(array3, 0, 99999);
	auto t6 = chrono::high_resolution_clock::now();
	auto duration3 = chrono::duration_cast<chrono::microseconds>(t6 - t5).count();
	cout << "sorting took " << duration3 << " microseconds" << endl;

	for (int i = 0; i < 100000; i++)
	{
		cout << array3[i] << " ";
	}
  
  return 0;
}
