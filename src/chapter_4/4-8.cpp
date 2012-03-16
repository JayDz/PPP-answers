/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 8
	Page 127
*/
#include "std_lib_facilities.h"

int power(int base, int power)
{
	if (power == 0) return 1;
	if (power == 1) return base;

	int answer = base;
	for (int i = 1; i < power; ++i)
		answer *= base;
	
	return answer;
}

int main()
{
	int grains_of_rice   = 0;
	int squares_required = 0;
	
	int i = 0; // will keep as its value the current power to raise to base.
	while (grains_of_rice < 1000) {
		grains_of_rice += power(2, i);
		++squares_required;
		++i;
	}
	cout << "For one thousand  grains of rice we require " << squares_required << " squares." << endl;

	while (grains_of_rice < 1000000) {
		grains_of_rice += power(2, i);
		++squares_required;
		++i;
	}
	cout << "For one million grains of rice we require " << squares_required << " squares." << endl;

	while (grains_of_rice < 1000000000) {
		grains_of_rice += power(2, i);
		++squares_required;
		++i;
	}
	cout << "For one billion grains of rice we require " << squares_required << " squares." << endl;
	
	return 0;
}
