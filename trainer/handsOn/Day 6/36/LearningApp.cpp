/*
Read two numbers and find sum using pointers 
Notes: Declare variables "firstNum", "secondNum", "sum" 
and pointers "firstNumAddr", "secondNumAddr", "sumAddr" 
to point them respectively.
 
Migrate into functions

references for data processing

c++ dynamic memory 
*/    
#include<iostream>
#include<cstdlib>
using namespace std;
void inputNumbers(int& firstNum, int& secondNum) {
	cout << "Enter first number:";
	cin >> firstNum; 

	cout << "Enter second number:";
	cin >> secondNum;
}
void doFindSum(int& firstNum, int& secondNum, int& sum) {
	sum = firstNum + secondNum;
}
void print(int& firstNum, int& secondNum, int& sum) {
	cout << "First number:" << firstNum << endl;
	cout << "Second number:" << secondNum << endl;
	cout << "Sum:" << sum << endl;
}


int main() {
	int* firstNumAddr = NULL;	
	int* secondNumAddr = NULL;
	int* sumAddr = NULL;

	firstNumAddr = new int;
	secondNumAddr = new int;
	sumAddr = new int;

	inputNumbers((*firstNumAddr), (*secondNumAddr));
	doFindSum((*firstNumAddr), (*secondNumAddr), (*sumAddr));
	print((*firstNumAddr), (*secondNumAddr), (*sumAddr));

	delete firstNumAddr;
	delete secondNumAddr;
	delete sumAddr;

	firstNumAddr = NULL; 
	secondNumAddr = NULL;
	sumAddr = NULL;
	
	return 0;
}
