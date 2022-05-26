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
*/
#include <iostream>
using namespace std;
void selectionSort(int arr[], int startIndex, int endIndex, bool isAsc)
{
    int i, j, min_idx;
    for (i = startIndex; i <= (endIndex-1); i++)
    {
        min_idx = i;
        for (j = i+1; j <= endIndex; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}
int findThirdLargest(int arr[], int startIndex, int endIndex) {
    selectionSort(arr, startIndex, endIndex, false);
    int foundIndex = endIndex -3 + 1;
    return arr[foundIndex];
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = { 6, 5, 3, 1, 8, 7, 4, 2, 0, 30, 20 };
    int N = sizeof(arr) / sizeof(arr[0]);
   
   cout << "3rd larget in first sublist: " << findThirdLargest(arr, 0, (N/2)-1)<<endl;
    //selectionSort(arr, 5, N-1);
   cout << "3rd larget in second sublist: " << findThirdLargest(arr, (N / 2),N - 1) << endl;
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}
/*           
Subhash  - Descending Ascendingx  Bubble  
           ---------              ------		   
*/
#include <bits/stdc++.h>
using namespace std;
void mySwap(int *firstAddr, int *secondAdd){
    int temp = (*firstAddr);
    (*firstAddr) = (*secondAdd);
    (*secondAdd) = temp;
}
void myBubbleSort(int arr[], int startIndex, int endIndex)
{
    int lastIndex = endIndex;
    
    while(startIndex <= (lastIndex - 1)) //Each pass 
     {
        bool isSwapped = false;    
        for (int J = startIndex; J <= (lastIndex - 1); J++) // "element" and "next element"
        {
            bool condValue;
            
                condValue = arr[J] < arr[J + 1];
            
            
            if (condValue)
            {
                mySwap(&arr[J], &arr[J + 1]);
                isSwapped = true;
            }
        }
        if(isSwapped == false){ //OPTIMIZATION 1
            break;
        }
        lastIndex--; //OPTIMIZATION 2
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void sortSublistv3(int arr[],int N,int sublistSize){
     int startIndex,endIndex;
     int SubListCount=N/sublistSize;        
     if(N%sublistSize!=0)           
     {
         SubListCount++;       
     }
     
     startIndex =0;
     endIndex =startIndex+sublistSize -1;  
     
     for(int i=1;i<=SubListCount;i++)       
     {
        myBubbleSort(arr,startIndex,endIndex);    //arr,0,2  arr,3,5      arr,6,8     arr,9,10
        startIndex =endIndex+1;                     //sI =3     6       9       11
        endIndex =startIndex+sublistSize -1;        //EI =3+3-1=5   8   11      13
            if(endIndex>N-1)                        //failed   Failed   Passed  Passed
             {
                 endIndex =N-1;             //11-1=10   10
            }
     }
      
}
int main()
{   
    int arr[] ={6, 5, 3, 1, 8, 7, 4, 2, 0, 30, 20};      
    int N = sizeof(arr) / sizeof(arr[0]);
    //int subListSize = 3;
    int subListSize = (N/3)+1;
    
    cout << "before sorting array: \n";
    printArray(arr, N);
   // int startIndex = 0;
   // int endIndex = (N - 1);
   
    sortSublistv3(arr,N,subListSize);
    cout << "After Sorted array: \n";
    printArray(arr, N);
    int sublsIndex=1;
    cout<<endl;
    cout<<"Third largest element of array= "<<arr[subListSize*(sublsIndex-1)+3-1]<<endl;
    sublsIndex++;
    cout<<"Third largest element of array= "<<arr[subListSize*(sublsIndex-1)+3-1]<<endl;
    return 0;
}
/*           
Uday - Descending Bubblex Selection 	Ascx 	   
       ----------         ---------
*/

/*       
Divya - asc,insertion  bubblex
        --- ---------	   
*/

/*        
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
