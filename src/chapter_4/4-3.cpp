/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 3
	Page 126
*/
#include "std_lib_facilities.h"

int main()
{
	vector<double> distances;
	double sum_distance  = 0;
	double mean_distance = 0;

	double distance;
	while (cin >> distance) {
		distances.push_back(distance);
		sum_distance += distance;
	}

	cout << "The total distance is: " << sum_distance << endl;
	
	//find mean distance between neighboring cities
	for (int i = 1; i < distances.size(); ++i) {
		double avg = (distances[i] + distances[i -1]) / 2;
		mean_distance += avg;
	}
	cout << "The mean distance between two neighboring cities is: "
	     << mean_distance / (distances.size() - 1) << endl;

	sort(distances.begin(), distances.end());
	cout << "The smallest distance is: " << distances[0] << endl;
	cout << "The largest distance is: " << distances[distances.size() - 1] << endl;

	return 0;
}
