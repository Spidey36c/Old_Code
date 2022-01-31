/*************************************************************
* Author: James Nordquist
* Filename: stub.cpp
* Date Created: 1/26/19
* Modifications: 1/27/19 – Added selection sort
*				 1/28/19 – Added Insertion Sort
*				 1/29/19 - Added Shell and Heap sort
*				 1/30/19 - Added Merge Sort and Quick Sort
*				 1/31/19 - Fixed Quick Sort
*			     2/1/19 - Added Function Headers
**************************************************************/
/*************************************************************
* Lab/Assignment: Lab 2 - Sorts
*
* Overview:
* This program will take the first command line argument
* besides the location of the program, and use it for the number
* of records to sort
*
* Input:
* an Integer Command line argument which will become n, or
* number of records to sort
*
* Output:
* The output of this program will be the name of array sorted, 
* type of sort used, and time it took to sort using that type
* of sort to the console and a file, but also the file will get
* every 1000th element of the array sorted to check if it is sorted.
*
************************************************************/
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <crtdbg.h>
#include "Array.h"
using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::time;
using std::vector;
using std::ofstream;
using std::ios;

/**********************************************************************
* Purpose: Printing the name and time of a sort
*
* Precondition:
* time: the amount of time it took for a sort to finish, goes down to 10^-3 seconds
*		as its smallest decimal number
* sname: the name of the sort
* aname: the name of the array being sorted
*
* Postcondition:
* outputs the sort name array name and time it took to sort to console
* and SortOutput.txt
*
************************************************************************/
void PrintTime(double time, const char * sname, const char * aname);

/**********************************************************************
* Purpose: Printing an element in an array to a file
*
* Precondition:
* element: data to be outputted into file
* filename: name of file to output to
*
* Postcondition:
* specific element is placed at the end of the file
*
************************************************************************/
template<typename T>
void PrintElement(T element, const char *filename);

/**********************************************************************
* Purpose: Setting one arrays data to another
*
* Precondition:
* toreset: array that has been sorted
* original: array that holds the data in the order toreset held before
*			being sorted
* numelements: number of elements in the arrays
*
* Postcondition:
* toreset is unsorted and back to original order
*
************************************************************************/
template<typename T>
void Reset(T &toreset, T &original, int numelements);

/**********************************************************************
* Purpose: Bubblesort Brute forced so it always does extra passes even if
*		   no change is made
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the bubble sorting method
*
************************************************************************/
template<typename T>
void BruteForceBubble(T &tosort, int numelements);

/**********************************************************************
* Purpose: Bubblesort flagged so it doesn't do an extra pass if no change
*		   is made
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the bubble sorting method
*
************************************************************************/
template<typename T>
void FlaggedBubble(T &tosort, int numelements);

/**********************************************************************
* Purpose: Selection Sort find the index of the largest element and place
*		   it at the end of the unsorted part of the array
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the selection sort method
*
************************************************************************/
template<typename T>
void SelectionSort(T &tosort, int numelements);

/**********************************************************************
* Purpose: Insertion Sort assume the left side of the array is a new array
*		   and the first element is already sorted. Check the element to the
*		   right of the end of the "new" array and find the elements place in
*		   the new array.
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
* startingpos: the starting position of the array to sort. Useful for
*			   using in tandem with shell sort. 0 should be used outside
*			   of shell sort
* gap: gap between subarrays in shell sort. 1 when used outside of shell sort 
*
* Postcondition:
* tosort is sorted in ascending order using the insertion sort method
*
************************************************************************/
template<typename T>
void InsertionSort(T &tosort, int numelements, int startingpos, int gap);

/**********************************************************************
* Purpose: Shell Sort break the array into subarrays using a gap, and sort
*		   the subarrays using insertion sort
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the Shell sort method
*
************************************************************************/
template<typename T>
void ShellSort(T &tosort, int numelements);

/**********************************************************************
* Purpose: Used to heapify arrays for use in a heap sort.
*
* Precondition:
* data: array to heapify
* first: the last node with children
* last: the index of the last element
*
* Postcondition:
* data is made into a heap
*
************************************************************************/
template<typename T>
void MoveDown(T &data, int first, int last);

