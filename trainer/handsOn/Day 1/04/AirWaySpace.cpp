#include <iostream>
#include "AirWaySpace.h"


namespace AirWaySpace {
	int numberOfSeats;
	float fare;
	struct FullName_t fullName;

	void readFlightData() {
		std::cout << "Enter number of seats:";
		std::cin >> numberOfSeats;

		std::cout << "Enter ticket fare:";
		std::cin >> fare;

		std::cout << "Enter First Name:";
		std::cin >> fullName.firstName;

		std::cout << "Enter Last Name:";
		std::cin >> fullName.lastName;
	}
}