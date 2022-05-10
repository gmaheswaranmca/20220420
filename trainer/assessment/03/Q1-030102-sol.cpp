#define MAX_SIZE 100
#include<iostream>
#include<string>
using namespace std;

class MyStack{
	private:
		string names[MAX_SIZE];
		int top;
	public:
		MyStack();
		void push(string name);
		string pop();
		bool isEmpty();
		bool isFull();
};

// Define constructor 
MyStack::MyStack(){
    this->top = -1;
}

// Define push function
void MyStack::push(string name){
    if (this->isFull()) {
		cout << "STACK is full." << endl;
		return;
	}

	this->top = this->top + 1;
	names[this->top] = name;
}

// Define pull function
string MyStack::pop(){
    if (this->isEmpty()) {
		cout << "STACK is empty." << endl;
		return "";//no-space empty string
	}
	string name = names[this->top];
	this->top = this->top - 1;
	return name;
}

bool MyStack::isEmpty(){
	return this->top == -1;
}

bool MyStack::isFull(){
	return this->top == (MAX_SIZE - 1);
}

int main(){
	int N;
	string names[MAX_SIZE];
	MyStack mystack;
	
	cout << "Enter number of names:"; cin >> N;
	
	for(int I = 0; I < N; I++){
		cout << "Enter name:"; cin >> names[I];
	}
	
	for(int I = 0; I < N; I++){
		//call "push" function of "mystack" to add each name of "names" array into "mystack"
        mystack.push();
	}
	cout << endl << endl << "Names from stack (LIFO) structure:" << endl;
	while(!mystack.isEmpty()){
		string name = mystack.pop();/* call "pop" function to read each char from "mystack" */
		cout << name << endl;
	}
	return 0;
}