/**********************************************************************
* Purpose: Heap Sort turn an array into a heap and swap the first element and last
*		   non swapped element then redo the heap subtracting the amount of 
*		   swapped elements
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the Heap sort method
*
************************************************************************/
template<typename T>
void HeapSort(T &tosort, int numelements);

/**********************************************************************
* Purpose: Merge Sort a temporary array is made and The actual mergesort is
*		   called using the temp array
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the Merge sort method
*
************************************************************************/
template<typename T>
void MergeSort(T &tosort, int numelements);

/**********************************************************************
* Purpose: Merge Sort, "Splits" the array recusively into two halves until only a 
*		   one element array is made on the left half and then the right half
*		   and then pops up merging the two halves of the array
*
* Precondition:
* tosort: array to be sorted
* temp: temporary array to be used in sorting array
* left_index: the left most index of the current array
* right_index: the right most index of the current array
*
* Postcondition:
* halves of tosort are made and sorted then merged together until tosort is sorted
*
************************************************************************/
template<typename T>
void MergeSort2(T &tosort, int *temp, int left_index, int right_index);

/**********************************************************************
* Purpose: Merges two halves of the tosort array and sorts them and places them
*		   inside a temp which then writes over the original tosort array with the
*		   now sorted halves
*
* Precondition:
* tosort: array to be sorted
* temp: temporary array to be used in sorting array
* left_index: the first element int the left array
* right_index: the first element in the right array
* rightend: the last element in the right array
*
* Postcondition:
* two halves of an array are sorted and placed back into the tosort array
*
************************************************************************/
template<typename T>
void Merge(T &tosort, int *temp, int left_index, int right_index, int rightend);

/**********************************************************************
* Purpose: Quick sort, the largest element is placed at the end of the array
*		   and the first pivot is the first element in the array
*
* Precondition:
* tosort: array to be sorted
* numelements: number of elements in array
*
* Postcondition:
* tosort is sorted in ascending order using the Quick sort method
*
************************************************************************/
template<typename T>
void QuickSort(T &tosort, int numelements);

/**********************************************************************
* Purpose: Quick sort, compares elements agains a pivot element to
*		   sort the array into two halves where one is greater than the
*		   pivot and one that is less than the pivot and swaps the old
*		   pivot with the element in between the two halves and then
*		   calls itself on these new halves
*
* Precondition:
* tosort: array to be sorted
* first: the first element in the current array
* last: the last element in the current array
*
* Postcondition:
* tosort is sorted in ascending order using the Quick sort method
*
************************************************************************/
template<typename T>
void QuickSort2(T &tosort, int first, int last);


