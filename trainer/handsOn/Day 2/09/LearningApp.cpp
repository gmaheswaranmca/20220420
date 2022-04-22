#include <iostream>
#define SIZE 3
using namespace std;

struct _Date_t {
	int day;
	int month;
	int year;
};
struct _Time_t {
	int hour;
	int minute;
};
typedef struct _Date_t Date_t;
typedef struct _Time_t Time_t;
struct _Flight_t {
	int flightId;
	char airlineName[256];
	char flightNumber[20];
	char source[256];
	char destination[256];
	Date_t travelDate;
	Time_t departureTime;
	Time_t arrivalTime;
	int numberOfSeats;
	float fare;
};
typedef struct _Flight_t Flight_t;
Flight_t flights[SIZE] = {
	{1,"Indico","I123","Mysore","Hydrabad",{21,4,2022},{18,00},{19,30},175,5500.0f},
	{2,"Air India","A456","Bangalore","Chennai",{21,4,2022},{20,00},{22,15},150,7000.0f},
	{3,"King Fisher","KF789","Mumbai","New Delhi",{21,4,2022},{19,00},{22,00},160,8000.0f}
};
int countTotalTickets() {
	int count = 0;
	for (int index = 0; index < SIZE; index++) {
		Flight_t& flight = flights[index];
		count = count + flight.numberOfSeats;
	}
	return count;
}
double maxIncome() {
	double total = 0;
	for (int index = 0; index < SIZE; index++) {
		Flight_t& flight = flights[index];
		total = total + (double)(flight.numberOfSeats * (double)flight.fare);
	}
	return total;
}
double avgIncome() {
	return maxIncome() / (double)countTotalTickets();
}
void printFlight() {
	for (int index = 0; index < SIZE; index++) {
		Flight_t& flight = flights[index];
		cout << "[Flight ID=" << flight.flightId << ", Airline Name=" <<
			flight.airlineName << ",Departure at=" <<
			flight.departureTime.hour << ":" << flight.departureTime.minute << "]"
			<< endl;
	}
}

int main() {
	printFlight();
	cout << "Number of Tickets to be booked is " << countTotalTickets() << endl;
	cout << "Max Income is " << maxIncome() << endl;
	cout << "Average Income is " << avgIncome() << endl;
}