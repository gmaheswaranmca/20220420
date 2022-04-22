#include <iostream>
#include "AirWaySpace.h"
#include "MyUtil.h"

namespace AirWaySpace {
	int numberOfSeats;
	float fare;
	struct FullName_t fullName;

	void readFlightData() {
		MyUtil::in::read((char*)"Enter number of seats:", numberOfSeats);
		MyUtil::in::read((char*)"Enter ticket fare:", fare);
		MyUtil::in::read((char*)"Enter First Name:", fullName.firstName);
		MyUtil::in::read((char*)"Enter Last Name:", fullName.lastName);
	}
}