int main(int argc, char ** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (argc > 1)
	{
		int numElements = atoi(argv[1]);

		long double duration;
		clock_t start;

		srand(time(0));

		ofstream fout;
		fout.open("SortOutput.txt");
		if (fout.is_open())
		{
			fout << "Sorting algorithims timing and every 1000th element" << endl << endl;
			fout.close();
		}

		int *array2 = new int[numElements];
		int *array = new int[numElements];

		for (int i = 0; i < numElements; i++)
		{
			array[i] = rand() % numElements;
		}

		Reset(array2, array, numElements); //Array is changed because of passing by pointer so the array must be reset

		start = clock();
		BruteForceBubble(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Bubble", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		FlaggedBubble(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Bubble Flagged", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		SelectionSort(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Selection", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		InsertionSort(array2, numElements, 0, 1);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Insertion", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		ShellSort(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Shell", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		HeapSort(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Heap", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		MergeSort(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Merge", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		start = clock();
		QuickSort(array2, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Quick", "Carray");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(array2[i], "SortOutput.txt");
		}

		Reset(array2, array, numElements);

		Array<int> carray(numElements);
		Array<int> carray2(numElements);
		for (int i = 0; i < numElements; i++)
		{
			carray[i] = rand() % numElements;
		}

		carray2 = carray;

		start = clock();
		BruteForceBubble(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Bubble", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements); //using reset function as op = was giving me issues with flagged bubble sort and only flagged bubble sort

		start = clock();
		FlaggedBubble(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Bubble flagged", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		start = clock();
		SelectionSort(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Selection", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		start = clock();
		InsertionSort(carray, numElements, 0, 1);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Insertion", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		start = clock();
		ShellSort(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Shell", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		start = clock();
		HeapSort(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Heap", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		start = clock();
		MergeSort(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Merge", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		start = clock();
		QuickSort(carray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Quick", "Array class");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(carray[i], "SortOutput.txt");
		}

		Reset(carray, carray2, numElements);

		vector<int> varray(numElements);
		vector<int> varray2(numElements);
		for (int i = 0; i < numElements; i++)
		{
			varray[i] = rand() % numElements;
		}

		varray2 = varray;

		start = clock();
		BruteForceBubble(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Bubble", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements); //using reset function as op = was acting up for flagged bubble sort and only flagged bubble sort

		start = clock();
		FlaggedBubble(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Bubble Flagged", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements);

		start = clock();
		SelectionSort(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Selection", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}
		Reset(varray, varray2, numElements);

		start = clock();
		InsertionSort(varray, numElements, 0, 1);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Insertion", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements);

		start = clock();
		ShellSort(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Shell", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements);

		start = clock();
		HeapSort(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Heap", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements);

		start = clock();
		MergeSort(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Merge", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements);

		start = clock();
		QuickSort(varray, numElements);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		PrintTime(duration, "Quick", "Vector");
		for (int i = 0; i < numElements; i += 1000)
		{
			PrintElement(varray[i], "SortOutput.txt");
		}

		Reset(varray, varray2, numElements);

		delete array;
		delete array2;
	}
	else
	{
		cout << "The program needs to have an integer command line argument" << endl;
	}
	return 0;
}

template<typename T>
void BruteForceBubble(T &tosort, int numelements)
{
	int temp;
	for (int i = 0; i < numelements; i++)
	{
		for (int j = 0; j < numelements - 1; j++)
		{
			if (tosort[j] > tosort[j + 1])
			{
				temp = tosort[j];
				tosort[j] = tosort[j + 1];
				tosort[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void FlaggedBubble(T &tosort, int numelements)
{
	bool notSorted = true;
	int temp;
	for (int i = 0; i < numelements && notSorted; i++)
	{
		notSorted = false;
		for (int j = 0; j < numelements - 1; j++)
		{
			if (tosort[j] > tosort[j + 1])
			{
				notSorted = true;
				temp = tosort[j];
				tosort[j] = tosort[j + 1];
				tosort[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void SelectionSort(T &tosort, int numelements)
{
	int temp;
	int index;
	for (int i = numelements - 1; i >= 0; i--)
	{
		index = i; //set an index to i so that if no changes are needed none are made
		for (int j = 0; j < i; j++)
		{
			if (tosort[j] > tosort[index]) //find the largest element in the array
			{
				index = j;
			}
		}
		if (index != i) //if i is already sorted in the array dont change anything
		{
			temp = tosort[index];
			tosort[index] = tosort[i];
			tosort[i] = temp;
		}
	}
}

template<typename T>
void InsertionSort(T &tosort, int numelements, int startingpos, int gap)
{
	int index;
	int temp;
	for (int i = startingpos + gap; i < numelements; i += gap)
	{
		temp = tosort[i];
		index = i;
		for (int j = i - gap; j >= startingpos && temp < tosort[j]; j -= gap)
		{
			tosort[j + gap] = tosort[j];
			index -= gap;
		}
		tosort[index] = temp;
	}
}

template<typename T>
void ShellSort(T &tosort, int numelements)
{
	int h = 1;
	int startPos = 0;
	vector<int> gap;

	while (h < numelements)
	{
		gap.push_back(h);
		h = 3 * h + 1;
	}
	gap.pop_back();

	for (int i = gap.size() - 1; i >= 0; i--)
	{
		h = gap[i];
		for (int j = 0; j < h; j++)
		{
			InsertionSort(tosort, numelements, j, h);
		}
	}
}

template<typename T>
void MoveDown(T &data, int first, int last)
{
	int temp;
	int largest = first * 2 + 1;
	while (largest <= last)
	{
		if (largest < last && data[largest] < data[largest + 1])
		{
			largest++;
		}

		if (data[first] < data[largest])
		{
			temp = data[first];
			data[first] = data[largest];
			data[largest] = temp;
			first = largest;
			largest = first * 2 + 1;
		}
		else
		{
			largest = last + 1;
		}
	}
}

template<typename T>
void HeapSort(T &tosort, int numelements)
{
	int temp;
	for (int i = (numelements - 1) / 2; i >= 0; i--)
	{
		MoveDown(tosort, i, numelements - 1);
	}
	for (int i = numelements - 1; i > 0; i--)
	{
		temp = tosort[0];
		tosort[0] = tosort[i];
		tosort[i] = temp;
		MoveDown(tosort, 0, i - 1);
	}
}

template<typename T>
void MergeSort(T &tosort, int numelements)
{
	int *temp = new int[numelements];

	MergeSort2(tosort, temp, 0, numelements - 1);

	delete temp;
}

template<typename T>
void MergeSort2(T &tosort, int *temp, int left_index, int right_index)
{
	int mid;
	if (left_index < right_index)
	{
		mid = (left_index + right_index) / 2;

		MergeSort2(tosort, temp, left_index, mid);
		MergeSort2(tosort, temp, mid + 1, right_index);
		Merge(tosort, temp, left_index, mid + 1, right_index);
	}
}

template<typename T>
void Merge(T &tosort, int *temp, int left_index, int right_index, int rightend)
{
	int leftend = right_index - 1;
	int startpos = left_index; //for putting the temp array into the tosort array
	int temppos = left_index;

	while (left_index <= leftend && right_index <= rightend)
	{
		if (tosort[left_index] <= tosort[right_index])
		{
			temp[temppos] = tosort[left_index];
			temppos++;
			left_index++;
		}
		else
		{
			temp[temppos] = tosort[right_index];
			temppos++;
			right_index++;
		}
	}

	while (left_index <= leftend)
	{
		temp[temppos] = tosort[left_index];
		temppos++;
		left_index++;
	}
	while (right_index <= rightend)
	{
		temp[temppos] = tosort[right_index];
		temppos++;
		right_index++;
	}

	for (int i = startpos; i <= rightend; i++)
	{
		tosort[i] = temp[i];
	}
}

template<typename T>
void QuickSort(T &tosort, int numelements)
{
	int max = 0;
	int temp;
	if (numelements >= 2)
	{
		for (int i = 0; i < numelements; i++)
		{
			if (tosort[max] < tosort[i])
			{
				max = i;
			}
		}
		temp = tosort[numelements - 1];
		tosort[numelements - 1] = tosort[max];
		tosort[max] = temp;
		QuickSort2(tosort, 0, numelements - 2);
	}
}

template<typename T>
void QuickSort2(T &tosort, int first, int last)
{
	int temp;
	int small = first + 1;
	int large = last;
	int pivot = tosort[first];
	while (small <= large)
	{
		while (tosort[small] < pivot)
		{
			small++;
		}
		while (tosort[large] > pivot)
		{
			large--;
		}
		if (small < large)
		{
			temp = tosort[small];
			tosort[small] = tosort[large];
			tosort[large] = temp;
			small++;
			large--;
		}
		else
		{
			small++;
		}
	}
	temp = tosort[first];
	tosort[first] = tosort[large];
	tosort[large] = temp;
	if (first < large - 1)
	{
		QuickSort2(tosort, first, large - 1); //large should always be the pivot of the right array
	}
	if (last > large + 1)
	{
		QuickSort2(tosort, large + 1, last);
	}
}

template<typename T>
void PrintElement(T element, const char *filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	if (fout.is_open())
	{
		fout << element << endl;
		fout.close();
	}
}

void PrintTime(double time, const char * sname, const char * aname)
{
	ofstream fout;
	fout.open("SortOutput.txt", ios::app);
	cout << sname << " Sort for " << aname << ": ";
	cout << time << endl;
	if (fout.is_open())
	{
		fout << endl << sname << " Sort for " << aname << ": ";
		fout << time << endl << endl;
		fout.close();
	}
}

template<typename T>
void Reset(T &toreset, T &original, int numelements)
{
	for (int i = 0; i < numelements; i++)
	{
		toreset[i] = original[i];
	}
}