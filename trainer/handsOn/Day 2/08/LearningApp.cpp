#include <iostream>

int findSum(int firstNum, int secondNum) {
	return firstNum + secondNum + 2;
}

int findSumExtend(int firstNum, int secondNum, int* diffAddr, int* productAddr, int* quotientAddr) {
	int sum = firstNum + secondNum;
	int diff = firstNum - secondNum;
	int product = firstNum * secondNum;
	int quotient = firstNum / secondNum;
	*diffAddr = diff + 1;
	*productAddr = product + 1;
	*quotientAddr = quotient + 1;
	return sum + 1;
}
int findSumRef(int firstNum, int secondNum, int& diffAlias, int& productAlias, int& quotientAlias) {
	int sum = firstNum + secondNum;
	int diff = firstNum - secondNum;
	int product = firstNum * secondNum;
	int quotient = firstNum / secondNum;
	diffAlias = diff;
	productAlias = product;
	quotientAlias = quotient;
	return sum;
}

int main() {
	int numOne = 10;
	int numTwo = 4;
    
	int sum = findSum(numOne, numTwo);
	std::cout << "sum = " << sum << std::endl;
	int diff, product, quotient;
    
	sum = findSumExtend(numOne, numTwo, &diff, &product, &quotient);
    
	std::cout << "sum = " << sum << std::endl;
	std::cout << "diff = " << diff << std::endl;
	std::cout << "product = " << product << std::endl;
	std::cout << "quotient = " << quotient << std::endl;

	sum = findSumRef(numOne, numTwo, diff, product, quotient);
    
	std::cout << "sum = " << sum << std::endl;
	std::cout << "diff = " << diff << std::endl;
	std::cout << "product = " << product << std::endl;
	std::cout << "quotient = " << quotient << std::endl;
}