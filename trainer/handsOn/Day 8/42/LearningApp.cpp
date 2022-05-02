#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Account.h"

void doProcess(Account& account) {
	account.read();

	account.deposit(500);
	account.deposit(1500);
	account.deposit(500);
	account.deposit(2000);
	account.withdraw(100);
	account.deposit(300); //4700+1000=5700

	account.print();
}

int main() {
	Account acMani;
	doProcess(acMani);

	Account acAnil;
	Account acUdai;
		
	doProcess(acAnil);
	doProcess(acUdai);


	return EXIT_SUCCESS;
}