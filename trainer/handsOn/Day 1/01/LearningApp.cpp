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

int main()
{
	flightApp();
	return 0;
}