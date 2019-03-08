#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//in class example: Pizza orders
int main()
{
  ///housekeeping
  int noPizzas = 0, choice;
  double price, totalPrice = 0.0;
  string pizza, customer;

  ofstream fout("pizzas.dat");
  if (!fout.is_open())
  {
    cout << "Error opening file. ";
    system("pause");
    exit(-1);
  }

  //input
  cout << "welcome to order pizza online " << endl << endl;
  cout << "1. Cheese $3.00" << endl;
  cout << "2. Meat Lovers $5.55" << endl;
  cout << "3. Feta, Black Olives $1.50" << endl << endl;
  cout << "Enter customer's name, or ctl Z at store closing: ";
  getline(cin, customer);

  while (!cin.eof())
  {
    cout << "Enter choice: ";
    cin >> choice;
    
    while (cin.fail() || choice < 1 || choice > 3)
    {
      cin.clear(); //remove bad data type
      cin.ignore(80, '\n'); //remove extra data input with bad data type
      cout << "Enter 1 to 3 only: ";
      cin >> choice;
    }

    if (choice == 1)
    {
      price = 3.00;
      pizza = "Cheese";
    }

    else if (choice == 2)
    {
      pizza = "Meat Lovers";
      price = 5.55;
    }

    else
    {
      price = 1.50;
      pizza = "Feta, Black Olives";
    }

    //processing
    noPizzas++; // count
    totalPrice += price;//accumulate
    //output
    fout << fixed << setprecision(2);
    fout << "Pizza Order Receipt for " << customer << endl << endl;
    fout << left << setw(20) << "Pizza" << right << setw(15) << "Price" << endl << endl;
    fout << left << setw(20) << pizza << right << setw(15) << price << endl;

    cout << "Enter next customer's name: ";
    cin.ignore(80, '\n');
    getline(cin, customer);
  }
  fout << endl << "Total sales $ " << totalPrice << endl;
  fout << endl << "# of Pizzas sold " << noPizzas << endl << endl;

  cout << "program ended successfully." << endl;

  system("type pizzas.dat");
  system("pause");
}
