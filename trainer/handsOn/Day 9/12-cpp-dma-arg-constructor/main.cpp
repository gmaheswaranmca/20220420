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
	cout << this->accountId << ") Constructor - Default" << endl;
	this->accountNumber = 0;
	strcpy(this->accountHolderName,"");
	this->balance = 0.0f;
}
Account::Account(int accountNumber, char accountHolderName[], float balance){
	Account::updateInstanceCount();
	this->accountId = Account::instanceCount;
	cout << this->accountId << ") Constructor - Parameterized" << endl;
	this->accountNumber = accountNumber;
	strcpy(this->accountHolderName,accountHolderName);
	this->balance = balance;
}
Account::Account(const Account &acc){
	Account::updateInstanceCount();
	this->accountId = Account::instanceCount;
	cout << this->accountId << ") Constructor - Copy" << endl;
	this->accountNumber = acc.accountNumber;
	strcpy(this->accountHolderName,acc.accountHolderName);
	this->balance = acc.balance;
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
    char notSetStr[] = "Not Set";
    
	Account* accountAddr = NULL;
    accountAddr = new Account(101010,notSetStr,0.01f);
	
	accountAddr->read();
	accountAddr->deposit(500);
	accountAddr->deposit(1000);
	accountAddr->deposit(500);
	accountAddr->deposit(600);
	accountAddr->withdraw(100);
	accountAddr->deposit(500);
	accountAddr->print();
    
    delete accountAddr;
    accountAddr = NULL;
    
	
	return EXIT_SUCCESS;
}