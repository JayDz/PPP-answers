/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 16
	Page 128
*/
#include "std_lib_facilities.h"

int main()
{
	vector<double> sequence;

	cout << "Enter a sequence of positive numbers and | to finish input: ";
	double val;
	while (cin >> val) {
		if (val > 0)
			sequence.push_back(val);
		else
			cout << val << " not recorded, input must be a positive integer." << endl;
	}
	
	if (sequence.size() > 0) {

		sort(sequence.begin(), sequence.end());
		
		vector<int> frequency; // Will contain the frequency of each unique digit in sequence.
		int count = 1;
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
		int largest_freq = frequency[0];
		int index_of_largest = 0;
		for (int i = 1; i < frequency.size(); ++i) {
			if (frequency[i] > largest_freq) {
				largest_freq = frequency[i];
				index_of_largest = i;
			}
		}
		
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
	else 
		cout << "Sequence was too short!" << endl;

	return 0;
}
