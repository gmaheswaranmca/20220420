#include <iostream>
#include "AirWaySpace.h"
void flightApp(void) {
	AirWaySpace::readFlightData();
	
	std::cout << "Number of Seasts:" << AirWaySpace::numberOfSeats << std::endl;
	std::cout << "Fare:" << AirWaySpace::fare << std::endl;
	std::cout << "First Name:" << AirWaySpace::fullName.firstName << std::endl;
	std::cout << "Last Name:" << AirWaySpace::fullName.lastName << std::endl;
	std::cout << "Full Name:" << AirWaySpace::fullName.firstName << " " << AirWaySpace::fullName.lastName << std::endl;
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