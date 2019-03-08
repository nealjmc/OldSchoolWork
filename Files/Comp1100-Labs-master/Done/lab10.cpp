#include <iostream>
#include <ctime>
#include <string>
using namespace std;
// Lab ex#7 8 ball game (arrays)
int main()
{
  const int SIZE=10;
  int ctr;
  //add 9 more responses to the string array that may appear after shaking the 8 ball
  string responses[SIZE]={"Yes", "No", "Maybe", "Sometimes",
  "Of course!", "Come back later", "Always", "Never", "Possibly","Come back in 5"};
  string question;
  int number;
  srand((unsigned) time(0));
  system("color 70");
  //************Write a for loop that will repeat the following 10 (use SIZE) times***********
  for(ctr = 0; ctr < SIZE; ctr++)
  {
    // a) Obtain from the user his/her question (don't forget to prompt them)
    cout << "Enter your question: ";
    getline(cin, question);
    // e) Add an if statement that checks if ctrl Z was entered. i.e. if (cin.eof())
    // If so, break out of the loop.
    if (cin.eof()) {
      break;
    }

    // f) Add this validation code after you have parts a) to f) working.
    //  Add a while loop that will ensure the user enters a question. We don’t want them
    // to simply press enter.
    //  Code : While (question.length()==0)
    while (question.length()==0)
    {
      // Ask the user to reenter
      cout << endl;
      cout << "Error please ask again: ";
      getline(cin,question);
    }
    // b) Generate a random number i.e. number=rand()%SIZE;
    number = rand()%SIZE;
    // c) Use a cout statement to display the value in the string array using number as
    // the index.
    cout << "Array["<< number << "]: ";
    cout << responses[number];
    cout << endl;
  }
  // g) after loop ends: print the number of questions asked. Code this after a) to e) works
  // Hint use your for loop counter 
  cout << endl << "Number of questions asked: " << ctr << endl;
  // d) print program ended successfully
  cout << "Program ended successfully" << endl;

  /******************************************************************************
  Try using F10 to run your program in Debug mode.
  Continue pressing F10 and it will step over you code.
  It is handy to see which statements are being executed or missed.
  To end Debug mode, click on Debug>Stop Debugging.
  ****************************************************************************/
  /***************************************************************
  Here's a handy way to ensure your statements are aligned:
  press Indexl A then Indexl K and finally Indexl F
  ************************************************************************/
  system("pause");
}
