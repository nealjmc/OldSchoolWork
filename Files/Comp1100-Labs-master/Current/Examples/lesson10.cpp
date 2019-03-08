#include <iostream>
#include <string>
using namespace std;

int main()
{
  int grade[5], length, totalCombinedGrades;

  for (length = 0; length < 5; length++) {
    cout << "Enter grade: ";
    cin >> grade[length];
    cin.ignore(80, '\n');
    totalCombinedGrades += grade[length];
    cout << endl;
  }
  int avgGrades = 0;
  avgGrades = totalCombinedGrades/length;
  cout << "Avg Grade: " << avgGrades;


}
