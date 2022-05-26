/*
input[N=9,numbers= 3 7 8 5 2 1 9 5 4]	
output[3 7 8 1 2 5 4 5 9 ]

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


void sortSublistv3(int arr[],int N,int sublistSize){
     int startIndex,endIndex;
     int SubListCount=N/sublistSize;        //11/3 =3       12/3=4      15/3=5
     if(N%sublistSize!=0)           //11%3 =2       12%3==0     15%3==0
     {
         SubListCount++;        //3+1=4
     }
     
     startIndex =0;
     endIndex =startIndex+sublistSize -1;   //2
     
     for(int i=1;i<=SubListCount;i++)       //i=1 i<=3 i=2  i=3 i=4 (i=5 Failed)
     {
        bubbleSortv3(arr,startIndex , endIndex);    //arr,0,2  arr,3,5      arr,6,8     arr,9,10
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
    int subListSize = 4;
    
    cout << "before sorting array: \n";
    printArray(arr, N);
    
    sortSublistv3(arr,N,subListSize);

   
    cout << "After Sorted array: \n";
    printArray(arr, N);
    return 0;
}