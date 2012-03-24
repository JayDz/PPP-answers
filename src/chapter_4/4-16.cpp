/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 16
	Page 128
*/
#include "std_lib_facilities.h"

int main()
{
	vector<double> sequence;

	cout << "Enter a sequence of positive numbers and | to finish: ";
	double val;
	while (cin >> val) {
		if (val > 0)
			sequence.push_back(val);
		else
			cout << val << " not recorded, input must be a positive integer." << endl;
	}
	
	if (sequence.size() > 0) {

		sort(sequence.begin(), sequence.end());
		
		vector<double> frequency; // Will contain the frequency of each unique digit in sequence.
		double count = 1;
		for (int i = 1; i < sequence.size(); ++i) {
			if (sequence[i] != sequence[i - 1]) {
				frequency.push_back(count);
				count = 1;
			}
			else
				++count;
		}
		frequency.push_back(count); // Loop ended before we can finish pushing the final count. 

		// Search for the largest frequency. 
		double largest_freq = frequency[0];
		double index_of_largest = 0;
		for (int i = 1; i < frequency.size(); ++i) {
			if (frequency[i] > largest_freq) {
				largest_freq = frequency[i];
				index_of_largest = i;
			}
		}
		
		if (largest_freq == 1) { 
			if (sequence.size() > 1) 
				cout << "No number appears more than once." << endl;
		}
		else {
			// Create a set out of the vector sequence. Contains no recurrences.
			// Needed so we can print out the correct mode indicated by variable index_of_largest.
			vector<double> unique_seq;
			unique_seq.push_back(sequence[0]);
			for (int i = 1; i < sequence.size(); ++i) {
				if (sequence[i] != sequence[i - 1])
					unique_seq.push_back(sequence[i]);
			}
		
			cout << "The mode is " << unique_seq[index_of_largest];
			cout << ". The number of times it appeared is " << largest_freq << "." << endl;
		}
	}
	else 
		cout << "Sequence was too short!" << endl;

	return 0;
}
