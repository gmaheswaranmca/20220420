/*
Read two numbers and find sum using pointers 
Notes: Declare variables "firstNum", "secondNum", "sum" 
and pointers "firstNumAddr", "secondNumAddr", "sumAddr" 
to point them respectively.
 
Migrate into functions

const qualifier for pointer

c++ dynamic memory 
*/    
#include<iostream>
#include<cstdlib>
using namespace std;
void inputNumbers(int*const firstNumAddr, int* const secondNumAddr) {
	cout << "Enter first number:";
	cin >> (*firstNumAddr); 

	cout << "Enter second number:";
	cin >> (*secondNumAddr);
}
void doFindSum(const int*const firstNumAddr, const int* const secondNumAddr, int* const sumAddr) {
	(*sumAddr) = (*firstNumAddr) + (*secondNumAddr);
}
void print(const int* const firstNumAddr, const int* const secondNumAddr, const int* const sumAddr) {
	cout << "First number:" << (*firstNumAddr) << endl;
	cout << "Second number:" << (*secondNumAddr) << endl;
	cout << "Sum:" << (*sumAddr) << endl;
}


int main() {
	int* firstNumAddr = NULL;	
	int* secondNumAddr = NULL;
	int* sumAddr = NULL;

	firstNumAddr = new int;
	secondNumAddr = new int;
	sumAddr = new int;

	inputNumbers(firstNumAddr, secondNumAddr);
	doFindSum(firstNumAddr, secondNumAddr, sumAddr);
	print(firstNumAddr, secondNumAddr, sumAddr);

	delete firstNumAddr;
	delete secondNumAddr;
	delete sumAddr;

	firstNumAddr = NULL; 
	secondNumAddr = NULL;
	sumAddr = NULL;
	
	return 0;
} 