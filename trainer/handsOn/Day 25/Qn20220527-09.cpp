/*
Checking Armstrong numbers in three digit: 
Get one three digit positive integer and check that number is Armstrong number or not.
"Armstrong number of three digits means, 
sum of cube of individual digit is equal to that number"

Input:
105
Output:
Not Armstrong

Input:
153                 -> 1^3 + 5^3 + 3^3 -> 1 + 125 + 27 = 153
Output:
Armstrong

Test Case 1:
Input:
102
Output:
Not Armstrong

Test Case 2:
Input:
370                 ->  3^3 + 7^3 + 0^0 -> 27 + 343 + 0 = 370
Output:
Armstrong

Test Case 3:
Input:
-50
Output:
Invalid Input

Test Case 4:
Input:
371                 ->  3^3 + 7^3 + 1^3 -> 27 + 343 + 1 = 371
Output:
Armstrong

Test Case 5:
Input:
0
Output:
Not Armstrong



*/

#include<iostream>
using namespace std;
int main()
{
    int number,sum=0,arm,i,r;
    cout << "enter your number";cin >> number;
    arm = number;
    if (number <= 0)
    {
        cout << "invalid output" << endl;

    }
    else {
        while (number > 0)
        {
            i = number % 10;
            r = i * i * i;
            sum = sum + r;
            number = number / 10;
        }
    }
    number = arm;
    if (number == sum)
    {
        cout << "given number is armstrong" << endl;

    }
    else
    {
        cout << "given number is not armstrong" << endl;
    }

}