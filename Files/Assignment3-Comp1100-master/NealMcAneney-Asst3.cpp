#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
//Neal McAneney, Section 104

/*
Desc: C++ program to record the Title of books, and their number of copies.
This will be using arrays, strings, and file outputs.
This will ask for user input and then output to a file.
*/
using namespace std;
int main() {
	//Declaration of variables and files (ie Housekeeping)
	const int A_SIZE = 20;
	string a_bookTitles[A_SIZE] = {};
	int bookTotalCopies = 0, bookTotalInStock = 0, lowestIndex = 0;
	int a_bookCopies[A_SIZE] = {};

	//File creation
	ofstream fout("books.file");
	if (!fout.is_open()) {
		cout << "\nError, File not opened. Check directory. " << endl;
		cout << "Now Crashing.." << endl;
		system("pause");
		exit(-1);
	}
	fout << left << setw(33) << "Book Titles" << right << setw(16) << "Number of copies" << endl;
	//input
	for (bookTotalCopies = 0; bookTotalCopies < A_SIZE; bookTotalCopies++) {
		cout << "Enter title of book or ctrl+z to exit: ";
		getline(cin, a_bookTitles[bookTotalCopies]);
		if (cin.eof()) {
			break;
		}

		cout << "Enter # of copies: ";
		cin >> a_bookCopies[bookTotalCopies];
		//While loop validation
		while (a_bookCopies[bookTotalCopies] < 0  || a_bookCopies[bookTotalCopies] > 150 || cin.fail()) {
			cout << "Error. failed input, in-between 0 and 150." << endl;
			cout << "Enter # of copies: " << endl;
			cin.clear();
			cin.ignore(80,'\n');
			cin >> a_bookCopies[bookTotalCopies];
		}
		bookTotalInStock += a_bookCopies[bookTotalCopies];
		cin.clear();
		cin.ignore(80, '\n');
		if (a_bookCopies[bookTotalCopies] < a_bookCopies[lowestIndex]) {
			lowestIndex = bookTotalCopies;//sets lowest index
		}
	}
	//output
	for (int ctr = 0; ctr < bookTotalCopies; ctr++) {
		fout << left << setw(33) << a_bookTitles[ctr] << right << setw(16) << a_bookCopies[ctr];
		if (lowestIndex == ctr) {
			fout << " **** FEWEST ****";
		}
		fout << endl;
	}
	fout << endl << left << setw(22) << "Total Books in stock: " << bookTotalInStock << endl;
	fout << setw(17) << "Number of books: " << bookTotalCopies << endl;

	system("type books.file");
	cout << "Program Ended" << endl;
	system("pause");
}
// Enter title of book or ctrl+z to exit: Mages and you
// Enter # of copies: 34
// Enter title of book or ctrl+z to exit: Alduin is Real
// Enter # of copies: 12
// Enter title of book or ctrl+z to exit: Bandits Journal
// Enter # of copies: 23
// Enter title of book or ctrl+z to exit: ^Z
// Book Titles                      Number of copies
// Mages and you                                  34
// Alduin is Real                                 12 **** FEWEST ****
// Bandits Journal                                23
//
// Total Books in stock: 69
// Number of books: 3
// Program Ended
// Press any key to continue . . .
