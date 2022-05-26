// C++ program for implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSortv1(int arr[], int n)  
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSortv2(int arr[], int startIndex, int endIndex)//arr,3,6
{
    int i, j, k=endIndex;
    for (i = startIndex; i <= (endIndex-1); i++) // i=3,4,5
     {
        // Last i elements are already in place
        
        for (j = startIndex; j <= (k-1); j++)//j=3,4,5 | 3,4 | 3
                                    //5-3=2
        {
                if (arr[j] > arr[j + 1])
            {
                        swap(arr[j], arr[j + 1]);
            }
        }
        k--;
    }
}

void selectionSortv1(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(arr[min_idx], arr[i]);
    }
}

void selectionSortv2(int arr[], int startIndex, int endIndex)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = startIndex; i <= (endIndex-1); i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j <= endIndex; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = { 5, 1, 4, 8, 2};
    int N = sizeof(arr) / sizeof(arr[0]);
    //bubbleSortv1(arr, N);
    //bubbleSortv2(arr, 0, N-1);
    bubbleSortv2(arr, 0, 2);
    bubbleSortv2(arr, 3, N-1);
    //selectionSortv2(arr, 0, N-1);
    //selectionSortv2(arr, 0, 2);
    //selectionSortv2(arr, 3, N-1);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}