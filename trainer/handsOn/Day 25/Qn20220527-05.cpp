/*
Print "perfect squares" from given numbers: 
Get list of numbers into an array and find and print the perfect squares.
It we cannot find one perfect square, then print just -1.


Input:
5
10  25  18  16  0
Output:
25	16

Input:
6
10  20  30  40  50  60
Output:
-1

Test Case 1:
Input:
4
10  21  36  56
Output:
36

Test Case 2:
Input:
8
25  30  40  56  10  4  81  0
Output :
25	4	81

Test Case 3:
Input:
6
7  85  90  102  254  200
Output :
-1

Test Case 4:
Input:
3
100 200 400
Output:
100	200

Test Case 5:
Input:
4
256  196  8   25
Output:
256	196	25
*/
#include<iostream>
#include<cmath>
using namespace std;

void read(int numbers[],int size){
    cout << "Enter numbers one by one:" << endl;
    for(int I=0;I<size;I++){
        cout << "Enter number at " << I << ":"; cin >> numbers[I];
    }
}
bool isPerfectSquare(int num){
    double squareRoot_d = sqrt((double)num);
    int squareRoot = (int)squareRoot_d;
    int squareOfRoot = squareRoot * squareRoot;
    return squareOfRoot == num; // if equals perfect square
}
void printPerfect(int numbers[],int size){
    int count = 0;
    cout << "Perfect squares are:" << endl;
    for(int I=0;I<size;I++){
        if(isPerfectSquare(numbers[I])){
            cout << numbers[I] << " ";
            count++;
        }
    }
    if(count==0){
        cout << -1;
    }
}
int main(){
    int numbers[] = {25,  30,  40,  56,  10,  4,  81,  0};
    //int numbers[] = {10,  20,  30,  40,  50,  60};
    
    int N = sizeof(numbers)/sizeof(int);
    //cout << "Enter size of numbers:"; cin >> N;
    //read(numbers,N);
    
    printPerfect(numbers,N);
    
    return 0;
}






