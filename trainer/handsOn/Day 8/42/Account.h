#pragma once
class Account
{
private:
	static int objCount;
	static void updateObjCount();
	int accountId;
	int accountNumber;
	char accountHolderName[256];
	float balance;
public:
	Account();
	void read();
	void print();
	void deposit(float amount);
	void withdraw(float amount);
	~Account();
};

