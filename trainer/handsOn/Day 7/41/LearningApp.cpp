//function pointer
//pass function pointer to the function 
#include<iostream>
using namespace std;
int findSum(int firstNum, int secondNum) {
	return firstNum + secondNum;
}
int findDiff(int firstNum, int secondNum) {
	return firstNum - secondNum;
}

int findResult(int firstNum, int secondNum, int (*opAddr)(int, int)) {
	return (*opAddr)(firstNum, secondNum);
}

int main() {
	int (*opArithAddr)(int, int) = NULL;

	int numOne, numTwo;
	cout << "First Number:";
	cin >> numOne;

	cout << "Second Number:";
	cin >> numTwo;

	int menu;

	cout << "Choice(1-Addition,2-Subtraction):";
	cin >> menu;
	
	switch (menu) {
	case 1:
		cout << findResult(numOne, numTwo,&findSum) << endl;
		break;
	case 2:
		cout << findResult(numOne, numTwo, &findDiff) << endl;
		break;
	}
	return EXIT_SUCCESS;
}