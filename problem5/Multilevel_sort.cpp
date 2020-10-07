#include <iostream>
#include "Multilevelsort.h"
#include "insertionsort.h"

using namespace std;

// Build a multilevel sort, implemented recursively 
void multiLevelSort(int array[], int start, int end)
{
	//determine the size of array, adding indicies 
	int size = start + end + 1;

	// Determine either sort x or sort y compared to size n, n = 10 in our case.
	// compare the start index to the end index, i.e look to see whether not we have a single element
	if (start < end)
	{
		// calculate mid index value;
		int mid = start + (end - start) / 2;

		// recursively call mergesort on left hand side to divide and conquer
		multiLevelSort(array, start, mid);

		// recursively call mergsesort on right hand side to divide and conquer
		multiLevelSort(array, mid + 1, end);

		// merge the seperated array
		mergeHalves(array, start, mid, end);
	}
	return;
}


void mergeHalves(int array[], int start, int mid, int end)
{
	int i, j, k;  // iterators for left, right and merged array
	int size1 = mid - start + 1;
	int size2 = end - mid;

	//check sizes compared to n=10
	if (size1 <= 10)
	{
		sortY(array, size1);
	}
	else if (size2 <= 10)
	{
		sortY(array, size2);
	}

	// dynamically allocated temporary arrays
	int* left = new int[size1];
	int* right = new int[size2];

	// fill in the temporary arrays
	for (i = 0; i < size1; i++)
	{
		left[i] = array[start + i];
	}

	for (j = 0; j < size2; j++)
	{
		right[j] = array[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = start;

	// merge the two sub-arrays
	while (i < size1 && j < size2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	// check to see if any elements remain
	while (i < size1)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	// free temporary arrays
	delete[] left;
	delete[] right;
}


void sortY(int array[], int size)
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