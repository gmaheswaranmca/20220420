//Find frequency of characters in given string.
//And sort the characters based on frequency
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class KeyValue {
public:
	char key;
	int value;
};

class Freq {
public:
	Freq();
	KeyValue keyValues[1000];
	int count;
	void set(char key);
	void sort();
};
Freq::Freq() {
	this->count = 0;
}
void Freq::set(char key) {
	Freq& freq = *this;
	int find = -1;//is there the key, then we put the index(pos) into find
	for (int I = 0; I < freq.count; I++) {
		KeyValue& keyValue = freq.keyValues[I];
		if (keyValue.key == key) {
			find = I;
			break;
		}
	}
	if (find != -1) {//increase the freq if key already exist
		KeyValue& keyValue = freq.keyValues[find];
		keyValue.value++;
	}
	else {//add key into "Freq" container
		KeyValue& keyValue = freq.keyValues[freq.count];
		keyValue.key = key;
		keyValue.value = 1;
		freq.count++;
	}
}
void Freq::sort() {//Insertion Sort
	Freq& freq = *this;
	for (int I = 1; I < freq.count; I++) {
		KeyValue eI = freq.keyValues[I];
		int newPos = I;
		for (int J = I - 1;J >= 0 && freq.keyValues[J].value > eI.value;J--) {
			freq.keyValues[J + 1] = freq.keyValues[J];
			newPos = J;
		}
		if(newPos != I){
			freq.keyValues[newPos] = eI;
		}
	}
}
int main() {
	Freq freq;
	
	char source[1000] = "hihellohihello";//hihellohihello => h:4 i:2 e:2 l:4 o:2
	//cout << "Enter the text:"; cin >> source;

	for (int I = 0; source[I] != '\0'; I++) {
		freq.set(source[I]);
	}

	cout << "Frequencies of characters in " << source << ":" << endl;
	for (int I = 0; I < freq.count; I++) {
		KeyValue& keyValue = freq.keyValues[I];
		cout << keyValue.key << ":" << keyValue.value << endl;
	}
	freq.sort();
	cout << "Frequencies of characters in " << source << ":" << endl;
	for (int I = 0; I < freq.count; I++) {
		KeyValue& keyValue = freq.keyValues[I];
		cout << keyValue.key << ":" << keyValue.value << endl;
	}
	return EXIT_SUCCESS;
}

//Read N numbers and find occurance frequency of the numbers 
//Read N numbers and sort the numbers based on occurance frequency
//Read a string and sort the characters based on occurance frequency