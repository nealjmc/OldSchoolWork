#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//add required header file for files
using namespace std;
//Name: Neal McAneney
//Lab Ex#5: pgm computes expenses and writes them to a file
void output()
{

}
int main()
{
  //housekeeping
  const double ROOM_RATE = 350.00;
  string city, item;
  double balance, cost, mealCost, expenses;
  int numberDays;
  ofstream afile("output.txt");
  ifstream bfile("output.txt");
  afile << fixed << setprecision(2);
  //add the code to open a file for output and set output rules

  //input
  cout << "Enter the name of a city: ";
  getline(cin, city);

  cout << "Enter a noun: ";
  getline(cin,item);

  cout << "Enter a dollar amount: ";
  cin >> balance;

  cout << "Enter a positive number: ";
  cin >> numberDays;

  cout << "Enter a real number: ";
  cin >> cost;

  cout << "Enter a second real number: ";
  cin >> mealCost;

  //processing
  //calculate expenses by multiplying the room rate by the number of days + cost + mealCost,
  expenses = (ROOM_RATE * numberDays) + cost + mealCost;

  //subtract the expenses from the balances
  balance -= expenses;

  //output
  // add the code to change cout to the output file name
  if (afile.is_open()) {
    afile << endl;
    afile << "During a " << numberDays << " day vacation to " << city;
    afile << ". You book accommodations at the Marriott Resort and Spa at a cost of $"
    << ROOM_RATE << " per night " << endl;
    afile << "While on vacation, you decide to go shopping for a(n) " << item
    << " that costs $ " << cost << endl;
    afile << "Feeling tired from shopping, you decide to order room service and charged $ "
    << mealCost << endl << endl;
    afile << "Your vacation expenses are summarized below." << endl << endl;
    /*add formatting to print string data left justified in a column width of 25 and
    numeric data right justified in a column width of 10*/
    afile << "Total vacation expenses: " << expenses << endl;
    afile << "Amount of money remaining: " << balance << endl;
    afile.close();
    cout << endl << "Program ended successfully." << endl;
  }
  else{
    cout << "Connection to file failed." << endl;
  }
  system("pause");
  system("cls");
  system("type output.txt");

  //Run the program, did the balance appear on the output file
  // copy the output file to the I/O dialogue

}
