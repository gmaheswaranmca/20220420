#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Account {
private:
	static int instanceCount;
	static void updateInstanceCount();
private:
	int accountId;
	int accountNumber;
	char accountHolderName[256];
	float balance;
public:
	//constructors:Default(No arg), Parameterized, Copy
	Account();
	Account(int accountNumber, char accountHolderName[], float balance);
	Account(const Account& acc);
	//destructor:
	~Account();
	//services/interfaces
	void deposit(float amount);
	void withdraw(float amount);
	//support services 
	friend istream& operator>>(istream& input,Account& account);
	friend ostream& operator<<(ostream& output, const Account& account);
};

int Account::instanceCount = 0;
void Account::updateInstanceCount() {
	Account::instanceCount++;
}

Account::Account() {
	Account::updateInstanceCount();

	this->accountId = Account::instanceCount;
	this->accountNumber = 0;
	strcpy(this->accountHolderName, "");
	this->balance = 0.0f;

	cout << this->accountId << ") Constructor - Default" << endl;
}
Account::Account(int accountNumber, char accountHolderName[], float balance) {
	Account::updateInstanceCount();

	this->accountId = Account::instanceCount;
	this->accountNumber = accountNumber;
	strcpy(this->accountHolderName, accountHolderName);
	this->balance = balance;

	cout << this->accountId << ") Constructor - Parameterized" << endl;
}
Account::Account(const Account& acc) {
	Account::updateInstanceCount();

	this->accountId = Account::instanceCount;
	this->accountNumber = acc.accountNumber;
	strcpy(this->accountHolderName, acc.accountHolderName);
	this->balance = acc.balance;

	cout << this->accountId << ") Constructor - Copy" << endl;
}
Account::~Account() {
	cout << this->accountId << ") Destructor" << endl;
}

void Account::deposit(float amount) {
	this->balance = this->balance + amount;
}
void Account::withdraw(float amount) {
	this->balance = this->balance - amount;
}


istream& operator>>(istream& input, Account& account) {
	cout << "Enter Account Details of Account ID " << account.accountId << endl;
	cout << "Enter Account Number:"; input >> account.accountNumber;
	cout << "Enter Account Holder Name:"; input >> account.accountHolderName;
	cout << "Enter Initial Deposit:"; input >> account.balance;
	return input;
}
ostream& operator<<(ostream& output, const Account& account) {
	output << endl << endl << "The Account Details of Account ID " << account.accountId << endl;
	output << "Account Number:" << account.accountNumber << endl;
	output << "Account Holder Name:" << account.accountHolderName << endl;
	output << "Balance:" << account.balance << endl;
	return output;
}

int main() {
	Account account;

	cin >> account;
	account.deposit(500);
	account.deposit(1000);
	account.deposit(500);
	account.deposit(600);
	account.withdraw(100);
	account.deposit(500);
	cout << account;

	return EXIT_SUCCESS;
}