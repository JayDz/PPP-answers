/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 4
	Page 126
*/
#include "std_lib_facilities.h"

int main()
{
	int lower_limit = 0;
	int upper_limit = 101;
	int middle = 50;
	int users_number = 0;

	cout << "Think of a number between 1 and 100." << endl;
	int found = 0;
	while (found == 0) {
		cout << "Is the number less than " << middle << "? ";
		string answer;
		cin >> answer;

		if (answer == "yes" || answer == "y") {
			upper_limit = middle;
			middle = (middle + lower_limit) / 2; 
		}
		else if(answer == "no" || answer == "n") {
			lower_limit = middle;
			middle = (middle + upper_limit) / 2;
		}
		else 
			cout << "Please answer (y)es or (n)o" << endl;

		if ((upper_limit - middle) == 1 || (lower_limit - middle) == 0) {
			found = 1;
			users_number = middle;
		}
	}
	
	cout << "The number you're thinking of is: " << users_number << endl;

	return 0;
}
