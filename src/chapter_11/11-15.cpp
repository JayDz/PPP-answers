/*
	chapter 11 exercise 15
	page 405
*/
#include "std_lib_facilities.h"

void fill_vector(ifstream& is, vector<double>& numbers)
{
	double number;
	while (is >> number)
		numbers.push_back(number);
	if (!is.eof()) error("A reading error occured."); //we should only exit loop on eof.
}

void print(const vector<double>& numbers)
{
	int count = 0;
	int i = 0;

	while (i < numbers.size()) {
		cout << numbers[i];
		int j = i;
		while (i < numbers.size()) {
			if (numbers[j] != numbers[i])
				break;
			else {
				++count;
				++i;
			}
		}

		if (count > 1)
			cout << "\t" << count;
		count = 0;
		cout << endl;
	}
}
int main()
{
	try {
		cout << "Enter filename: ";
		string name;
		cin >> name;
		ifstream is(name.c_str());
		if (!is) error("Error opening ",name);

		vector<double> numbers;
		fill_vector(is,numbers);
		sort(numbers.begin(),numbers.end());
		print(numbers);
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
