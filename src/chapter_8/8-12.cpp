/*
	chapter 8 exercise 12
	page 297
*/
#include "std_lib_facilities.h"

// returning a struct is cleaner than a function which takes five arguments.
struct Vector_data {
double largest;
double smallest;
double mean;
double median;
};

Vector_data get_data(const vector<double>& v)
{
	vector<double> v_copy = v; //keep original vector the same.
	sort(v_copy.begin(),v_copy.end());

	Vector_data data;
	data.largest  = v_copy[v_copy.size()-1];
	data.smallest = v_copy[0];

	//find mean
	double total = 0;
	for (int i = 0; i < v.size(); ++i)
		total += v[i];
	data.mean = total / v.size();
	
	//find median
	if (v_copy.size() % 2 == 0) { //even number
		double mid  = v_copy[v_copy.size() / 2] + v_copy[(v_copy.size() / 2)-1];
		data.median = mid / 2;
	}
	else
		data.median = v[v.size() / 2];

	return data;
}

int main()
{
	try {
		cout << "Enter a sequence of numbers (non-digit character to exit loop): ";
		vector<double> seq;
		double val;
		while (cin >> val)
			seq.push_back(val);
	
		if (seq.size() < 2) error("Give me more numbers.");

		Vector_data data = get_data(seq);

		cout << "The largest element is: " << data.largest << endl;
		cout << "The smallest element is: " << data.smallest << endl;
		cout << "The mean is: " << data.mean << endl;
		cout << "The median is: " << data.median << endl;
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
