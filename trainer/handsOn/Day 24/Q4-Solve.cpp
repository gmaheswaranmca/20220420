/*
Q4
Test Case 1:
  N = {23145}
  Output={Number of Digits=5, 
		Sum of Digits=15,
		Reverse of Number=54132,
		Is Palindrome=No}
Test Case 2:
  N = {54145}
  Output={Number of Digits=5, 
		Sum of Digits=19,
		Reverse of Number=54145,
		Is Palindrome=Yes}
		
*/
#include<iostream>
using namespace std;

int main(){
	int number = {23145};
	//Solve Here
    int sum=0;
    int count=0;
    int anotherNumber = number;
    int reverse=0;
    while(anotherNumber>0){            // 23145   2314   231     23       2         0x
        //Solve 
        count++;                        //  1      2      3       4       5
        int digit = anotherNumber % 10; //  5      4      3       2       1
        sum = sum + digit;              //  5      9      12      14      15
        reverse = (reverse * 10) + digit;// 0+5    50+4  540+3    5430+2  54320+1 = 54321 
        anotherNumber = anotherNumber / 10; //2314 231    23       2       0
    }
    //
	cout << "Number of Digits=" << count << endl;
	cout << "Sum of Digits=" << sum << endl;
	cout << "Reverse of Number=" << reverse << endl;
    if(number == reverse){
        cout << "Is Palindrome=Yes" << endl;
    }
    else {
        cout << "Is Palindrome=No" << endl;
    }
	return	0;
}