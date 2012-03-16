/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 6
	Page 126
*/
#include "std_lib_facilities.h"

int main()
{
	vector<string> values(10);
	values[0] = "zero";
	values[1] = "one";
	values[2] = "two";
	values[3] = "three";
	values[4] = "four";
	values[5] = "five";
	values[6] = "six";
	values[7] = "seven";
	values[8] = "eight";
	values[9] = "nine";

	cout << "Enter a digit (0-9) or spelled out digit to convert to its opposite equivalent: ";
	string digit;
	while(cin >> digit) {
			int index = -1;
			for (int i = 0; i < values.size(); ++i)
				if (digit == values[i])
					index = i;
				
			// if index equals -1 it means user input was in digit form.
			// On the other hand, if index is not equal to -1, input was in spelled-out form
			// and contains the index of the word we want to output.
			if (index != -1)
				cout << digit << " in digit form is: " << index << endl;
			else {
				if (digit == "0")      index = 0;
				else if (digit == "1") index = 1;
				else if (digit == "2") index = 2;
				else if (digit == "3") index = 3;
				else if (digit == "4") index = 4;
				else if (digit == "5") index = 5;
				else if (digit == "6") index = 6;
				else if (digit == "7") index = 7;
				else if (digit == "8") index = 8;
				else if (digit == "9") index = 9;
				else 
					cout << "Invalid input." << endl;
				
				// no need to bounds check, book's header file throws the excetion for us.
				cout << digit << " in spelled-out form is: " << values[index] << endl;
			}

		cout << "Enter a digit (0-9) or spelled out digit to convert to its opposite equivalent: ";
	}

	return 0;
}
