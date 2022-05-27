/*
Write the range function 
to print numbers between r1(start number) and r2(end number)
NOTE: Use Pointers in the range function for the two argumetns 

Input:
10  19
Output:
10 11	12 13	14 15	16 17	18 19

Input:
5   -5
Output:
5 4 3 2 1 0 -1 -2 -3	-4 -5

Test Case 1:
Input:
5   5
Output:
5

Test Case 2:
Input:
-4  4
Output:
-4 -3 -2 -1 0 1 2 3 4

Test Case 3:
Input:
20 10
Output:
20 19 18 17 16 15 14 13 12 11 10

Test Case 4:
Input:
120 125
Output:
120 121 122 123 124 125

Test Case 5:
Input:
-10 -1
Output:
-10 -9 -8 -7 -6 -5 -4 -3 -2 -1


Initial Code:
#include<stdio.h>
void range(int*,int*){
	//Solve HERE
}
void main()
 {
   int r1,r2;
   scanf("%d%d",&r1,&r2);
   range(&r1,&r2);
 }
 */
#include<iostream>
using namespace std;
void range(int* start, int* end) {
    //Solve HERE
    if (*start <= *end) {
        for (int i = (*start); i <= (*end); i++)
        {
            cout << i << endl;
        }
    }
    else {
        for (int i = (*start); i >= (*end); i--)
        {
            cout << i << endl;
        }
    }
}
void main()
{
    int r1, r2;
    cout << "Enter start range:";
    cin >> r1;
    cout << "Enter end range:";
    cin >> r2;
    range(&r1, &r2);
}

