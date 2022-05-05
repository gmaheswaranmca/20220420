#define _CRT_SECURE_NO_WARNINGS
//#include"Wallet.h"
#include<iostream>
#include<string>
using namespace std;

class ShopDb
{
public:
	static int lastWalletId;
};
int ShopDb::lastWalletId = 102000;
class Wallet
{
private:
	int walletId;
	string subscriber;
	string phoneNumber;
	string player;
	float walletBalance;
public:
	Wallet();
	Wallet(int walletId, string subscriber, string phoneNumber,
		string player, float walletBalance);
	void read();
	void print();
	void doTopup(float amount);
	void updatePlay(float amount);
};

Wallet::Wallet() {
	this->walletId = 0;
	this->subscriber = "";
	this->phoneNumber = "";
	this->player = "";
	this->walletBalance = 0.0f;
}
Wallet::Wallet(int walletId, string subscriber, string phoneNumber,
	string player, float walletBalance) {
	this->walletId = walletId;
	this->subscriber = subscriber;
	this->phoneNumber = phoneNumber;
	this->player = player;
	this->walletBalance = walletBalance;
}
void Wallet::read() {
	ShopDb::lastWalletId++;
	this->walletId = ShopDb::lastWalletId;

	cout << "Enter Subscriber Name :";
	cin >> this->subscriber;
	cout << "Enter Phone Number :";
	cin >> this->phoneNumber;
	cout << "Enter Player Name :";
	cin >> this->player;
	this->walletBalance = 1000;
	cout << "Subscription Charge : Rs" << this->walletBalance << endl << endl;

	//cout << "Are you sure to subscribe(y / n) ?:";

	cout << "You are subscribed to our Game Shop!!!!" << endl;
	cout << "Your wallet id is " << this->walletId << endl << endl;
}
void Wallet::print() {
	cout << "Subscriber:" << this->subscriber << endl;
	cout << "Phone Number:" << this->phoneNumber << endl;
	cout << "Player:" << this->player << endl;
	cout << "Wallet Balance:" << this->walletBalance << endl;
}
void Wallet::doTopup(float amount) {
	cout << "Topup yet to be done" << endl << endl;
}
void Wallet::updatePlay(float amount) {
	cout << "Update play yet to be done" << endl << endl;
}
int main() {
	Wallet wallet;

	wallet.read();

	wallet.doTopup(1000);
	wallet.updatePlay(300);

	cout << "The details of wallet is " << endl;
	wallet.print();

	return EXIT_SUCCESS;
}