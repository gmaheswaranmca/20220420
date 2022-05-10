#define MAX_SIZE 100
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyStack{
	private:
		T dataList[MAX_SIZE];
		int top;
        T emptyData;
	public:
		MyStack(T emptyData);
		void push(T data);
		T pop();
		bool isEmpty();
		bool isFull();
};

// Define constructor 
template<class T>
MyStack<T>::MyStack(T emptyData){
    this->top = -1;
    this->emptyData = emptyData;
}

// Define push function
template<class T>
void MyStack<T>::push(T data){
    if (this->isFull()) {
		cout << "STACK is full." << endl;
		return;
	}

	this->top = this->top + 1;
	dataList[this->top] = data;
}

// Define pull function
template<class T>
T MyStack<T>::pop(){
    if (this->isEmpty()) {
		cout << "STACK is empty." << endl;
		return this->emptyData;
	}
	T data = dataList[this->top];
	this->top = this->top - 1;
	return data;
}

template<class T>
bool MyStack<T>::isEmpty(){
	return this->top == -1;
}

template<class T>
bool MyStack<T>::isFull(){
	return this->top == (MAX_SIZE - 1);
}

int main(){
	int N=5;
	string names[]={"anil","shrikant","subhash","uday","manikanta"};
    
	MyStack<string> mystack;
	
	for(int I = 0; I < N; I++){
        mystack.push();
	}
	cout << endl << endl << "Names from stack (LIFO) structure:" << endl;
	while(!mystack.isEmpty()){
		string data = mystack.pop();
		cout << data << endl;
	}
	return 0;
}