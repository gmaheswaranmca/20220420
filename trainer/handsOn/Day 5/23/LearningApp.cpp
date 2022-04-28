//Solve:
//Console read the two c-strings "firstName", "lastName" 
//and do string addition (concatenation) of those names into "fullName" c-string
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
int main(){
	char firstName[256];
	char lastName[256];
	char fullName[256];
	
	cout << "Enter first name:";
	cin >> firstName;			// "Maheswaran"
	
	cout << "Enter last name:";
	cin >> lastName;			// "Govindaraju"
	
	strcpy(fullName,firstName);	// fullName <= "Maheswaran"
	strcat(fullName," ");		// fullName <= "Maheswaran "
	strcat(fullName,lastName);	// fullName <= "Maheswaran Govindaraju"
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "full name: " << fullName << endl;
	
	return EXIT_SUCCESS;
}