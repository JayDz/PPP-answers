/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 15
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
	cout << "Program will find the first N prime numbers, please enter N: ";
	int n;
	cin >> n;
	
	if (n > 0) {
		vector<int> found_primes;
		int i = 2;
		while (found_primes.size() < n) {
			int ret = is_prime(i);
			if (ret == 1)
				found_primes.push_back(i);
			++i;
		}

		for (int i = 0; i < found_primes.size(); ++i)
			cout << found_primes[i] << endl;
	}
	else
		cout << "N must be greater than zero." << endl;

	return 0;
}
