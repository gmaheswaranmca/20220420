//Count frequency of characters in given string.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

struct KeyValue {
	char key;
	int value;
};

struct Freq {
	KeyValue keyValues[1000];
	int count;
};

void setKeyValue(Freq& freq, char key) {
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

int main() {
	//Freq freq = { .count = 0 };
	Freq freq;
	freq.count = 0;
	char source[1000];//hihellohihello => h:4 i:2 e:2 l:4 o:2
	cout << "Enter the text:"; cin >> source;
	
	for (int I = 0; source[I] != '\0'; I++) {
		setKeyValue(freq, source[I]);
	}

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