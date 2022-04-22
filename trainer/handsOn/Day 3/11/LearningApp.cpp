/*
#include <iostream>
using namespace std;


void read(char* caption, int& data) {
	std::cout << caption;
	std::cin >> data;
}
void read(char* caption, float& data) {
	std::cout << caption;
	std::cin >> data;
}
void read(char* caption, char* data) {
	std::cout << caption;
	std::cin >> data;
}
int main()
{
int x=0; read((char*)"Enter number:",x);
float y=0.0f; read((char*)"Enter number:",y);
char z[256]=""; read((char*)"Enter text:",z);
}

//===>

*/

#include <iostream>
using namespace std;

template<class T>
void read(char* caption, T data) {
	std::cout << caption;
	std::cin >> data;
}
int main()
{
	int x=0; read<int&>((char*)"Enter number:", x);
	float y=0.0f; read<float&>((char*)"Enter number:", y);
	char z[256]; read<char*>((char*)"Enter text:", z);
}