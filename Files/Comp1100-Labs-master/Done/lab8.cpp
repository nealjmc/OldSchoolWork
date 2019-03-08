#include <iostream>
#include <string>
#include <ctime>
using namespace std;
/*Lab ex#8: Snakes and ladders
we will randomly roll die for the computer, player will input value
the game goes up to 10 (not 100) and only has 1 snake and 1 ladder
for simplicity, the computer isn’t effected by snakes or ladders */
int main()
{
	//----------------------------------------------------------------housekeeping
	int computer = 0, player = 0;//player and computer's position on board 1-10
	int die;
	int snake, ladder;
	string name;

	srand((unsigned)time(0)); //start the random number generator
	system("color 2E");//change the console colours

	cout << "What is your name? ";
	getline(cin, name);

	cout << char(1) << " Hello " << name << ", welcome to snakes & ladders! " << char(1) << endl;
	//write a while loop that will continue as long as the value of computer is less than 10
	// and the value of player is less than 10
	while(player < 10 && computer < 10)
	{
		cout << "Roll your die - what is its value: ";
		cin >> die;
		//write a while loop that will validate user input, by ensuring the value of die is 1-6,
		//allow the user to reenter if invalid
		while (die > 6 || die < 1) {
			cin.clear();
			cout << "Error. Roll die again: ";
			cin >> die;
		}
		//if player has 10, don’t allow the computer to move,
		//end the game (break out of loop)
		if (player >= 10) {
			cout << "Player has won!" << endl;
			break;
		}
		//add an if statement that checks if the die + current position is over 10,
		//if true tell player he/she can't make the move
		//otherwise (player can move)
		if ((player + die) > 10) {
			cout << "Sorry you cannot move!" << endl;
		}
		else
		{
			player += die; //add the die to current player's position:
			snake = rand() % 9 + 1; //randomly generates the position for the snake
			//add an if statement that checks if landed on a snake:
			//if the player’s position is the same as the snake,
			// inform the player and reposition to 1
			if (player == snake) {
				cout << "YOU LANDED ON A SNAKE!" << endl;
				cout << "Moving you to 1" << endl << endl;
				player = 1;
			}
			// otherwise
			else
			{
				ladder = rand() % 8 + 1;//randomly generates the position for the ladder
				//if the player lands on a ladder,
				//inform the player and reposition to 9
				if (player == ladder) {
					cout << "YOU LANDED ON A LADDER!" << endl;
					cout << "Moving you to 9" << endl << endl;
					player = 1;
				}
			} //end if (ladder)

		} //end if (player’s move)
		//computer’s turn
		die = rand() % 6 + 1; //randomly generates roll of die for the computer
		//Check if computer can make move:
		//Add an if statement that checks if the die + computer’s position is over 10,
		// if true tell player that the computer can't move
		if ((computer + die) > 10) {
			cout << "Sorry, Computer can't move." << endl;
		}
		//otherwise (computer can move)
		else{
			computer += die; //add the die to current computer’s position:
			cout << "Your position is " << player << " My position is " << computer << endl;
		}
	} //end while loop
	//add an if statement to determine the winner
	if (player > computer) {
		cout << "PLAYER HAS WON!" << endl;
	}
	else{
		cout << "COMPUTER HAS WON!" << endl;
	}
	cout << endl << "game over " << endl;
	system("pause");
}
//i h8 this
