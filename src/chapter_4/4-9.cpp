/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 9
	Page 127
*/
#include "std_lib_facilities.h"

int i_power(int base, int power)
// Use this function to calculate max grains we're able to calculate for an int.
{
	if (power == 0) return 1;
	if (power == 1) return base;

	int answer = base;
	for (int i = 1; i < power; ++i)
		answer *= base;
	
	return answer;
}

double d_power(int base, int power)
// Use this function to calculate max grains we're able to calculate for a double.
{
	if (power == 0) return 1;
	if (power == 1) return base;

	double answer = base;
	for (int i = 1; i < power; ++i)
		answer *= base;

	return answer;
}

int main()
{
	int i_grains_of_rice    = 0;
	double d_grains_of_rice	= 0;
	int current_square      = 0;

	int base  = 2;
	int power = 63; // Inventor asked for 2^63 grains of rice.
	
	// calculates largest amount of grain an int can hold.
	// the largest square we can calculate for int is 2^31 before values turn negative.
	for (int i = 0; i < power; ++i) {
		i_grains_of_rice += i_power(base, i);
		cout << i_grains_of_rice << '\t' << ++current_square << endl;
	} 

	current_square = 0;
	// calculate for type double.
	// on a GNU/Linux system the largest square we can calculate for double is 2^63.
	// represented in scientific notation after 2^20.
	for (int i = 0; i < power; ++i) {
		d_grains_of_rice += d_power(base, i);
		cout << d_grains_of_rice << '\t' << ++current_square << endl;
	}

	return 0;
}
