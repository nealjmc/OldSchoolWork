#include <iostream>
#include <iomanip>
using namespace std;

class Math {
  double a,b,c,d;
private:
  /* data */

public:
  void Input(){
    cout << "Enter 1st number: ";
    cin >> a;
    cout << "Enter 2nd number: ";
    cin >> b;
    cout << endl;
  }

  void Add(){
    cout << "Result = " << a+b;
  }
  void Subtract(){
    cout << "Result = " << a-b;
  }
  void Multiply(){
    cout << "Result = " << a*b;
  }
  void Divide(){
    cout << "Result = " << a/b;
  }

  void Choice(){
    char userChoice;
    cout << "1.Add" << endl;
    cout << "2.Subtract" << endl;
    cout << "3.Multiply" << endl;
    cout << "4.Divide" << endl;
    cout << "Please Enter Choice: ";
    cin >> userChoice;


    switch (userChoice) {
      case '1':
        Input();
        Add();
      break;

      case '2':
        Input();
        Subtract();
      break;

      case '3':
        Input();
        Multiply();
      break;

      case '4':
        Input();
        Divide();
      break;

      default:
      system("cls");
      Choice();
            break;
    }
  }
};

int main()
{
  Math m;
  m.Choice();
}
