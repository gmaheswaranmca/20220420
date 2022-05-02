#include "Account.h"
#include<iostream>
using namespace std;
void Account::deposit(float amount) {
	this->balance = this->balance + amount;
}

void Account::withdraw(float amount) {
	this->balance = this->balance - amount;
}
void Account::read() {
	cout << "Enter Account Number:";
	cin >> this->accountNumber;

	cout << "Enter Account Holder Name:";
	cin >> this->accountHolderName;

	cout << "Initial Deposit:";
	cin >> this->balance;
}
void Account::print() {
	cout << "Account ID:" << this->accountId << endl;
	cout << "Account Number:" << this->accountNumber << endl;
	cout << "Account Holder Name:" << this->accountHolderName << endl;
	cout << "Balance:" << this->balance << endl;
}

//has no-return type, may have args | name is class name
//at the time object creation (allocating memory)
//initialization process: intialze attributes, opening the resources
Account::Account() {
	Account::updateObjCount();
	this->accountId = Account::objCount;
	cout << this->accountId << ")Constructor is called" << endl;
}
//has no-return type, have no args | name is class name
//at the time object destruction (deallocating memory)
//cleaning up process: releasing the resources
Account::~Account() {
	cout << this->accountId << ")Destructor is called" << endl;
}

int Account::objCount = 0;
void Account::updateObjCount() {
	Account::objCount++;
}