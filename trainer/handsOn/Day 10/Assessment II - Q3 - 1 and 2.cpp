#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

struct _person_t {
	char firstName[256];
	char lastName[256];
	char fullName[256];
};
typedef struct _person_t person_t;

void doProcess(person_t* personAddr) {
	/* Do here the swap and then update of names */
	
	//
	char t[256];
	strcpy(t, personAddr->firstName);
	strcpy(personAddr->firstName, personAddr->lastName);
	strcpy(personAddr->lastName, t);
	//
	strcpy(personAddr->fullName, personAddr->firstName);
	strcat(personAddr->fullName, " ");
	strcat(personAddr->fullName, personAddr->lastName);
}
int main() {
	person_t person;
	cout << "Enter First Name :"; cin >> person.firstName;
	cout << "Enter Last Name :"; cin >> person.lastName;

	//doProcess(&person);
	void (*doProcessAddr)(person_t * personAddr);
	doProcessAddr = &doProcess;
	(*doProcessAddr)(&person);

	cout << "First Name :" << person.firstName << endl;
	cout << "Last Name :" << person.lastName << endl;
	cout << "Full Name :" << person.fullName << endl;

	return EXIT_SUCCESS;
}
