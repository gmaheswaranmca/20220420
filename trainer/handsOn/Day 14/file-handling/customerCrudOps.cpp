#define _CRT_SECURE_NO_WARNINGS
//CRUD operations - Create Read Update Delete
//Binary File
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;


class Customer {
	private:
		char username[256];
		int id;
		float bankBalance;	//264
	public:
		Customer();
		Customer(char username[], int id, float bankBalance);
		void read();
		void print();
};
Customer::Customer() {
	strcpy(this->username, "");
	this->id = 0;
	this->bankBalance = 0.0f;
}
Customer::Customer(char username[], int id, float bankBalance) {
	strcpy(this->username, username);
	this->id = id;
	this->bankBalance = bankBalance;
}
void Customer::read() {
	cout << "ID:"; cin >> this->id;
	cout << "Username:"; cin >> this->username;
	cout << "Bank Balance:"; cin >> this->bankBalance;
}
void Customer::print() {
	cout << "[" << this->id << "," << this->username << "," << this->bankBalance << "]" << endl;
}

class CustomerDao {
private:
	const string fileLoc = "E:/work/jobs/20220420/day_wise/filedb";
	const string fileName = "/customerdb.dat";
public:
	int findIndex(char username[]);
	void create(Customer& cust);
	void update(Customer& cust, char username[]);
	void remove(Customer& cust, char username[]);
	void read(Customer& cust, char username[]);
	void readAll(Customer cust[], int& count);
};
int CustomerDao::findIndex(char username[]) {
	return -1;
}
void CustomerDao::create(Customer& cust) {
	fstream output;
	output.open(this->fileLoc + this->fileName, ios::out | ios::binary | ios::app);
	if (output.is_open()) {
		output.write((char*)&cust, sizeof(Customer));
	}
	output.close();
}
void CustomerDao::update(Customer& cust, char username[]) {

}
void CustomerDao::remove(Customer& cust, char username[]) {

}
void CustomerDao::read(Customer& cust, char username[]) {

}
void CustomerDao::readAll(Customer cust[], int& count) {
	fstream input;
	input.open(this->fileLoc + this->fileName, ios::in || ios::binary);
	if (input.is_open()) {
		count = 0;
		Customer temp;
		while (input.read((char*)&temp, sizeof(Customer))) {
			cust[count] = temp;
			count++;
		}
	}
	input.close();
}


int main()
{	
	Customer cust;
	Customer customers[2000];
	int custCount;
	CustomerDao dao;

	int menu;
	do {
		cout << "1: Write" << endl;
		cout << "2: Read All" << endl;
		cout << "0: Exit" << endl;
		cout << "Your Option:"; cin >> menu;

		if (1 == menu) {
			cout << endl << endl << "Enter customer details:" << endl;
			cust.read();
			dao.create(cust);
		}
		else if (2 == menu){
			dao.readAll(customers, custCount);
			cout << endl << endl << "The customers db:" << endl ;
			for (int I = 0;I < custCount;I++) {
				customers[I].print();
			}
		}
	} while (menu != 0);
	return 0;
}
