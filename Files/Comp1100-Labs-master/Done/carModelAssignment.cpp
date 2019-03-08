#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//Neal McAneney
/*
  Start Date 09/29/17
  End Date 09/29/17
Assignment 1
Write a program that analyzes a car’s fuel usage. The program asks the user to input the type of car (i.e. model), the
number of litres of gas in the tank, and the fuel efficiency in kilometres per litre.
Print the output similar to the following: (where the X’s represent string data and 9’s represent numeric data).
Model: XXXXXXXXXXXXXXXXXXXXXXXX
Litres per tank      Kms per litre      Price per litre        Cost per tank       Distance per tank
			999                999               999.99               999.99                    9999
*/



int main()
{
	//Declaring variables
	string carModel;
	double litresPerTank, fuelEfficiency, travelDistance, costPerTank;
	const double pricePerLitre = 109.9;
	//This is the price of gas as of: 09/29/17 - 10:51Am @ 1120 Sydenham Rd near Hwy 401 Exit 613.
	//Resource: http://www.ontariogasprices.com/Kingston/index.aspx

	//Input
	cout << "Enter you car model: ";
	getline(cin, carModel);
	cout << endl;

	cout << "Enter litres per tank: ";
	cin >> litresPerTank;
	cout << endl;

	cout << "Enter fuel efficiency(litre/100km): ";
	cin >> fuelEfficiency;
	cout << endl;

	//process
	costPerTank = (litresPerTank * pricePerLitre) / 100;
	travelDistance =(litresPerTank * 100)/ fuelEfficiency;
  
	//output
	system("cls");
	cout << "Model: " << carModel << endl << endl;

	cout << right << setw(11) << "Litres/Tank" << setw(13) << "Litre/100km" << setw(14) << "Price/Litre" << setw(12) << "Cost/Tank" << setw(20) << "Distance/tank(km)" << endl;
	cout << right << setprecision(4) << setw(11) << litresPerTank << setw(13) << fuelEfficiency << setw(14) << pricePerLitre << setw(12) << costPerTank << setw(20) << travelDistance << endl << endl;
	cout << "Program Ended Successfully " << endl;
	system("pause");

}
