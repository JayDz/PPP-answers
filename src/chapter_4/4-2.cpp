/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 2
	Page 126
*/
#include "std_lib_facilities.h"

int main()
{
	vector<double> temps;
	double temp;
	while (cin >> temp)
		temps.push_back(temp);

	double sum = 0;
	for (int i = 0; i < temps.size(); ++i) 
		sum += temps[i];
	
	cout << "Average temp: " << sum / temps.size() << endl;

	sort(temps.begin(), temps.end());

	if (temps.size() % 2 == 0) {
		double mid = ((temps[temps.size() / 2]) +
		             (temps[temps.size() / 2 - 1])) / 2.0;
		cout << "Median temp is: " << mid << endl;
	}
	else 
		cout << "Median temp is: " << temps[temps.size() / 2] << endl;
	
	return 0;
}
