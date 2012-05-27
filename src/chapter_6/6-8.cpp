/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 6 exercise 8
	Page 217
*/
#include "std_lib_facilities.h"

int main()
{
	vector<char> winning_chars(4);
	winning_chars[0] = 'f';
	winning_chars[1] = 'r';
	winning_chars[2] = 'e';
	winning_chars[3] = 'e';

	int bulls = 0;
	int cows  = 0;

	cout << "Welcome to Bulls and Cows! Please enter 4 characters [a-zA-Z]:\n";
	while (bulls != 4) {
		bulls = 0;
		cows  = 0;
		int guesses = 0; //keep count of how many numbers user has supplied.

		while (guesses < 4) {
			char ch;
			cin >> ch;
			if (cin) {
				bool is_a_valid_char = true;
				if (ch < 'a' || ch > 'z') {
					if (ch < 'A' || ch > 'Z') {
						cout << "Please enter a valid [a-zA-Z] character.\n";	
						cout << "Valid guesses recorded = " << guesses << endl;
						is_a_valid_char = false;
					}
				}
				if (is_a_valid_char) {
					for ( int i = 0; i < winning_chars.size(); ++i) {
						if (ch == winning_chars[i]) {
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

	return 0;
}
