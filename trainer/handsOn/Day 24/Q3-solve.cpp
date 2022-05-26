/*
Q3
--------------------------------------------------------------------------
Third Largest Number from each half sub-array of the given array of size N
input[N=11,numbers= {6, 5, 3, 1, 8, 7, 4, 2, 0, 30, 20}]	
					 --------------
                                    ------------------					 
output{5,7}
--------------------------------------------------------------------------

--------------------------------------------------------------------------
Avinash - desc insertion 		
--------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;
void myInsertionSort(int arr[], int startIndex, int endIndex, bool isAsc){
	for (int I = startIndex+1; I <= endIndex; I++) {
		int eI = arr[I];
		int newPos = I;
		for (int J = I - 1; J >= startIndex ;J--) {//sorted-list
			bool condValue;
            
            if(isAsc){
                condValue = arr[J] > eI;
            }else{
                condValue = arr[J] < eI;
            }
            
			if (false == condValue) {
				break;
			}
			arr[J + 1] = arr[J];
			newPos = J;
		}
		if(newPos != I){
			arr[newPos] = eI;
		}
	}
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int findThirdLargest(int arr[], int startIndex, int endIndex){
    myInsertionSort(arr,startIndex,endIndex,false);
    int foundIndex = startIndex + 3 - 1;
    return arr[foundIndex];
}

int main()
{   
    int arr[] ={6, 5, 3, 1, 8, 7, 4, 2, 0, 30, 20};      
    int N = sizeof(arr) / sizeof(arr[0]);    
    
    cout << "before sorting array: \n";
    printArray(arr, N);
    
    cout << "third largest of first half sub array is " << findThirdLargest(arr,0,(N/2)-1) << endl;
    cout << "third largest of second half sub array is " << findThirdLargest(arr,(N/2),N-1) << endl;
    
    return 0;
}

/*
Shrikant - Ascending [xBubble] Selection
		   ---------           ---------
Subhash  - Descending Ascendingx  Bubble  
           ---------              ------		   
Uday - Descending Bubblex Selection 	Ascx 	   
       ----------         ---------
Divya - asc,insertion  bubblex
        --- ---------	   
Anil    - asc Bubble 
*/

// C++ program to find third Largest
// element in an array of distinct elements
#include <bits/stdc++.h>

void thirdLargest(int arr[], int startIndex, int endIndex)
{
    /* There should be atleast three elements */
    if (endIndex < 3)
    {
        printf(" Invalid Input ");
        return;
    }

    // Find first largest element
    //int first = arr[0];
    int first = INT_MIN;
    for (int i = startIndex; i < endIndex ; i++)
        if (arr[i] > first)
            first = arr[i];

    // Find second largest element
    int second = INT_MIN;
    for (int i = startIndex; i < endIndex ; i++)
        if (arr[i] > second && arr[i] < first)
            second = arr[i];

    // Find third largest element
    int third = INT_MIN;
    for (int i = startIndex; i < endIndex ; i++)
        if (arr[i] > third && arr[i] < second)
            third = arr[i];

    printf("%d  ", third);
}

/* Driver program to test above function */
int main()
{
    int arr[] = {6, 50, 3, 1, 8, 7, 40, 2, 0, 30, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    thirdLargest(arr, 0, 5);
    thirdLargest(arr, 5, 11);
    return 0;
}


/*
Manikanta - asc,selection
*/