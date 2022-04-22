#pragma once
namespace AirWaySpace {
	struct FullName_t {
		char firstName[250];
		char lastName[250];
	};

	extern int numberOfSeats;
	extern float fare;
	extern struct FullName_t fullName;

	void readFlightData();
}