//To extract each attribute of employee record in csv (comma separated value)
//Example:
//101,Maheswaran,Trainer
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
int main() {
	
	char csv[] = "101,Maheswaran,Trainer";
	char* attr;
	cout << "The csv text:";
	cout << csv << endl;

	attr = strtok(csv, ",");
	while (attr != NULL)
	{
		cout << attr << endl;
		attr = strtok(NULL, ",");
	}
	
	return EXIT_SUCCESS;
}