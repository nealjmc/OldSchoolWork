//Neal McAneney
/*Description: A private hospital would like you to write a program to prepare a report on patient charges. The program
should prompt the user for the patient name, room type (‘P’ for private, ‘S’ for semi private, or ‘W’ for ward)
and the number of days. The program also should prompt for whether the patient will require a television in
the room. The program should continue accepting patient information until they indicate that there are no
more patients. */
//prototype
int getValidDays();
char getValidRoomType();
double determineRoomRate(char);
char getTelevisonOption();
char validateReply();
double computeCharge(double, int, char, char);
double accumulateCharges(double);

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//housekeeping
	int roomDays;
	char roomType, userReply;
	double roomRate, roomCharge, totalRoomCharges = 0;
	string patientName, fullRoomType;

	ofstream fout("charges.dat");
	if (!fout.is_open()) {
		cout << "Error opening file. Check current directory." << endl;
		cout << "Now crashing." << endl;
		system("pause");
		exit(-1);
	}

	fout << setw(42) << "CPA Private Hospital Room Charge" << endl;
	fout << fixed << setprecision(2) << setw(36) << "*********************" << endl;
	fout << endl << left << setw(14) << "Patient Name" << setw(13) << "Room Type" <<
	right << setw(10) << "# of Days" << setw(17) << "Room Charge" << endl << endl;

	do{
		cout << "Enter patient name:";
		getline(cin, patientName);
		while (patientName.length() < 2) {
			cout << "Error, name too short." << endl;
			cout << "Enter patient name: ";
			getline(cin, patientName);
		}

		roomType = getValidRoomType();
		roomDays = getValidDays();
		roomRate = determineRoomRate(roomType);

		cout << "Does the user require a television(y/n): ";
		cin >> userReply;
		cin.ignore(80,'\n');

		userReply = validateReply(userReply);
		roomCharge = computeCharge(roomRate, roomDays, userReply, roomType);
		totalRoomCharges += accumulateCharges(roomCharge);
		switch (roomType)
		{
			case 'P':
			fullRoomType = "Private";
			break;
			case 'S':
			fullRoomType = "Semi-Private";
			break;
			default:
			fullRoomType = "Ward";
		}

		fout << left << setw(14) << patientName << setw(13) << fullRoomType <<
		right << setw(10) << roomDays << setw(17) <<  roomCharge << endl;

		cout << "Would you like to enter another patient(y/n): ";
		cin >> userReply;
		userReply = toupper(userReply);
		cin.ignore(80,'\n');
		userReply = validateReply(userReply);
	}while(userReply != 'N');

	fout << endl << "Total charges" << setw(41) << totalRoomCharges << endl;
	system("type charges.dat");
	system("pause");
}

int getValidDays() {
	int numbDays = 0;
	cout << "Enter number of days(1-10): ";
	cin >> numbDays;
	while (numbDays > 10 || numbDays < 1 || cin.fail()) {
		cout << "Error. Invalid input." << endl;
		cout << "Enter number of days(1-10): ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> numbDays;
	}
	return numbDays;
}
char getValidRoomType() {
	char roomType;
	cout << "Enter room type(P,S,W): ";
	cin >> roomType;
	roomType = toupper(roomType);
	while (cin.fail() || roomType != 'P' && roomType != 'S' && roomType != 'W') {
		cout << "Error. Invalid input. " << endl;
		cout << "Enter room type(P,S,W): ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> roomType;
		roomType = toupper(roomType);
	}
	return roomType;
}
double determineRoomRate(char roomType) {
	double roomRate;

	switch (roomType) {
		case 'P':
		roomRate = 1000.0;
		break;
		case 'S':
		roomRate = 750.0;
		break;
		default:
		roomRate = 500.0;
		break;
	}
	return roomRate;
}
char getTelevisonOption() {
	char response;
	cout << "Does the patient require a television(y/n): ";
	cin >> response;
	cin.ignore(80, '\n');
	return response;
}
char validateReply(char reply) {
	char finalReply = ' ';
	reply = toupper(reply);
	while (reply != 'Y' && reply != 'N') {
		cout << "Error. Invalid input." << endl;
		cout << "Re-Enter(y/n): ";
		cin >> reply;
		cin.ignore(80, '\n');
		reply = toupper(reply);
	}
	finalReply = toupper(reply);
	return finalReply;
}
double computeCharge(double rate, int days, char reply, char type) {
	double charge = 0;
	charge += (rate * days);
	if (reply == 'Y' && type != 'W') {
		charge += (days * 25.00);
	}
	return charge;
}
double accumulateCharges(double roomCharge) {
	double totalCharges = 0;
	totalCharges += roomCharge;
	return totalCharges;
}
