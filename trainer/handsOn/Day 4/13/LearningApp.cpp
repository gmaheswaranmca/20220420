#define SIZE 5
#include <iostream>

using namespace std;

int main() {
    double salary[SIZE];
    cout << "Enter salaries one by one:" << endl;
    for(int index = 0 ; index < SIZE; index++){
    	cout << "Salary at index " << index << ":";
    	cin >> salary[index];
    }
    
    cout << "Salaries:" << endl;
	for(int index = 0 ; index < SIZE; index++){
		cout << salary[index] << " ";
	}
	
	//Pointer Arithmetic version
	cout << endl << "Salaries(Pointer Arithmetic):" << endl;
	for(int index = 0 ; index < SIZE; index++){
		cout << *(salary + index) << " ";
	}
	
	cout << endl << "Reverse of Salaries:" << endl;
	for(int index = SIZE -1; index >= 0; index--){
		cout << salary[index] << " ";
	}
}		
