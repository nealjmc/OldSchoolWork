#include <iostream>
#include <ctime>
using namespace std;
// Lab Ex#11: simplified Shut the Box game
/* Rules: 6 tiles are displayed, 2 dice rolled,
player chooses one of the dice to remove a tile
Play stops when no dice values match any
of the tiles or all tiles removed */

int main()
{
	/////////////////////housekeeping
	const int SIZE = 6;
	int tile[SIZE] = { 1,2,3,4,5,6 };
	int index;
	int dice1, dice2, choice;
	int score = 0;
	int noTiles = SIZE;
	char choice = ' ';
	srand((unsigned)time(0));
	system("color 0A");
	while (noTiles > 0) //play game while there are tiles
	{
		// use a for loop to add the code to
		// display each tile separated by a space (remember
		// to use SIZE) only print tiles with a
		// value greater than zero
		for (int i = 0; i < SIZE; i++) {
			if (tile[i] > 0) {
				cout << i << " ";
			}
		}
		cout << endl;
		//////////////////////roll the dice
		dice1 = rand() % 6 + 1;
		cout << "The first die rolled is: " << dice1 << endl;
		dice2 = rand() % 6 + 1;
		cout << "The second die rolled is: " << dice2 << endl;
		//add a for loop statement to look at all 6 tiles
		// (remember to use SIZE
		for (int i = 0; i < SIZE; i++) {
			// add an if statement to see if either die matches
			// a tile. If so, quit the for loop
			if(dice1 == tile[i] || dice2 == tile[i])
			{
				break;
			}
		}
		if (SIZE == index) {
			/* code */
		}
		// After the loop: add an if statement to check if no
		// matches (ie size and index are
		// equal). If so
		// end the outer while loop if no matches
		if (SIZE == index) {
			break;
		}
		cout << "Enter choice of die to use(1/2): ";
		cin >> choice;
		//add a while loop to validate user input, ensure that choice is dice1 or dice2 only
		//don't allow input failure.
		while (cin.fail() && choice != '1' || choice != '2' ) {
			cout << "Error try again: ";
			cin >> choice;
			cout << endl;
		}
		//If the die selected is one that has already been
		//turned over, the user forfeits his/her turn.
		//add an if statement that checks if equals a tile that is zero
		for (int i = 0; i < SIZE; i++) {
			if () {
				/* code */
			}
		}
		//if true, state they lose their turn
		//otherwise
		// set tile value that matches the choice
		// (remember arrays start a zero) to zero
		// add choice to score, reduce number of
		// tiles remaining and stop looping
	}
	cout << "Your score is" << score << endl;
	// if no tiles are remaining (i.e. zero),
	// print a message that they won the game
	cout << endl << "Game over " << endl;;
	system("pause");
}
