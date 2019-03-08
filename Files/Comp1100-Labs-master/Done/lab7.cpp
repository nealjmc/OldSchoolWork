#include <iostream>
#include <ctime>
using namespace std;
// Neal McAneney
//    Lab ex#7 Nested If
//    Black Jack Game
//      for simplicity, the dealer only gets 1 point for Ace, not 11

int main()
{

  ///housekeeping
  int card1, card2, card3 = 0, score = 0, dealer;
  char reply;
  srand((unsigned) time(0)); //start the random number generator

  system("color 5A");        //change the console colours

  cout << "\t" << char(3) << char(4) << char(5) << char(6) << endl;
  cout << "Let's play Black Jack! "<< endl;
  cout << "The object of this game is to get 21, and not go over. " << endl;

  /////////input

  cout << "The First card dealt is: ";
  card1 = rand()%10+1;      //deal the first card
  //add an if statement to print Ace if
  //the card is 1 otherwise print its face value
  if (card1 == 1) {
    cout << "ACE" << endl;
  }
  else{
    cout << card1 << endl;
  }


  //deal the second card and copy the first
  //if statement for the second card to
  //display ACE if the card was a 1
  cout << "The Second card dealt is: ";
  card2 = rand()%10+1;      //deal the first card


  if (card2 == 1) {
    cout << "ACE" << endl;  //add an if statement to print Ace if 1
  }
  else{
    cout << card2 << endl;
  }

  //add an if statement to check if y was entered.
  //if y then deal the third card
  //hint: the code will be the same as for card 1 and card 2
  cout << endl<< "Would you like another card (y/n)?";
  cin >> reply;
  if (reply == 'y') {
    card3 = rand()%10+1;
    if (card3 == 1) {
      cout << "ACE" << endl;  //add an if statement to print Ace if 1
    }
    else{
      cout << card3 << endl;
    }
  }


  ///////////////processing

  //calculate your score i.e. add
  //the 3 cards and store the answer in score
  score = card1 + card2 + card3;

  //In Black Jack if you go over 21, you automatically lose:
  //add an if statement that checks if the score is more than 21.
  //if it is, display dealer won!
  if (score > 21) {
    cout << "Dealer has won!" << endl;
  }
  //otherwise, add an else and a brace bracket add
  //a closing bracket before the game is over
  else{

    dealer = (rand() % 10 + 1) + (rand() % 10 + 1);  //give the dealer 2 cards

    //if the dealer's score is less than or equal to 16,
    //then the dealer must draw another card
    if (dealer <= 16) {
      dealer += (rand() % 10 + 1);
    }

    //add an if statement that checks the dealer's score,
    //if it is less than or equal to 16,
    //deal another card and display the new score.
    if (dealer <= 16) {
      dealer += (rand() % 10 + 1);
    }

    cout << "The dealer's  score is "<<dealer << endl;

    //If the dealer has more 21, you automatically lose:
    //  add an if statement that checks if the dealer
    //score is more than 21.
    //   if it is, display you won!
    if (dealer >= 21) {
      cout << "Dealer has lost! \nYou win!" << endl;
    }
    else {
      cout << "Dealer has won! \nYou lose!" << endl;
    }

    //In BlackJack, an ace can be worth 1 point or 11 points.

    // Let's add the code to change the Ace to have a face value of 11
    // if score won't go over 21:
    if(score < 21){
      //if either card is an ace and if the score is less than or equal to 11,
      if (((card1 || card2) == 1) && score <= 11) {
        score += 10;  //add 10 to the score
        cout << "Your score is: " << score << endl;//and redisplay the new score
      }
      if (score > dealer) {
        cout << "You win!" << endl;
      }
      /*If your score is more than the dealer's
      display you won!
      otherwise
      display dealer won!
      */
    }
    cout << endl << "Game over " << endl;;
    system("pause");
  }
}
