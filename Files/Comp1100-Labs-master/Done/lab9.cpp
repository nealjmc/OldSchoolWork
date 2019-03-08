#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int main()
{
	int number, ctr, countdown;
	ctr = 1;
	system("color 5F");

	// #1 Rewrite the following while loop using a for loop.
	//    It currently prints 1 2 3 Go!

	// ctr=1;
	// while (ctr < 4)
	// {
	//   cout << ctr << " ";
	//   ctr++;
	// }
	for (int i = 1; i < 4; i++) {
		cout << i << " ";
	}
	cout << "Go!" << endl;
	system("pause");



	// #2 Print your name 10 times.
	//    Each name should appear on a line by itself.
	for (int i = 0; i < 10; i++) {
		cout << i << " - Neal" << endl;
	}
	system("pause");


	// #3  Print the ascii values.
	//     What is an upper case A?
	cout << "Upper case letter a: " << char(65) << endl;
	//     What is a lower case a?
	cout << "Lower case letter a: " << char(97) << endl;
	system("pause");

	for (ctr = 0; ctr <= 244; ctr++)
	{
		cout << ctr << " = " << char(ctr) << endl;
	}
	cout << endl << endl;
	system("pause");

	// #4  Print todays temperature using degrees symbol
	cout << "Todays temperature is 4" << char(248) << ", and feels like 0" << char(248) << endl;

	// #5  Use a for loop to print a 5 asterisks (do not use *)
	//     values across the screen
	for (int i = 0; i < 4; i++) {
		cout << char(42) << " ";
	}
	cout << endl;
	system("pause");
	cout << endl;


	// #6 Complete the following loop that counts backwards
	//    from 10 to 0

	/*   for (countdown=___; countdown___;countdown___)
	{
	cout << ctr << " "   // why doesn't it print 10 9 8 etc?
	<< char(7);
	Sleep(240);  //wait a couple of seconds
  }
  */
	for (int i = 10; i > 0; i--) {
		cout << i << endl << char(7);
		Sleep(240);
	}
	cout << "Blast off!" << endl << endl;
	system("pause");
	//  cout << "Blast off!" << endl << endl;

	// #7 Complete the following loop instructions that will
	//    print the odd numbers from 1 to 20

	//  cout << "Odd numbers are: " << endl;
	cout << "Odd nubers are: " << endl;
	for (int i = 1; i < 20; i += 2) {
		cout << i << " ";
	}
	cout << endl << endl;
	system("pause");
	// for (ctr=___;ctr<___;ctr___)
	//     cout << ctr << " ";
	// cout << endl << endl;

	// #8 Complete the rest of the code that helps someone
	//    practice their multiplication table.

	int number2, answer, correctAnswer = 0, score = 0;
	char type;
	cout << "Arithmetic Drill Time" << endl;
	cout << "What do you want to practice * / + - ? ";
	cin >> type;

	while (cin.fail() || type != '*' && type != '/' && type != '+' && type != '-') {
		cout << "Error enter again: ";
		cin >> type;
	}

	// for (ctr=1;_________________;ctr++)
	for (int i = 0; i < 3; i++)
	{
		number = rand() % 10 + 1;
		number2 = rand() % 10 + 1;
		cout << "what is " << number << type << number2 << "? ";
		cin >> answer;

		//write the code that will validate answer. Check for input fail only
		while (cin.fail()) {
			cout << "Error. Input again: ";
			cin >> answer;
			cout << endl;
		}

		//add the nested if that will compute the correctAnswer
		//based on the type
    switch (type) {
      case '+':
      correctAnswer = number + number2;
      break;
      case '-':
      correctAnswer = number - number2;
      break;
      case '*':
      correctAnswer = number * number2;
      break;
      case '/':
      correctAnswer = number / number2;
      break;
    }


		//add an if statement that will compare the user's answer with the
		//correct answer. If correct add 1 to score
		if (answer == correctAnswer) {
			score++;
		}

	}
	cout << "Your score is: " << score << endl;

	//#9 Prints a row of big stars across the screen.
	//   Try printing another character using char values

	cout << endl;
	for (ctr = 0; ctr < 20; ctr++)
	{
		cout << char(220) << char(221) << ' ';
	}

	cout << endl;

	for (ctr = 0; ctr < 20; ctr++)
	{
		cout << char(222) << char(223) << ' ';
	}

	cout << endl << endl;

	cout << endl << "Program ended successfully" << endl;
	system("pause");
}
