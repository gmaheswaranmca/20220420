#include "CustomerApplication.h"
#include <iostream>
#include <string>
using namespace std;
void CustomerApplication::customerApp() {
	int menu;
	do {
		cout << "1. Login" << endl;
		cout << "2. Customer Registration" << endl;
		cout << "Your Option:"; cin >> menu;
		if (1 == menu) {
			cout << "Login." << endl;
		}
		else if (2 == menu) {
			cout << "Customer Registration." << endl;
		}
	} while (menu != 0);
}
void CustomerApplication::customerRegistration() {

}
void CustomerApplication::customerLogin() {

}
void CustomerApplication::customerHomePage() {
	//Loan Application
	//View Application
}