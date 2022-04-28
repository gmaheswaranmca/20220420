//Example for strcat
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
int main(){
	char firstName[256];
	char lastName[256];
	
	cout << "Enter first name:";
	cin >> firstName;	            
	
	cout << "Enter last name:";
	cin >> lastName;                
	
	strcat(firstName,lastName);     
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	
	return EXIT_SUCCESS;
}
