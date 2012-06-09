/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	chapter 6 exercise 10
	page 217
*/
#include "std_lib_facilities.h"

int factorial(int n)
	//pre-condition: n must be greater than or equal to zero.
	//post-condition: n! is calculated.
{
	if (n == 0) return 1;
	if (n < 0) error("Factorial error, n cannot be less than zero.");

	int answer = n;
	n -= 1;
	while (n > 0) { 
		answer *= n--;
		if (answer < 1) error("Overflow error.");
	}

	return answer;
}

int permutation(int a, int b)
	//pre-condition: a and b are greater than or equal to zero.
	//post-condition: the permutation of a and b is calculated.
{
	if ( a < 0 || 0 > b) error("a, and b must be positive integers.");
	return factorial(a) / factorial(a-b);
		
}
int combination(int a, int b)
	//pre-condition: a and b are greater than or equal to zero.
	//post-condition: the combination of a and b is calculated.
{
	if (a < 0 || 0 > b) error("a, and b must be positive integers.");
	return permutation(a,b) / factorial(b);
}

int main()
{
	try {
		cout << "Please enter two positive numbers: ";
		int a;
		int b;
		cin >> a >> b;
		
		if (cin) {
			int answer;
			bool valid_choice = false;
			while (!valid_choice) {
				cout << "Operation: To calculate permutation enter p, or c for combination: ";
				char choice;
				cin >> choice;
	
				if (choice == 'p' || choice == 'P') {
					answer = permutation(a,b);
					valid_choice = true;
				}
				else if (choice == 'c' || choice == 'C') {
					answer = combination(a,b);
					valid_choice = true;
				}
				else
					cout << "Invalid option." << endl;
			}

			cout << "result = " << answer << endl;
		}
		else
			cout << "Invalid input.\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
