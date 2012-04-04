/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 13
	Page 169
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "To help the game run please enter a number: ";
	int n;
	cin >> n;
	if (!cin)
		error("Input error.");
	srand(n);

	vector<int> winning_numbers(4);
	
	bool loop_game = true;
	while (loop_game == true) {
		winning_numbers[0] = randint(10);
		winning_numbers[1] = randint(10);
		winning_numbers[2] = randint(10);
		winning_numbers[3] = randint(10);

		int bulls = 0;
		int cows  = 0;

		cout << "Welcome to Bulls and Cows! Please enter 4 digits in the range 0 to 9:\n";
		while (bulls != 4) {
			bulls = 0;
			cows  = 0;
			int guesses = 0; //keep count of how many numbers user has supplied.

			while (guesses < 4) { 	//get number from user and check if it's a bull or cow.
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
				else {
					cerr << "Input error. Try again.\n";
					cin.clear(); //clear bad state and clean up garbage.
					string garbage;
					cin >> garbage;
				}
			}

			if (bulls != 4)
				cout<<"You have "<<bulls<<" bull(s) and "<<cows<<" cow(s). You need 4 bulls to win, try again.\n";
		}		
		cout << "Good job, you got all 4 bulls!\n";
		cout << "Would you like to play again (Y/N)? ";
		string response;
		cin >> response;
		
		if (response != "yes" && response != "y" && response != "Y")
			loop_game = false;
	}

	return 0;
}
