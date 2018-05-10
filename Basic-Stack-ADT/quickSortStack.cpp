/*************************************************************************
* this program illustrates the use of a stack to implement a nonrecursive
* quicksort function which is more efficient
*************************************************************************/
#include <stack>
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::stack;

// Function prototypes
void qSort(int a[], int size);
void outputArray(const int a[], int size);
int partition(int a[], int, int);

// Range is used to indicate a segment of an array that is still to be sorted
class Range
{
	// Make qSort a friend
	friend void qSort(int a[], int);
	int start;
	int end;
public:
	Range(int s, int e)
	{
		start = s;
		end = e;
	}
};

/*************************************************************************
* qSort performs a nonrecursive quicksort on the array a[] of the given size
*************************************************************************/
void qSort(int arr[], int size)
{
	// qStack holds segments of the array that have not yet been sorted
	stack<Range> qStack;
	int pivot, start, end;

	qStack.push(Range(0, size - 1));

	// As long as there is a range waiting to be sorted, take it off the
	// stack, partition it, and then put the resulting two smaller ranges
	// onto the stack
	while (!qStack.empty())
	{
		Range currentRange = qStack.top();
		qStack.pop();

		// Get the endpoints of the current Range and partition it
		start = currentRange.start;
		end = currentRange.end;
		if (start < end)
		{
			pivot = partition(arr, start, end);

			// Store the resulting smaller ranges for later processing
			qStack.push(Range(start, pivot - 1));
			qStack.push(Range(pivot + 1, end));
		}
	}
}

/*************************************************************************
* partition rearranges the entries in the array arr from start to end so
* all values greater than or equal to pivot are on the right of the pivot
* and all values less than are on the left of the pivot
*************************************************************************/
int partition(int arr[], int start, int end)
{
	// The pviot element is taken to be the element at the start of the
	// subrange to be partitioned
	int pivotValue = arr[start];
	int pivotPosition = start;

	// Rearrange the rest of the array elements to partition the subrange
	// from start to end
	for (int pos = start + 1; pos <= end; pos++)
	{
		if (arr[pos] < pivotValue)
		{
			// arr[scan] is the "current" item
			// Swap the current item with the item to the right of the
			// pivot element
			swap(arr[pivotPosition + 1], arr[pos]);

			// swap the current item with the pivot element
			swap(arr[pivotPosition], arr[pivotPosition + 1]);

			// adjust the pivot position so it stays with the pivot element
			pivotPosition++;
		}
	}
	return pivotPosition;
}

/*************************************************************************
* output an array's elements
*************************************************************************/
void outputArray(const int arr[], int size)
{
	for (int k = 0; k < size; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;
}

int main()
{
	const int arrSize = 6;
	int myArray[arrSize] = { 34,-45,78,32,90,45 };

	// read out the above array
	cout << "The unsorted array: ";
	outputArray(myArray, arrSize);

	// perform the sort and then output the result
	qSort(myArray, arrSize);
	cout << "The sorted array is: ";
	outputArray(myArray, arrSize);

	cin.get();
	return 0;
}