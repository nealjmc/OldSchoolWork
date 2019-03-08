#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//show cin.eof and find highest bid (silent auction)
int main()
{
  string item;
  double bidAmt, bidHighest;
  int noBids=0;
  ofstream fout("auction.dat");

  if (!fout.is_open())
  {
    cout << "Error opening file. ";
    system("pause");
    exit(-1);
  }

  fout << fixed << setprecision(2);

  cout << "Enter: item to bid on: ";
  getline(cin,item);

  cout << "Enter bid amount, or ctrl Z when done: ";
  cin >> bidAmt;

  bidHighest = bidAmt;
  while (!cin.eof())
  {
    if (bidAmt > bidHighest)
    bidHighest = bidAmt;
    noBids++;

    cout << "Enter bid amount, or ctrl Z when done: ";
    cin >> bidAmt;
  }

  if (noBids>0)
  {
    fout << "\n" << item << " Sold for $ " << bidHighest << endl;
    fout << "Number of bids for this item: " << noBids << endl;
  }

  cout << "\nAuction has closed. " << endl;

  system("type auction.dat");
  system("pause");
}
