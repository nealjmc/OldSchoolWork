#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**********************************************************
Lab Exercise #4:  Correct the syntax and run time errors

This program calculates and prints an employee's pay.

Help:  First, before trying to run the program, try to find
and correct as many errors as you can.

Hint: This program appears all green. Which means it is a comment.
You'll need to end the comment. C++ is case sensitive.
Don't forget the header files! Next, try running the program.
Click on View>Error List and work  through each error from the first one down.
After you have corrected the errors, run it again.
Compare the answer calculated by the computer with a calculator.

Hint: all programs follow input-process-output order.
If you still canâ€™t find all of the errors, compare the code
to a program that works. Often itâ€™s the smallest errors that are missed.
******************************************************************/

int main()
{
  //housekeeping
  cout << fixed << setprecision(2);

  const double PAYRATE=15.50;

  string employeeName="Robert Goulet";
  int employeeHours;
  double totalPay;
  char dept = 'A';

  //input
  employeeHours=44;
  dept='A';

  //processing
  totalPay = employeeHours * PAYRATE;


  //output
  cout << left << setw(20) << "Name  " << left << setw(15) << "Department " << setw(10) << right << "Pay " << endl << endl;
  cout << left << setw(20) << employeeName << left << setw(14) << dept << setw(10) << right << totalPay << endl <<endl;

  cout << "Program ended successfully" << endl;
  system("pause");

}
