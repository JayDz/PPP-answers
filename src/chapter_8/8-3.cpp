/*
	chapter 8 exercise 3
	page 296
*/
#include "std_lib_facilities.h"

void print(string label, const vector<int>& values)
{
	cout << label << ": ";
	for (int i = 0; i < values.size(); ++i) {
		cout << values[i];
		if (i+1 < values.size()) 
			cout << ", ";
	}
	cout << endl;
}

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
	if (n != 0)
		cout << "WARNING: overflow detected.\n";
}

int main()
{
	vector<int> fib_sequence;
	fibonacci(5,8,fib_sequence,25);
	print("fibonacci sequence",fib_sequence);
	return 0;
}
