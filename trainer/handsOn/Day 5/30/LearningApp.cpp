/*
 5. reverse string, fibonacii
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

void stringReverse(char text[], char reversed[]) {
	//find the last index of the given word using strlen -> lastIndex=strlen(text)-1;
	//(::J=0)
	//from the last index till 0 th index (::I) <-- Decrement loop
	//	loop
			//copy character into reversed
			//reversed[J] = text[I]; J++;
	//  end loop
}

int main() {
	char someText[256];
	char result[256];
	cout << "Enter text/name:";
	cin >> someText;	//fibonacii

	stringReverse(someText, result);

	cout << "Reverse of " << someText << " is " << result;

	return EXIT_SUCCESS;
}