#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Account{
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
		Account(const Account &acc);
		//destructor:
		~Account();
		//services/interfaces
		void deposit(float amount);
		void withdraw(float amount);
		//support services 
		void read();
		void print();
};
int Account::instanceCount = 0;
void Account::updateInstanceCount(){
	Account::instanceCount++;
}

Account::Account(){
	Account::updateInstanceCount();
    
	this->accountId = Account::instanceCount;
	this->accountNumber = 0;
	strcpy(this->accountHolderName,"");
	this->balance = 0.0f;
    
    cout << this->accountId << ") Constructor - Default" << endl;
}
Account::Account(int accountNumber, char accountHolderName[], float balance){
	Account::updateInstanceCount();
    
	this->accountId = Account::instanceCount;
	this->accountNumber = accountNumber;
	strcpy(this->accountHolderName,accountHolderName);
	this->balance = balance;
    
    cout << this->accountId << ") Constructor - Parameterized" << endl;
}
Account::Account(const Account &acc){
	Account::updateInstanceCount();
    
	this->accountId = Account::instanceCount;
	this->accountNumber = acc.accountNumber;
	strcpy(this->accountHolderName,acc.accountHolderName);
	this->balance = acc.balance;
    
    cout << this->accountId << ") Constructor - Copy" << endl;
}
Account::~Account(){
	cout << this->accountId << ") Destructor" << endl;
}

void Account::deposit(float amount){
	this->balance = this->balance + amount;
}
void Account::withdraw(float amount){
	this->balance = this->balance - amount;
}

void Account::read(){
	cout << "Enter Account Details of Account ID " << this->accountId << endl;
	cout << "Enter Account Number:"; cin >> this->accountNumber;
	cout << "Enter Account Holder Name:"; cin >> this->accountHolderName;
	cout << "Enter Initial Deposit:"; cin >> this->balance;
}
void Account::print(){
	cout << "The Account Details of Account ID " << this->accountId << endl;
	cout << "Account Number:" <<  this->accountNumber << endl;
	cout << "Account Holder Name:" << this->accountHolderName << endl;
	cout << "Balance:" << this->balance << endl;
}

int main(){
	Account account;
	
	account.read();
	account.deposit(500);
	account.deposit(1000);
	account.deposit(500);
	account.deposit(600);
	account.withdraw(100);
	account.deposit(500);
	account.print();
	
	return EXIT_SUCCESS;
}