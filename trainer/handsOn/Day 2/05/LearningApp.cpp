#include <iostream>
#include "AirWaySpace.h"
#include "EPMSSpace.h"
#include "MyUtil.h"

void flightApp(void) {
	AirWaySpace::readFlightData();
	
    MyUtil::out::print((char*)"Number of Seasts:", AirWaySpace::numberOfSeats);
	MyUtil::out::print((char*)"Fare:", AirWaySpace::fare);
	MyUtil::out::print((char*)"First Name:", AirWaySpace::fullName.firstName);
	MyUtil::out::print((char*)"Last Name:", AirWaySpace::fullName.lastName);
}

void empApp(void) {
	using namespace EPMSSpace;

	readEmp();
	printEmp();
}

int main()
{
    int choice = 0;
	
    do {
		std::cout << "Enter Choice (1-Flight App, 2-Emp App, 0-Exit):";
		std::cin >> choice;

		if (choice == 1) {
			flightApp();
		}
		else if (choice == 2) {
			empApp();
		}
		else if (choice == 0) {
			std::cout << "Hard Exit";
			break;
		}
		else {
			std::cout << "Wrong Choice";
		}
	} while (1 <= choice && choice <= 2);
    
	return 0;
}