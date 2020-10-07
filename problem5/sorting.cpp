#include <iostream>
#include "insertionsort.h"

using namespace std;

void insertionSort(int array[], int size)
{
	// iterate and evaluate every entry after array[0]
	for (int i = 1; i < size; i++)
	{
		// compare the current value to predecessor 
		int j = i;
		// because we always compare to predecessor the furthest ahead we need to go is index 1
		while (j >= 1)
		{	
			// is current value smaller than predecessor
			if (array[j] < array[j - 1])
			{
				// swap values
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
			else
			{
				// compare current to all predecessors
				j--;
			}
		}	
	}
}