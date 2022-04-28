/*
  Read two numbers and find sum using pointers 
Notes: Declare variables "firstNum", "secondNum", "sum" 
and pointers "firstNumAddr", "secondNumAddr", "sumAddr" 
to point them respectively. 
Migrate into functions
*/
#include<iostream>
using namespace std;
void inputNumbers(int* firstNumAddr, int* secondNumAddr) {
	cout << "Enter first number:";
	cin >> (*firstNumAddr); // (*firstNumAddr) alias for firstNum 

	cout << "Enter second number:";
	cin >> (*secondNumAddr);
}
void doFindSum(const int* firstNumAddr, const int* secondNumAddr, int* sumAddr) {
	(*sumAddr) = (*firstNumAddr) + (*secondNumAddr);
}
void print(const int* firstNumAddr, const int* secondNumAddr, const int* sumAddr) {
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