/*Qn:
Create six dynamic memories and put into pointers
named 
firstNumAddr, secondNumAddr, sumAddr, diffAddr, productAddr, quotientAddr
Use following functions 
void readNumbers(int& firstNum, int& secondNum) to read two numbers 
void doFindSumExt(int& firstNum, int& secondNum,
    int &sum, int &diff, int &product, int & quotient); to do sum, diff, product, quotient 
void print(int& firstNum, int& secondNum,
    int &sum, int &diff, int &product, int & quotient)
    
Complete the driver program
Allocate six c++ dynamic memory and makd necessary function calls    
*/
#include<iostream>
using namespace std;
void readNumbers(int& firstNum, int& secondNum){
    cout << "Enter first number:";
	cin >> firstNum; 

	cout << "Enter second number:";
	cin >> secondNum;
}
void doFindSumExt(int& firstNum, int& secondNum,
    int &sum, int &diff, int &product, int & quotient){
        sum = firstNum + secondNum;
        diff = firstNum - secondNum;
        product = firstNum * secondNum;
        quotient = firstNum / secondNum;
}
void print(int& firstNum, int& secondNum,
    int &sum, int &diff, int &product, int & quotient){
    cout << "First number:" << firstNum << endl;
	cout << "Second number:" << secondNum << endl;
	cout << "Sum:" << sum << endl;
    cout << "Diff:" << diff << endl;
    cout << "Product:" << product << endl;
    cout << "Quotient:" << quotient << endl;
}

int main() {
    //CODE HERE 
    return 0;
}