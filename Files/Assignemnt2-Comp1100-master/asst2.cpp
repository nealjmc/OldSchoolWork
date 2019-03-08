#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
// Neal McAneney
/* This programs prompts the user to enter a name(string), liters of gas(int), and a gas type(char).
Based on user input, the program will output various results and calculate totals.*/

using namespace std;
int main()
{
  //housekeeping
  // Declare all variables, open files, set output rules, print report titles
  int numCustomer = 0;
  string customerName = "";
  char gasType = ' ';
  string gasTypeFull = "";
  double litresOfGas = 0.0,
  salesAmountTotal = 0.0,
  salesOverAll = 0.0,
  salesAverage = 0.0,
  pricePerLitre = 0.0;

  ofstream gasRpt("gas.rpt");
  if (!gasRpt.is_open()) {
    cout << "Error creating file. Check directory.";
    system("pause");
    exit(-1);
  }

  cout << fixed << setprecision(2);
  gasRpt << fixed << setprecision(2);

  // Customer Name      Type of Gasoline      # of Litres       Sales Amount
  gasRpt << setw(18) << left << "Customer Name"
  << setw(16) << left << "Type of Gasoline"
  << setw(15) << right << "Price/Litre"
  << setw(15) << "# Of Litres"
  << setw(16) << "Sales Amount" << "\n";


  //input
  // Obtain prime read
  // Begin a while loop to process numerous data
  // Obtain and validate more data
  cout << "Enter customer's name (or ctrl Z to end) ";
  getline(cin,customerName);
  while(!cin.eof()){
    while(customerName == ""){
      cout << "Error. Failed input." << endl;
      cout << "Enter your name: ";
      getline(cin,customerName);
    }

    cout << "Enter number of litres ";
    cin >> litresOfGas;
    while(litresOfGas < 1 || litresOfGas > 100 || cin.fail()){
      cin.clear();
      cin.ignore(80,'\n');
      cout << "Error. Failed input. Limit litres to 1-100." << endl;
      cout << "Enter litres of gas: ";
      cin >> litresOfGas;
    }

    cout << "Enter type of gasoline (R)egular ,(D)iesel or P(ropane): ";
    cin >> gasType;
    gasType = toupper(gasType);
    //processing & validation
    while(cin.fail() || gasType != 'R' && gasType != 'D' && gasType != 'P'){
      cin.clear();
      cin.ignore(80,'\n');
      cout << "Error. Failed Input." << endl;
      cout << "Enter type of gasoline (R)egular ,(D)iesel or P(ropane): ";
      cin >> gasType;
      gasType = toupper(gasType);
    }

    // Code nested if, arithmetic, counting and accumulating
    if (gasType == 'R') {
      gasTypeFull = "Regular";
      pricePerLitre = 1.28;
      salesAmountTotal =  litresOfGas * pricePerLitre;
    }
    else if (gasType == 'P'){
      gasTypeFull = "Propane";
      pricePerLitre = 2.50;
      salesAmountTotal = litresOfGas * pricePerLitre;
    }
    else{
      gasTypeFull = "Diesel";
      pricePerLitre = 1.08;
      salesAmountTotal = litresOfGas * pricePerLitre;
    }
    //output
    // Print data to the file
    gasRpt << setw(18) << left << customerName
    << setw(16) << gasTypeFull
    << setw(15) << right << pricePerLitre << setprecision(1)
    << setw(15) << litresOfGas << setprecision(2)
    << setw(16) << salesAmountTotal;
    numCustomer++;
    //Division by zero check, even though it should never happen
    if (numCustomer != 0) {
      salesOverAll += salesAmountTotal;
      salesAverage = salesOverAll/numCustomer;
    }
    else{
      cout << "Error. Division by 0. Crashing."<< endl;
      system("pause");
      exit(-1);
    }
    // Print and calculate final results
    cin.clear();
    cin.ignore(80,'\n');
    cout << "Enter customer's name (or ctrl Z to end) ";
    getline(cin,customerName);
  }
  //Adds totals and average at bottom of gasRpt
  gasRpt << endl << left
  << setw(16) << "Total Sales"
  << setw(64) << right << salesOverAll << left
  << setw(16) << "Average Sales"
  << setw(64) << right << salesAverage << endl;
  //Checks if exit on first input
  if (numCustomer == 0) {
    cout << "Program ended by user. No result." << endl;
    system("pause");
    exit(-1);
  }
  cout << "Program ended successfully" << endl;
  //  Print data file
  system("type gas.rpt");
  system("pause");
}
  
 /*Example output from gasRpt*/

// Enter customer's name (or ctrl Z to end) Neal
// Enter number of litres 23
// Enter type of gasoline (R)egular ,(D)iesel or P(ropane): r
// Enter customer's name (or ctrl Z to end) Olivier
// Enter number of litres 43
// Enter type of gasoline (R)egular ,(D)iesel or P(ropane): d
// Enter customer's name (or ctrl Z to end) David
// Enter number of litres 34
// Enter type of gasoline (R)egular ,(D)iesel or P(ropane): p
// Enter customer's name (or ctrl Z to end) ^Z
// Program ended successfully
// Customer Name     Type of Gasoline    Price/Litre    # Of Litres    Sales Amoun
//
// Neal              Regular                    1.28           23.0           29.4
// Olivier           Diesel                     1.08           43.0           46.4
// David             Propane                    2.50           34.0           85.0
//
// Total Sales                                                               160.8
// Average Sales                                                              53.6
//
// Press any key to continue . . .
//
