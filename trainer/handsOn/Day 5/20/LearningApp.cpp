//Example for strcpy, strlen
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char firstName[256];
	char anotherName[256];
	
	cout << "Enter first name:";
	cin >> firstName;
	strcpy(anotherName,firstName);
	cout << "first name: " << firstName << endl;
	cout << "another name: " << anotherName << endl;
	
	cout << "char count in first name: " << strlen(firstName) << endl;
	
	return EXIT_SUCCESS;
}