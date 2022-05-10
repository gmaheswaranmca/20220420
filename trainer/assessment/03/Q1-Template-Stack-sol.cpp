#define MAX_SIZE 100
#include<iostream>
#include<string>
using namespace std;

template<class T>   //T : string, char, int 
class MyStack {
private:
	T dataList[MAX_SIZE]; //dataList of type string/char/int array
	int top;
	T emptyData;          //emptyData of type string/char/int 
public:
	MyStack(T emptyData); //emptyData of type string/char/int 
	void push(T data);    //data of type string/char/int 
	T pop();              //return data of type string/char/int   
	bool isEmpty();         
	bool isFull();
};

// Define constructor 
template<class T>
MyStack<T>::MyStack(T emptyData) {//className<T>::   plus declaration
	this->top = -1;
	this->emptyData = emptyData;
}

// Define push function
template<class T>
void MyStack<T>::push(T data) {//className<T>::  plus declaration
	if (this->isFull()) {
		cout << "STACK is full." << endl;
		return;
	}

	this->top = this->top + 1;
	dataList[this->top] = data;
}

// Define pull function
template<class T>
T MyStack<T>::pop() {   //className<T>::  plus declaration
	if (this->isEmpty()) {
		cout << "STACK is empty." << endl;
		return this->emptyData;
	}
	T data = dataList[this->top]; //data of type string/int/char
	this->top = this->top - 1;
	return data;
}

template<class T>
bool MyStack<T>::isEmpty() {//className<T>::  plus declaration
	return this->top == -1;
}

template<class T>
bool MyStack<T>::isFull() {//className<T>::  plus declaration
	return this->top == (MAX_SIZE - 1);
}

template<class U, int N>        //U->string/char/int
void doProcess(U dataList[], U emptyData) {//dataList -> array of string/char/int
                                    //emptyData is of type string/char/int
	MyStack<U> mystack(emptyData);  //mystack is of type MyStack<U>         

	for (int I = 0; I < N; I++) {   //N is data received from template
		mystack.push(dataList[I]);
	}
	cout << endl << endl << "Data List from stack (LIFO) structure:" << endl;
	while (!mystack.isEmpty()) {
		U data = mystack.pop();     //data is of type U
		cout << data << endl;
	}
}

int main() {
	string names[] = { "anil", "shrikant", "subhash", "uday", "manikanta" };
	char myname[] = "maheswaran";
	float nums[] = { 10.0f,20.0f,30.0f,40.0f,50.0f };

	doProcess<string,5>(names,"");
	doProcess<char,10>(myname,' ');
	doProcess<float,5>(nums,0.0f);

	return 0;
}