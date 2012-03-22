/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 11
	Page 127
*/
#include "std_lib_facilities.h"

vector<int> primes;

int is_prime(int value)
	// If value is prime return 1, else return 0.
{
	int i = 0;
	int keep_looping = 1;

	while (keep_looping == 1) {
		if ((i >= primes.size()) || (value <= primes[i])) return 1;
		else
			if (value % primes[i] == 0) return 0;
		++i;
	}
	return 0xdeadbeef; // Never reached.
}

int main()
{
	// First known 25 prime numbers in the range (1,100).
	primes.push_back(2);  primes.push_back(3);  primes.push_back(5);  primes.push_back(7);
	primes.push_back(11); primes.push_back(13); primes.push_back(17); primes.push_back(19);
	primes.push_back(23); primes.push_back(29); primes.push_back(31); primes.push_back(37);
	primes.push_back(41); primes.push_back(43); primes.push_back(47); primes.push_back(53);
	primes.push_back(59); primes.push_back(61); primes.push_back(67); primes.push_back(71);
	primes.push_back(73); primes.push_back(79); primes.push_back(83); primes.push_back(89); 
	primes.push_back(97);
	
	vector<int> found_primes;
	// Get prime numbers in range(1,100).
	for (int i = 2; i <= 100; ++i)
		if (is_prime(i) == 1)
			found_primes.push_back(i);
	
	int mismatch_found = 0;
	for (int i = 0; i < primes.size(); ++i)
		if (primes[i] != found_primes[i])
			mismatch_found = 1;

	if (mismatch_found == 0)
		// Print found_primes.
		for (int i = 0; i < found_primes.size(); ++i)
			cout << found_primes[i] << endl;
	else
		cout << "Mismatch in vectors found!" << endl;
	
	return 0;
}
