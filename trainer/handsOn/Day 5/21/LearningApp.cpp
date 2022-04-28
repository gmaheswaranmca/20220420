//Example to write the code replacing the strcpy
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char firstName[256];
	char anotherName[256];

	cout << "Enter first name:";
	cin >> firstName;					//Maheswaran \0
	//strcpy(anotherName, firstName);	//0123456789 10
	int I = 0;
	for (I=0; firstName[I] != '\0'; I++) { //for (int I; I < 256; I++)
		anotherName[I] = firstName[I];
	}
	anotherName[I] = '\0';
	cout << "first name: " << firstName << endl;
	cout << "another name: " << anotherName << endl;

	cout << "char count in first name: " << strlen(firstName) << endl;

	return EXIT_SUCCESS;
}