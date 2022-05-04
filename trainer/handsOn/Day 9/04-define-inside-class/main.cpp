#include<iostream>
#include<cstring>
using namespace std;

class Account{
	private:
static int instanceCount;
static void updateInstanceCount(){
    Account::instanceCount++;
}
	private:
		int accountId;
		int accountNumber;
		char accountHolderName[256];
		float balance;
	public:
		//constructors:Default(No arg), Parameterized, Copy
Account(){
	Account::updateInstanceCount();
	this->accountId = Account::instanceCount;
	cout << this->accountId << ") Constructor - Default" << endl;
	this->accountNumber = 0;
	strcpy(this->accountHolderName,"");
	this->balance = 0.0f;
}
Account(int accountNumber, char accountHolderName[], float balance){
	Account::updateInstanceCount();
	this->accountId = Account::instanceCount;
	cout << this->accountId << ") Constructor - Parameterized" << endl;
	this->accountNumber = accountNumber;
	strcpy(this->accountHolderName,accountHolderName);
	this->balance = balance;
}
Account(const Account &acc){
	Account::updateInstanceCount();
	this->accountId = Account::instanceCount;
	cout << this->accountId << ") Constructor - Copy" << endl;
	this->accountNumber = acc.accountNumber;
	strcpy(this->accountHolderName,acc.accountHolderName);
	this->balance = acc.balance;
}		
        
        //destructor:
        
~Account(){
	cout << this->accountId << ") Destructor" << endl;
}
        
        
		//services/interfaces
        
void deposit(float amount){
	this->balance = this->balance + amount;
}
void withdraw(float amount){
	this->balance = this->balance - amount;
}
        
		//support services 
        
void read(){
	cout << "Enter Account Details of Account ID " << this->accountId << endl;
	cout << "Enter Account Number:"; cin >> this->accountNumber;
	cout << "Enter Account Holder Name:"; cin >> this->accountHolderName;
	cout << "Enter Initial Deposit:"; cin >> this->balance;
}
void print(){
	cout << "The Account Details of Account ID " << this->accountId << endl;
	cout << "Account Number:" <<  this->accountNumber << endl;
	cout << "Account Holder Name:" << this->accountHolderName << endl;
	cout << "Balance:" << this->balance << endl;
}
};

int Account::instanceCount = 0;

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

