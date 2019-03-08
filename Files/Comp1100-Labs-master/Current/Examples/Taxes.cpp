#include <iostream>
#include <iomanip>

using namespace std;

void taxes(){

  double taxable, taxes;
  cout << "Please type in taxable income: ";
  cin >> taxable;

  if (taxable <= 20000.0) {
    taxes = 0.02 * taxable;
  }
  else{
    taxes = 0.035 * (taxable - 20000.0) + 400.0;
  }

  cout << setiosflags(ios::fixed)
      << setiosflags(ios::showpoint)
      << setprecision(2)
      << "Taxes are $ " << taxes << endl;
}

void tempConverter()
{
  char tempType;
  double temp, fahren, celsius;

  cout << fixed << setprecision(2);
  cout << "Enter Temperature to be converted: ";
  cin >> temp;

  cout << "Enter temp type(c/f): ";
  cin >> tempType;


  if (tempType == 'f')
  {
    celsius = (5.0 / 9.0) * (temp - 32);
    cout << temp << "f -> " << celsius << "c";
  }
  else if (tempType == 'c'){
    fahren = (9.0 / 5.0) * (temp + 32);
    cout << temp << "c -> " << fahren << "f";
  }
}


int main()
{
  tempConverter();
}
