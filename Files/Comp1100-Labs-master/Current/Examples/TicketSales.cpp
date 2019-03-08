#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//Program demonstrates: for loops, arrays, accumulating and counting.
int main()
{
  const int SIZE = 10; //SIZE is the maximum number of elements
  int ticketSales[SIZE];
  string patron[SIZE];//patron name and ticket sales are called parallel arrays
  int length, totalTicketSales = 0, ctr;
  cout << fixed << setprecision(2);
  for (length = 0; length<SIZE; length++)
  {
    cout << "Enter patron name or ^Z to end: ";
    getline(cin, patron[length]);
    if (cin.eof())
    break;
    while (patron[length] == "") // ensure name entered
    {
      cout << "You must enter a patron name: ";
      getline(cin, patron[length]);
    }
    cout << "Enter # of tickets: ";
    cin >> ticketSales[length];
    while (ticketSales[length]<0 || ticketSales[length]>100 || cin.fail())
    {
      cin.clear();
      cin.ignore(80, '\n');
      cout << "Error! Ticket sales must be 0 to 100 only, re enter: ";
      cin >> ticketSales[length];
    }
    totalTicketSales += ticketSales[length]; //accumulate ticket sales
    cin.ignore(80, '\n'); //need to remove enter(\n)from input buffer (cinbefore getline();
  }
  cout << setw(20) << left << "Patron" << setw(10) << right << "Ticket Sales"
  << endl << endl;
  for (ctr = 0; ctr < length; ctr++)
  cout << left << setw(20) << patron[ctr] << setw(10)
  << right << ticketSales[ctr] << endl;
  if (length>0)
  {
    cout << "Number of Patrons =" << length << endl;
    cout << "Total ticket sales " << totalTicketSales << endl;
    cout << "Average ticket sales " << totalTicketSales / length << endl;
  }
  else
  cout << "No ticket sales" << endl;
  cout << "program ended successfully " << endl;
  system("pause");
}
