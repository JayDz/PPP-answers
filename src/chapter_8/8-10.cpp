/*
	chapter 8 exercise 10
	page 296
*/
#include "std_lib_facilities.h"

double compute_index(const vector<double>& price, const vector<double>& weight)
{
	if (weight.size() <= price.size()) {
		double value = 0;
		for (int i = 0; i < price.size(); ++i)
			value += (price[i]*weight[i]);
	return value;
	}
	else
		error("input error.");
}

int main()
{
	vector<double> price;
	vector<double> weight;
	
	cout << "Enter price and weight pairs (or a non-digit to end input loop): ";
	double p;
	double w;
	while (cin >> p >> w) {
		price.push_back(p);
		weight.push_back(w);
	}

	cout << "The computed index is: " << compute_index(price,weight) << endl;
	return 0;
}
