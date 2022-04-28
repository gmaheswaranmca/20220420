/*
  Read two numbers and find sum using pointers 
Notes: Declare variables "firstNum", "secondNum", "sum" 
and pointers "firstNumAddr", "secondNumAddr", "sumAddr" 
to point them respectively.
 
Migrate into functions

const qualifier for pointer

c-dynamic memory 
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
	int* firstNumAddr = NULL;		// to avoid WILD ptr
	int* secondNumAddr = NULL;
	int* sumAddr = NULL;

	firstNumAddr = (int*)malloc(1 * sizeof(int));
	secondNumAddr = (int*)malloc(1 * sizeof(int));
	sumAddr = (int*)malloc(1 * sizeof(int));

	inputNumbers(firstNumAddr, secondNumAddr);
	doFindSum(firstNumAddr, secondNumAddr, sumAddr);
	print(firstNumAddr, secondNumAddr, sumAddr);

	free(firstNumAddr);	//Dangling ptr -> pointer points to released memory block
	free(secondNumAddr);
	free(sumAddr);

	firstNumAddr = NULL; //to avoid illegal access with Dangling pt
	secondNumAddr = NULL;
	sumAddr = NULL;
	
	return 0;
}