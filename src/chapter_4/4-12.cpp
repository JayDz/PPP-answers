/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 12
	Page 128
*/
#include "std_lib_facilities.h"

int is_prime(int value)
	// If value is prime return 1, else return 0.
{
	for (int i = 2; i < value; ++i)
		if (value % i == 0) 
			return 0;
	return 1;
}

int main()
{
	cout << "Program will find all prime numbers between 1 and max. Enter max: ";
	int max;
	cin >> max;
	
	if (max > 0) {
		vector<int> found_primes;
		// Get prime numbers in range(1,100).
		for (int i = 2; i <= max; ++i)
			if (is_prime(i) == 1)
				found_primes.push_back(i);

		// Print primes found.
		for (int i = 0; i < found_primes.size(); ++i)
			cout << found_primes[i] << endl;
	}
	else
		cout << "Max must be > 0" << endl;

	return 0;
}
