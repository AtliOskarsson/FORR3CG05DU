#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class FlightBooking{
public:
	FlightBooking();
	FlightBooking(int id, int capacity, int reserved);
	~FlightBooking();
	void printStatus();
	void add(int);
	void cancel(int);
	int id;
	int capacity;
	int reserved;

private:
	int getFillLevel();
};

void FlightBooking::printStatus()
{
	cout << "Flight: " << id << " " << reserved << "/" << capacity << " (" << getFillLevel() << "%) seats reserved" << endl;
}

FlightBooking::FlightBooking(){
	this->id = 0;
	this->capacity = 0;
	this->reserved = 0;
}


FlightBooking::FlightBooking(int id, int capacity, int reserved = 0){
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

FlightBooking::~FlightBooking(){
}

int FlightBooking::getFillLevel() {
	return 100 * reserved / capacity;
}

void FlightBooking::add(int addition) {
	reserved += addition;
}

void FlightBooking::cancel(int deletion){
	if (deletion < 0) {
		deletion = deletion*-1;
	}
	reserved -= deletion;
}

class FlightList {
	private:
		FlightBooking *listi;
		int naesti_lausi;
		int staerd;
	public:
		FlightList() {
			this->staerd = 4;
			listi = new FlightBooking[staerd];
			int naesti_lausi = 0;
		}

		void setjaILista(FlightBooking b) {
			if (naesti_lausi < staerd) {
				listi[naesti_lausi] = b;
				naesti_lausi++;
			}
			else{
				FlightBooking *temp = new FlightBooking[staerd * 2];
				for (int i = 0; i < staerd; i++) {
					temp[i] = listi[i];
				}
				cout << "HER" << endl;
				delete[] listi;
				listi = temp;
				listi[naesti_lausi++] = b;
				staerd *= 2;
			}
		}

		void prentaLista() {
			for (int i = 0; i < naesti_lausi; i++) {
				this->listi[i].printStatus();
			}
		}

		void addFlight(int id, int reserverd) {
			for (int i = 0; i < naesti_lausi; i++) {
				//this->listi[i].printStatus();
				if (listi[i].id == id) {
					listi[i].add(reserverd);
				}

			}
		}
};

int main()
{
	/*int flightID;
	int flightReserved;
	int flightCapacity;

	cout << "Flight ID: ";
	cin >> flightID;
	cout << "Reserved seats: ";
	cin >> flightReserved;
	cout << "Flight Capacity: ";
	cin >> flightCapacity;


	FlightBooking booking = FlightBooking(flightID, flightCapacity, flightReserved);
	booking.printStatus();
	booking.add(5);
	booking.printStatus();
	booking.cancel(5);
	booking.printStatus();*/

	FlightBooking flights[3];
	//cout << sizeof(flights)/sizeof(*flights) << endl;

	FlightList l = FlightList();

	int loop = 1;
	string command;
	
	int id, size;



	while (command != "quit"){
		cout << "Command: ";
		stringstream ss;
		getline(cin, command);

		ss << command;
		ss >> command >> id >> size;
		//cout << command << " - " << id << " - " << size << endl;

		

		if (command == "create") {
			///*cout << "creating flight " << id << endl;
			//int check = 0;
			//for (int i = 0; i < sizeof(flights) / sizeof(*flights); i++){
			//	if (flights[i].id == null || flights[i].id < 0 && check == 0){
			//		flightbooking b = flightbooking(id, size, 0);
			//		flightlist().setjailista(b);
			//		flights[i] = b;
			//		check = 1;
			//		cout << "created flight " << id << endl;
			//		flights[i].printstatus();
			//	}
			//	else if (flights[i].id != null) {
			//		if (id == flights[i].id) {
			//			cout << "flight already exists " << id << endl;
			//			check = 1;
			//		}
			//	}
			//}
			//cout << endl;*/
			FlightBooking b = FlightBooking(id, size);
			l.setjaILista(b);

		}
		else if (command == "add") {
			//for (int i = 0; i < sizeof(flights) / sizeof(*flights); i++){
			//	if (flights[i].id == id){
			//		flights[i].reserved += size;
			//	}
			//}
			l.addFlight(id, size);


		}
		else if (command == "delete") {
			cout << "Deleting flight " << id << endl;
			for (int i = 0; i < sizeof(flights) / sizeof(*flights); i++){
				if (flights[i].id == id){
					flights[i].id = -1;
				}
			}

		}
		else if (command == "cancel") {
			cout << "canceling " << size << " reservations from flight " << id << endl;
			for (int i = 0; i < sizeof(flights) / sizeof(*flights); i++){
				if (flights[i].id == id){
					
				}
			}
		}
		else if (command == "print"){
			//for (int i = 0; i < sizeof(flights) / sizeof(*flights); i++){
			//	if (flights[i].id != NULL){
			//		flights[i].printStatus();
			//	}
			//	else {
			//		cout << "Empty" << endl;
			//	}
			//}
			l.prentaLista();
		}
		else if (command == "quit") {
			break;
		}
		else {
			cout << "Invalid operation." << endl;
		}


	}



	return 0;
}