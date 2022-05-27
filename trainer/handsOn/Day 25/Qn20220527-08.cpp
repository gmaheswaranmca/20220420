/*
Write the range function 
to print prime numbers between start(start number) and end(end number)
NOTE: Use Pointers in the range function for the two argumetns 

Input:
10  20
Output:
11	13	17	19

Input:
-12   30
Output:
-1

Test Case 1:
Input:
5  17
Output:
5 7 11 13 17
Test Case 2:
Input:
2  25
Output:
2 3 5 7 11 13 17 19 23	

Test Case 3:
Input:
10  30
Output:
11 13 17 19 23 29

Test Case 4:
Input:
10  -4
Output:
-1

Test Case 5:
Input:
7  7
Output:
7


Initial Code:
#include<iostream>
using namespace std;
bool isPrimeNumber(int num){
	return false;
}
void range(int* startAddr, int* endAddr) {
    //Print Prime Numbers between
}
void main()
{
    int start, end;
    cout << "Enter start range:";
    cin >> start;
    cout << "Enter end range:";
    cin >> end;
    range(&start, &end);
}
 */
 
#include<iostream>
using namespace std;
bool isPrimeNumber(int num){
     if (num == 1 || num == 0){ return false;}
   bool  flag = true;
        for (int j = 2; j <= num / 2; ++j) {
            if (num % j == 0) {
                flag = false;
                break;
            }
        }
    return flag;
}
void range(int* startAddr, int* endAddr) {
    //Print Prime Numbers between
    int s=-1;
    int i;
    if(*startAddr<0||*endAddr<0){
        cout<<s;
        return ;
    }
    for (i = *startAddr; i <= *endAddr; i++) {
       
        
        if (isPrimeNumber(i))
         cout<<i<<" ";
    }
}
void main()
{
    int start, end;
    cout << "Enter start range:";
    cin >> start;
    cout << "Enter end range:";
    cin >> end;
    range(&start, &end);
}