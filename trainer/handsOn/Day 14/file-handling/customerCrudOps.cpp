#define _CRT_SECURE_NO_WARNINGS
//CRUD operations - Create			Read			Update				Delete
//Binary File		Add Customer	Get Customer	Modify Customer		Purge/Remove the Customer
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;


class Customer {
	public:
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
	void update(char username[], float amount);
	void update_v2(char username[], float amount);
	void remove(Customer& cust, char username[]);
	void read(Customer& cust, char username[]);
	void readAll(Customer cust[], int& count);
};
int CustomerDao::findIndex(char username[]) {
	int index = -1;
	int I = 0;

	fstream input;
	input.open(this->fileLoc + this->fileName, ios::in | ios::binary);
	if (input.is_open()) {
		Customer temp;
		while (input.read((char*)&temp, sizeof(Customer))) {			
			if (strcmp(temp.username, username)==0) {
				index = I;
				break;
			}
			I++;
		}
	}
	input.close();

	return index;
}
void CustomerDao::create(Customer& cust) {
	fstream output;
	output.open(this->fileLoc + this->fileName, ios::out | ios::binary | ios::app);
	if (output.is_open()) {
		output.write((char*)&cust, sizeof(Customer));
	}
	output.close();
}
void CustomerDao::update(char username[], float amount) {
	int index = this->findIndex(username);//object index
	int byteIndex = index * sizeof(Customer); //0*264 | 1*264 | 2*264
											  //0	  |  264  |  528
	
	fstream inout;
	inout.open(this->fileLoc + this->fileName, ios::in | ios::out | ios::binary);
	if (inout.is_open()) {
		inout.seekg(byteIndex, ios::beg);
		Customer temp;
		inout.read((char*)&temp, sizeof(Customer));
		//Before Update
		temp.bankBalance += amount;
		inout.seekg(byteIndex, ios::beg);
		inout.write((char*)&temp, sizeof(Customer));
		//After Update 
	}
	inout.close();
}

void CustomerDao::update_v2(char username[], float amount) {
	int index = -1;
	int I = 0;
	int byteIndex = 0;

	fstream inout;
	inout.open(this->fileLoc + this->fileName, ios::in | ios::out | ios::binary);
	Customer temp;
	if (inout.is_open()) {
		while (inout.read((char*)&temp, sizeof(Customer))) {
			if (strcmp(temp.username, username) == 0) {
				index = I;
				break;
			}
			I++;
		}
		byteIndex = index * sizeof(Customer);
		//Before Update
		temp.bankBalance += amount;
		inout.seekg(byteIndex, ios::beg);
		inout.write((char*)&temp, sizeof(Customer));
		//After Update 
	}
	inout.close();
}
void CustomerDao::remove(Customer& cust, char username[]) {

}
void CustomerDao::read(Customer& cust, char username[]) {

}
void CustomerDao::readAll(Customer cust[], int& count) {
	int I = 0;

	fstream input;
	input.open(this->fileLoc + this->fileName, ios::in | ios::binary);
	if (input.is_open()) {
		Customer temp;
		while (input.read((char*)&temp, sizeof(Customer))) {
			cust[I] = temp;
			I++;
		}
	}
	input.close();

	count = I;
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
		cout << "3: Find Index" << endl;
		cout << "4: Deposit Amount" << endl;
		cout << "5: Withdraw Amount" << endl;
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
		else if (3 == menu) {
			char search_username[256];
			cout << "Enter Username to search:"; cin >> search_username;
			int index = dao.findIndex(search_username);
			cout << endl << "The customer is at index " << index << endl;
		}
		else if (4 == menu || 5 == menu) {
			char search_username[256];
			cout << "Enter Username to search:"; cin >> search_username;
			int amount;
			switch (menu) {
			case 4:
				cout << "Deposit amount:"; cin >> amount;
				dao.update(search_username, amount);
				break;
			case 5:
				cout << "Withdrawal amount:"; cin >> amount;
				dao.update(search_username, -amount);
				break;
			}
			
			
			cout << "Transaction has done successfully." << endl;
			cout << "Press Enter to continue..."; cin.ignore(80, '\n');
			cout << endl;
		}
		
		
	} while (menu != 0);
	return 0;
}

