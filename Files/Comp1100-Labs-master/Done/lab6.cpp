#include <iostream>
#include <string>
#include <ctime> //necessary for random number generator
#include <fstream>
using namespace std;

//Lab ex#6:guessing game = allow the user 2 guesses only, write an assessment to a file
int main()
{
  //housekeeping
  int guess,number;
  int noTries = 0;
  string name;
  srand((unsigned)time(0)); //start the random number generator
  ofstream fout ("guess.txt");

  //add an if statement to ensure the file opened successfully
  if (fout.is_open()) {
    cout << "File Made successfully." << endl;
  }
  else{
    cout << "ERROR. File not made.";
  }

  number=rand()%10+1; //randomly generate the computer's guess

  //input
  cout << "what is your name: " ;
  getline(cin,name);
  cout << endl;

  cout << "Hello " << name << ", Let's play the guessing game!" << endl << endl;
  cout << "I am thinking of a number from 1-10. Can you guess it?";
  cin >> guess;
  noTries = noTries + 1;
  //processing
  //add an if statement to check if didn’t guess it correctly
  if (noTries <= 2)
   {
     //add an if statement to check if guessed it
     if (guess != number)
     {
      noTries = noTries + 1;
      cout << "Wrong. Guess again: ";
      cin >> guess;
    }

    else
    {
      cout << char(1) << " You guessed it! "; //look what char(1) does!!!
    }
  }
  else{
    cout << "Wrong! The number was: " << number; //only print if didn't guess it
  }
  cout << endl;



  ///////////////add an if statement to only print wrong! if didn't guess it




  cout << endl;
  //output to the file
  fout << "============================" << endl;
  fout << "Results of guessing game for: " << name << endl;
  fout << "Number to guess: "<< number <<endl;
  fout << "Number of tries: " << noTries << endl;
  ////////////////add an if to check if number was guessed first time
  if (noTries < 2) {
    fout << "Good guess, you must have esp! " << endl;
  }
  else{

  }
  //////////////add an if to check if number was not guessed
  if (guess != number) {
    /* code */
    fout << "Number not guessed.." ;
    fout << endl;
    fout << "============================" << endl;
    cout << "Game over" << endl;
  }
  fout.close();

  system("type guess.txt");
  system("pause");
}
