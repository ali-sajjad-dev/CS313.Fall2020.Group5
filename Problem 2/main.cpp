#include <iostream>
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;
using namespace std;

// Iterative binary search
bool iterativeBinarySearch(int* array, int left, int right, int x) {
	// while the last position does not equal to the first position
	while (right != left) {
		// set mid
		int mid = (right + left) / 2;
		// check if the x is in the middle of the array
		if (array[mid] == x) {
			return true;
		}
		// set the bound of the array
		else if (x > array[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

//Recursive binary search
bool recursiveBinarySearch(int* array, int left, int right, int x) {
	//set mid
	int mid = (right + left) / 2;

	// check if the x is in the middle of the array
	if (array[mid] == x) {
		return true;
	}
	// if the last position does not equal to the first position
	if (right != left) {
		return false;
	}

	// if x is less than the middle value, do a binary search on first half, else do a binary search on the second half
	if (x < array[mid]) {
		return recursiveBinarySearch(array, mid + 1, right, x);
	}
	if (x > array[mid]) {
		return recursiveBinarySearch(array, left, mid - 1, x);
	}
}

//Linked-type binary search
bool linkedTypeBinarySearch(int* array, int left, int right, int x) {
	// while the first element is not next to the last element in memory 
	while (&array[left] != &array[right] + 1) {
		// set mid
		int mid = (right + left) / 2;
		// check if the x is in middle of the array, or at the first or last value
		if (array[mid] == x || array[left] || array[right]) {
			return true;
		}
		// set the bound of the array
		else if (x > array[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

//Timing template
template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<nanoseconds>(end - begin).count();
}

int main() {
	const int size1 = 1000000;
	const int size2 = 10000000;
	const int size3 = 100000000;

	// The arrays are stored on the heap to prevent stack overflow
	// array1 has a size of 1 million, array2 with 10 million, and array3 with 100 million
	int* array1 = new int[size1];
	int* array2 = new int[size2];
	int* array3 = new int[size3];

	int n = 0;

	// fills array1 with 1 million random int
	for (int i = 0; i < size1; i++) {
		array1[i] = n;
		n = n + rand() % 9 + 0;
	}

	n = 0;

	// fills array2 with with 10 million random int
	for (int i = 0; i < size2; i++) {
		array2[i] = n;
		n = n + rand() % 9 + 0;

	}

	n = 0;

	// fills array3 with 100 million random int
	for (int i = 0; i < size3; i++) {
		array3[i] = n;
		n = n + rand() % 9 + 0;
	}

	// Each array is tested with the 3 types of binary searches and their timing is recorded is nanoseconds
	auto t1 = TimeFunc([&]() {iterativeBinarySearch(array1, 0, size1, 10); });
	auto t2 = TimeFunc([&]() {recursiveBinarySearch(array1, 0, size1, 10); });
	auto t3 = TimeFunc([&]() {linkedTypeBinarySearch(array1, 0, size1, 10); });

	auto t4 = TimeFunc([&]() {iterativeBinarySearch(array2, 0, size2, 10); });
	auto t5 = TimeFunc([&]() {recursiveBinarySearch(array2, 0, size2, 10); });
	auto t6 = TimeFunc([&]() {linkedTypeBinarySearch(array2, 0, size2, 10); });

	auto t7 = TimeFunc([&]() {iterativeBinarySearch(array3, 0, size3, 10); });
	auto t8 = TimeFunc([&]() {recursiveBinarySearch(array3, 0, size3, 10); });
	auto t9 = TimeFunc([&]() {linkedTypeBinarySearch(array3, 0, size3, 10); });

	//The results are printed
	cout << "For array of size 1 million:" << endl;
	cout << "The iterative binary search takes " << t1 << " nanoseconds to execute" << endl;
	cout << "The recursive binary search takes " << t2 << " nanoseconds to execute" << endl;
	cout << "The linked-type binary search takes " << t3 << " nanoseconds to execute" << endl;
	cout << endl;

	cout << "For array of size 10 million:" << endl;
	cout << "The iterative binary search takes " << t4 << " nanoseconds to execute" << endl;
	cout << "The recursive binary search takes " << t5 << " nanoseconds to execute" << endl;
	cout << "The linked-type binary search takes " << t6 << " nanoseconds to execute" << endl;
	cout << endl;

	cout << "For array of size 100 million:" << endl;
	cout << "The iterative binary search takes " << t7 << " nanoseconds to execute" << endl;
	cout << "The iterative binary search takes " << t8 << " nanoseconds to execute" << endl;
	cout << "The linked-type binary search takes " << t9 << " nanoseconds to execute" << endl;
	cout << endl;

	/*Based on the results, recursive binary search is the fastest. The secound fastest is
	the linked-type binary search. The slowest one is the iterative binary search.*/

	delete[] array1;
	delete[] array2;
	delete[] array3;
}



