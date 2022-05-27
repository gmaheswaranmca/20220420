/*Q-
For given numbers array of size N, remove the given number from the array 
If number is not there, print -1.

Input:
5
10  34  12  18 2
11
Output:
-1

Input:
8
1  2  3  4  5   6  7  8
3
Output:
1 2 4 5 6 7 8

Test Case 1:
Input:
5
1 1 2 3 4
1
Output:
2 3 4

Test Case 2:
Input:
8
2  4 2  5  6 8 12  0
2
Output: 
4 5 6 8 12 0
Test Case 3:
Input:
8
10  20  10  25  67  80   0  5
100
Output:
-1

Test Case 4:
Input:
3
10  10  10
10
Output:
(Nothing will be printed)

Test Case 5:
Input:
7
190  234  2  17  30  78  -34
-1
Output:
-1
*/

#include<iostream>
using namespace std;

void read(int numbers[],int size){
    cout << "Enter numbers one by one:" << endl;
    for(int I=0;I<size;I++){
        cout << "Enter number at " << I << ":"; cin >> numbers[I];
    }
}

void print(int numbers[],int size){
    cout << "The arrauy:" << endl;
    for(int I=0;I<size;I++){
       cout << numbers[I] << " ";
    }
    cout << endl;
}
int findIndex(int numbers[],int size,int foundNumber){
    //CODE HERE
    for(int i=0;i<size;i++)
    {
        if(numbers[i]==foundNumber)
        {
            return i;
        }
    }
    return -1;
}
void removeNumber(int numbers[],int size, int removePosition){
    int k;
    
    for(k=removePosition; k<=(size-1); k++){
     numbers[k] = numbers[k+1];
    }
}
int main(){
    int numbers[] = {1,  2,  3,  4,  5,   6,  7,  8};
    //int numbers[] = {10,  20,  30,  40,  50,  60};
    
    int N = sizeof(numbers)/sizeof(int);
    //cout << "Enter size of numbers:"; cin >> N;
    //read(numbers,N);
    
    
    int searchNumber;
    cout << "Enter number to be removed:"; cin >> searchNumber;
    
    print(numbers,N);
    
    int index = findIndex(numbers,N,searchNumber);
    if(index == -1){
        cout << -1;
    }else{
        removeNumber(numbers,N,index);
        print(numbers,N-1);
    }
    
    
    
    return 0;
}