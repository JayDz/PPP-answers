/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 14
	Page 169
*/
#include "std_lib_facilities.h"

int main()
{
	int rejected_values = 0;
	vector<int> mon;
	vector<int> tues;
	vector<int> weds;
	vector<int> thurs;
	vector<int> fri;
	vector<int> sat;
	vector<int> sun;

	cout << "Please enter (day-of-the-week,value) pairs, and Quit when finished.\n";
	string dow = "";
	int pair_val;

	while (dow != "Quit" && dow != "quit") {
		cin >> dow;
		if (dow=="Mon" || dow=="mon" || dow=="monday" || dow=="Monday") {
			cin >> pair_val;
			if (cin)
				mon.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Tues" || dow=="tues" || dow=="tuesday" || dow=="Tuesday") {
			cin >> pair_val;
			if (cin) 
				tues.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Weds" || dow=="weds" || dow=="wednesday" || dow=="Wednesday") {
			cin >> pair_val;
			if (cin)
				weds.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Thurs" || dow=="thurs" || dow=="thursday" || dow=="Thursday") {
			cin >> pair_val;
			if (cin)
				thurs.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Fri" || dow=="fri" || dow=="friday" || dow=="Friday") {
			cin >> pair_val;
			if (cin)
				fri.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Sat" || dow=="sat" || dow=="saturday" || dow=="Saturday") {
			cin >> pair_val;
			if (cin)
				sat.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Sun" || dow=="sun" || dow=="sunday" || dow=="Sunday") {
			cin >> pair_val;
			if (cin)
				sun.push_back(pair_val);
			else
				error("Invalid value for pair.");
		}
		else if (dow=="Quit" || dow=="quit"); // we're going to quit input loop. 
		else {
			cout << "I do not recognize " << dow << " as a valid day, try again.\n";
			++rejected_values;
		}
	}

	vector<int> sums(7);
	
	cout << "The values entered for Monday are: ";
	for (int i = 0; i < mon.size(); ++i) {
		cout << mon[i] << " ";
		sums[0] += mon[i];
	}
	cout << "\nThe sum for Monday is: " << sums[0] << "\n\n";

	cout << "The values entered for Tuesday are: ";
	for (int i = 0; i < tues.size(); ++i) {
		cout << tues[i] << " ";
		sums[1] += tues[i];
	}
	cout << "\nThe sum for Tuesday is: " << sums[1] << "\n\n";

	cout << "The values entered for Wednesday are: ";
	for (int i = 0; i < weds.size(); ++i) {
		cout << weds[i] << " ";
		sums[2] += weds[i];
	}
	cout << "\nThe sum for Wednesday is: " << sums[2] << "\n\n";

	cout << "The values entered for Thursday are: ";
	for (int i = 0; i < thurs.size(); ++i) {
		cout << thurs[i] << " ";
		sums[3] += thurs[i];
	}
	cout << "\nThe sum for Thursday is: " << sums[3] << "\n\n";
	
	cout << "The values entered for Friday are: ";
	for (int i = 0; i < fri.size(); ++i) {
		cout << fri[i] << " ";
		sums[4] += fri[i];
	}
	cout << "\nThe sum for Friday is: " << sums[4] << "\n\n";
	
	cout << "The values entered for Saturday are: ";
	for (int i = 0; i < sat.size(); ++i) {
		cout << sat[i] << " ";
		sums[5] += sat[i];
	}
	cout << "\nThe sum for Saturday is: " << sums[5] << "\n\n";

	cout << "The values entered for Sunday are: ";
	for (int i = 0; i < sun.size(); ++i) {
		cout << sun[i] << " ";
		sums[6] += sun[i];
	}
	cout << "\nThe sum for Sunday is: " << sums[6] << "\n\n";

	cout << "The number of rejected values is " << rejected_values << ".\n";
	
	return 0;
}
