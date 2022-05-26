/*
Q2
input[N=9,numbers={3, 7, 8, 5, 2, 1, 9, 5, 4}]	
output{3, 7, 9, 8, 5, 2, 1, 5, 4}

input[N=8,numbers= {6, 5, 3, 1, 8, 7, 2, 4}]	
output{6, 5, 8, 7, 3, 1, 2, 4}

input[N=11,numbers= {6, 5, 3, 1, 8, 7, 4, 2, 0, 30, 20}]	
output{6, 5, 8, 7, 4, 3, 2, 1, 0, 30, 20}
*/
#include <bits/stdc++.h>
using namespace std;
void mySwap(int *firstAddr, int *secondAdd){
    int temp = (*firstAddr);
    (*firstAddr) = (*secondAdd);
    (*secondAdd) = temp;
}


void myBubbleSort(int arr[], int startIndex, int endIndex, bool isAsc)
{
    int lastIndex = endIndex;
    
    while(startIndex <= (lastIndex - 1)) //Each pass 
     {
        bool isSwapped = false;    
        for (int J = startIndex; J <= (lastIndex - 1); J++) // "element" and "next element"
        {
            bool condValue;
            
            if(isAsc){
                condValue = arr[J] > arr[J + 1];
            }else{
                condValue = arr[J] < arr[J + 1];
            }
            
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


void mySelectionSort(int arr[], int startIndex, int endIndex, 
    bool isAsc) //0, 1, 2, 7, 4, 8, 3
{
    for (int I = startIndex; I <= (endIndex-1); I++)//each Pass
    {
        int sortIndex = I;
        for (int J = I+1; J <= endIndex; J++){//select sortable element index
            bool condValue;
            
            if(isAsc){
                condValue = arr[J] < arr[sortIndex];
            }else{
                condValue = arr[J] > arr[sortIndex];
            }
            
            if (condValue){
                sortIndex = J;
            }
        }
        if(sortIndex != I){
            mySwap(&arr[sortIndex], &arr[I]);
        }
    }
}
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



int main()
{   
    int arr[] ={6, 5, 3, 1, 8, 7, 4, 2, 0, 30, 20};      
    int N = sizeof(arr) / sizeof(arr[0]);
    //int subListSize = 3;
    int subListSize = 4;
    
    cout << "before sorting array: \n";
    printArray(arr, N);
    
    int sortAlgorithmChoice;
    cout << "Choice(1-Bubble,2-Selection):"; cin >> sortAlgorithmChoice;
    int sortChoice;
    cout << "Choice(1-Ascending,2-Descending):"; cin >> sortChoice;
    int startIndex = (0) + 2;
    int endIndex = (N - 1) - 2;
    if(sortAlgorithmChoice == 1){
        myBubbleSort(arr,startIndex,endIndex,sortChoice==1);
    }else if(sortAlgorithmChoice == 2){
        mySelectionSort(arr,startIndex,endIndex,sortChoice==1);
    }else if(sortAlgorithmChoice == 3){
        myInsertionSort(arr,startIndex,endIndex,sortChoice==1);
    }
   
    cout << "After Sorted array: \n";
    printArray(arr, N);
    return 0;
}