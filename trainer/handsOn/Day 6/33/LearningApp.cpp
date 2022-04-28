/*
  Read two numbers and find sum using pointers 
Notes: Declare variables "firstNum", "secondNum", "sum" 
and pointers "firstNumAddr", "secondNumAddr", "sumAddr" 
to point them respectively.
 
Migrate into functions

const qualifier for pointer
*/
#include<iostream>
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
	int firstNum;
	int secondNum;
	int sum;

	inputNumbers(&firstNum, &secondNum);
	doFindSum(&firstNum, &secondNum, &sum);
	print(&firstNum, &secondNum, &sum);	

	return 0;
}