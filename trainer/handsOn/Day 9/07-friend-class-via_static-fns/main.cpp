#include<iostream>
#include<cstring>
using namespace std;

class AccountNanban;
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
        friend AccountNanban;
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
class AccountNanban{
    public:
static void depositAccount(Account& ac, float amount);
static void withdrawAccount(Account& ac,float amount);
static void readAccount(Account& ac);
static void printAccount(Account& ac);
};
void AccountNanban::depositAccount(Account& ac, float amount){
	ac.balance = ac.balance + amount;
}
void AccountNanban::withdrawAccount(Account& ac,float amount){
	ac.balance = ac.balance - amount;
}

void AccountNanban::readAccount(Account& ac){
	cout << "Enter Account Details of Account ID " << ac.accountId << endl;
	cout << "Enter Account Number:"; cin >> ac.accountNumber;
	cout << "Enter Account Holder Name:"; cin >> ac.accountHolderName;
	cout << "Enter Initial Deposit:"; cin >> ac.balance;
}
void AccountNanban::printAccount(Account& ac){
	cout << "The Account Details of Account ID " << ac.accountId << endl;
	cout << "Account Number:" <<  ac.accountNumber << endl;
	cout << "Account Holder Name:" << ac.accountHolderName << endl;
	cout << "Balance:" << ac.balance << endl;
}

int main(){
    AccountNanban nanban;
	Account account;

	AccountNanban::readAccount(account);
    AccountNanban::depositAccount(account,500);
	AccountNanban::depositAccount(account,1000);
	AccountNanban::depositAccount(account,500);
	AccountNanban::depositAccount(account,600);
	AccountNanban::withdrawAccount(account,100);
	AccountNanban::depositAccount(account,500);
	AccountNanban::printAccount(account);
	
	return EXIT_SUCCESS;
}