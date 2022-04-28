/*
  Read two numbers and find sum using pointers 
Notes: Declare variables "firstNum", "secondNum", "sum" 
and pointers "firstNumAddr", "secondNumAddr", "sumAddr" 
to point them respectively. 
*/
#include<iostream>
using namespace std;
int main() {
	int firstNum;
	int secondNum;
	int sum;

	int* firstNumAddr = NULL;
	int* secondNumAddr = NULL;
	int* sumAddr = NULL;

	firstNumAddr = &firstNum;
	secondNumAddr = &secondNum;
	sumAddr = &sum;

	cout << "Enter first number:";
	cin >> (*firstNumAddr); // (*firstNumAddr) alias for firstNum 

	cout << "Enter second number:";
	cin >> (*secondNumAddr);

	(*sumAddr) = (*firstNumAddr) + (*secondNumAddr);

	cout << "First number:" << (*firstNumAddr) << endl;
	cout << "Second number:" << (*secondNumAddr) << endl;
	cout << "Sum:" << (*sumAddr) << endl;

	return 0;
}