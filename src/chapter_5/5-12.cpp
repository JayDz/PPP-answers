/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 12
	Page 169
*/
#include "std_lib_facilities.h"

int main()
{
	try {
		vector<int> winning_numbers(4);
		winning_numbers[0] = 2;
		winning_numbers[1] = 7;
		winning_numbers[2] = 8;
		winning_numbers[3] = 5;

		int bulls = 0;
		int cows  = 0;

		cout << "Welcome to Bulls and Cows! Please enter 4 digits in the range 0 to 9:\n";
		while (bulls != 4) {
			bulls = 0;
			cows  = 0;
			int guesses = 0; //keep count of how many numbers user has supplied.

			while (guesses < 4) {
				int num;
				cin >> num;
				if (cin) {
					if (num < 0 || num > 9)
						cout << "Please enter a digit in the range 0 to 9.\n";
					else {
						for ( int i = 0; i < winning_numbers.size(); ++i) {
							if (num == winning_numbers[i]) {
								if (guesses == i)
									++bulls;
								else
									++cows;
							}
						}
					++guesses;
					}		
				}
				else
					error("Input error detected.");
			}

			if (bulls != 4)
				cout << "You have " << bulls << " bull(s) and " << cows << " cow(s). You need 4 bulls to win, try again.\n";
		}		
		cout << "Good job, you got all 4 bulls!\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
