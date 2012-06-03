/*
	chapter 8 exercise 4
	page 296
*/
#include "std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.push_back(x);
	v.push_back(y);
	n -= 2;

	int pre_num1 = x;
	int pre_num2 = y;
	int fib_number = pre_num1 + pre_num2;

	while (n > 0 && fib_number > 0 ) {
		v.push_back(fib_number);
		pre_num1 = pre_num2;
		pre_num2 = fib_number;
		fib_number = pre_num1 + pre_num2;
		--n;
	}
}

void print_max(int max)
{
	cout << "The approximate maximum number an int can hold is: " << max << endl;
}

int main()
{
	vector<int> fib_sequence;
	int x = 1;
	int y = 2;
	// lets try different values for n, and if the size of fib_sequence
	// is less than n, we encountered an overflow.
	int n = 40;
	fibonacci(x,y,fib_sequence,n);
	if (fib_sequence.size() < n) {
		print_max(fib_sequence[fib_sequence.size()-1]);
		return 0;
	}
		
	// lets go further.
	n = 50;
	// lets continue an accurate fib sequence.
	x = fib_sequence[fib_sequence.size()-1] + fib_sequence[fib_sequence.size()-2];
	y = x + fib_sequence[fib_sequence.size()-1];
	fibonacci(x,y,fib_sequence,n);
	if (fib_sequence.size() < n) {
		print_max(fib_sequence[fib_sequence.size()-1]);
		return 0;
	}
	
	return 0;
}
