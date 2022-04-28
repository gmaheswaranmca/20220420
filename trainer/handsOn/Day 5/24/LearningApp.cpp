//Example for strcmp strchr strstr
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
int main(){
	cout << strcmp("apple","banana") << endl;
	cout << strcmp("banana","apple") << endl;
	cout << strcmp("apple","apple") << endl;
	cout << strcmp("apple cake","apple fruit") << endl;
	cout << strncmp("apple cake","apple fruit",5) << endl;
	cout << strchr("apple cake",'p') << endl;
	cout << strrchr("apple cake",'p') << endl;
	cout << strstr("apple is a word. the word means a fruit.","word") << endl;
	return EXIT_SUCCESS;
}