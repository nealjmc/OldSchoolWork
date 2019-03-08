#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//program displays all cities whose temperatures are above average
int main()
{ //housekeeping
  const int SIZE = 100;
  int length, ctr;
  int temp[SIZE], totalTemp = 0;
  int avgTemp;
  string city[SIZE];
  ofstream fout("temperature.file");
  if (!fout.is_open())
  {
    cout << "error opening file - contact systems " << endl;
    system("pause");
    exit(-1);
  }
  for (length = 0; length < SIZE; length++) //information gathering
  {
    cout << "Enter name of city or ^Z to end: ";
    getline(cin, city[length]);
    //validate city to ensure it was entered
    if (cin.eof())
    break;
    cout << "Enter temperature: ";
    cin >> temp[length];
    //validate length to a reasonable range and check for input fail here
    totalTemp += temp[length]; //accumulate temperatures
    cin.ignore(80, '\n');
  }
  if (length == 0)
  cout << "No data entered. " << endl;
  else
  {
    avgTemp = totalTemp / length; //calc avg
    fout << setw(20) << left << "City" << setw(15) << right << "Temperature" << endl << endl;
    for (ctr = 0; ctr < length; ctr++) //print each city and temperature
    {
      fout << left << setw(20) << city[ctr] << right << setw(15) << temp[ctr];
      if (temp[ctr]>avgTemp)
      fout << "*** above average ***";
      fout << endl;
    }
    fout << endl << "Average temperature " << avgTemp << char(248) << endl;
  }
  cout << "program ended successfully " << endl;
  system("type temperature.file");
  system("pause");
}
