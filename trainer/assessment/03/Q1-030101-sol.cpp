#define MAX_SIZE 100
#include<iostream>
#include<string>
using namespace std;

class MyStack{
	private:
		char characters[MAX_SIZE];
		int top;
	public:
		MyStack();        
		void push(char ch);
		char pop();
		bool isEmpty();
		bool isFull();
};

// Define constructor 
MyStack::MyStack(){    
    this->top = -1;
}


// Define push function
void MyStack::push(char ch){ //check is stack full. if not, do push.
    //if(this->top == (MAX_SIZE - 1)){
    if(this->isFull()){
        cout << "STACK is full." << endl;
        return;
    }
    //characters[++this->top] = ch;//characters[++top] = ch;
    this->top = this->top + 1; //++this->top;
    characters[this->top] = ch;
}

// Define pop function
char MyStack::pop(){ //check is stack empty. if not, do pop.
    //if(this->top == -1){
    if(this->isEmpty()){
        cout << "STACK is empty." << endl;
        return ' ';#space char
    }
    //ch = characters[this->top--];//ch = characters[top--];
    ch = characters[this->top];
    this->top = this->top - 1; //--this->top;
    return ch;
}

bool MyStack::isEmpty(){        //returns true if stack is empty. returns false if stack is not empty.
	return this->top == -1;
}

bool MyStack::isFull(){         //returns true if stack is full. returns false if stack is not full.
	return this->top == (MAX_SIZE - 1);
}

int main(){
	string yourname;
	MyStack mystack;
	cout << "Enter your name:"; cin >> yourname;
	for(int I = 0; I < yourname.size(); I++){
		char ch = yourname[I];
		//CODE HERE call "push" function of "mystack" to add "ch" into "mystack"
        mystack.push(ch);
	}
	cout << endl << endl << "Your name from stack (LIFO) structure:" << endl;
	while(!mystack.isEmpty()){
		char ch = mystack.pop();/*CODE HERE call "pop" function to read each char from "mystack" */
		cout << ch;
	}
	return 0;
}
