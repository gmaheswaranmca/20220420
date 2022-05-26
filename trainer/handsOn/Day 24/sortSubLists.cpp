/*
Case 1
input:   N=9, 
         numbers= 3 7 8 5 2 1 9 5 4
		          -----
				        -----
						      ------
output:           3 7 8 1 2 5 4 5 9
Case 2
input : N=8,
		numbers = 6 5 3 1 8 7 2 4 
				  ----- 
				        -----
						      ---
output:           3 5 6 1 7 8 2 4 


input[N=9,numbers= 3 7 8 5 2 1 9 5 4]	
output[3 7 8 1 2 5 4 5 9]

input[N=8,numbers= 6 5 3 1 8 7 2 4]	
output[3 5 6 1 7 8 2 4]

input[N=11,numbers= 6 5 3 1 8 7 4 2 0 30 20]	
output[3 5 6 1 7 8 0 2 4 20 30]
*/
#include <bits/stdc++.h>
using namespace std;

void bubbleSortv3(int arr[], int startIndex, int endIndex)//arr,3,6
{
    int lastIndex = endIndex;
    
    while(startIndex <= (lastIndex - 1)) //Each pass 
     {
        bool isSwapped = false;    
        for (int J = startIndex; J <= (lastIndex - 1); J++) // "element" and "next element"
        {
            if (arr[J] > arr[J + 1])
            {
                swap(arr[J], arr[J + 1]);
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

void sortSublist(int arr[],int N){
     bubbleSortv3(arr, 0, 2);
   bubbleSortv3(arr, 3, N-6);
   bubbleSortv3(arr, N-5, N-1);
}

void sortSublistv2(int arr[],int N){
     int startIndex,endIndex,sublistSize=3;
     startIndex =0;
     endIndex =startIndex+sublistSize -1;
     
     bubbleSortv3(arr,startIndex , endIndex);
     startIndex =endIndex+1;
     endIndex =startIndex+sublistSize -1;
      bubbleSortv3(arr,startIndex , endIndex);
  
  startIndex =endIndex+1;
     endIndex =startIndex+sublistSize -1;
      bubbleSortv3(arr,startIndex , endIndex);
  
}

void sortSublistv3(int arr[],int N){
     int startIndex,endIndex,sublistSize=3;
     int SubListCount=N/sublistSize;
     if(N%sublistSize!=0)
     {
         SubListCount++;
     }
     
     startIndex =0;
     endIndex =startIndex+sublistSize -1;
     
     for(int i=1;i<=SubListCount;i++)
     {
        bubbleSortv3(arr,startIndex , endIndex);
        startIndex =endIndex+1;
        endIndex =startIndex+sublistSize -1;
            if(endIndex>N-1)
             {
                 endIndex =N-1;
            }
     }
      
}


int main()
{
   
    int arr[] ={6,5 ,3, 1, 8};
    
 
    int N = sizeof(arr) / sizeof(arr[0]);
    
    cout << "before sorting array: \n";
    printArray(arr, N);
    
   // sortSublistv2(arr,N);
    sortSublistv3(arr,N);
  // bubbleSortv3(arr, 0, 2);
  // bubbleSortv3(arr, 3, N-6);
  // bubbleSortv3(arr, N-5, N-1);
   
    cout << "After Sorted array: \n";
    printArray(arr, N);
    return 0;
}