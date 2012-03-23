/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 14
	Page 128
*/
#include "std_lib_facilities.h"

vector<int> primes;

void find_primes()
	// Find prime numbers using the Sieve of Eratosthenes method.
{
	for (int i = 0; i < primes.size(); ++i) {
		int found = 0;
		int p;
		if (primes[i] != 0) {
			found = 1;
			p = primes[i];
		}

		int pp = p;
		if (found == 1) {
			while ((i + pp) <= (primes.size() - 1)) {
				primes[i + pp] = 0;
				pp += p;
			}
		}
	}
}

int main()
{
	cout << "I will find all prime numbers between 1 and max, please enter a max: ";
	int max;
	cin >> max;
	if (max > 0) {
		// Generate list of numbers from 2 to max.
		for (int i = 2; i <= max; ++i)
			primes.push_back(i);

		find_primes(); // Finding primes in range(1,100).
		
		// List prime numbers found.
		for (int i = 0; i < primes.size(); ++i) {
			if (primes[i] != 0) 
				cout << primes[i] << endl;
		}
	}
	else
		cout << "Max must be greater than zero." << endl;

	return 0;
}
