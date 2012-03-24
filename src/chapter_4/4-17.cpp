/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 17
	Page 128
*/
#include "std_lib_facilities.h"

int main()
{
	vector<string> sequence;

	cout << "Enter a sequence of strings and @stop to finish input: ";
	int keep_looping = 1;
	while (keep_looping == 1) {
		string val;
		cin >> val;
		if (val != "@stop")
			sequence.push_back(val);
		else 
			keep_looping = 0;
	}
	
	if (sequence.size() > 0) {

		sort(sequence.begin(), sequence.end());
		string min = sequence[0];
		string max = sequence[sequence.size() - 1];

		vector<int> frequency; // Will contain the frequency of each unique string in sequence.
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
		vector<string> unique_seq;
		unique_seq.push_back(sequence[0]);
		for (int i = 1; i < sequence.size(); ++i) {
			if (sequence[i] != sequence[i - 1])
				unique_seq.push_back(sequence[i]);
		}

		cout << "The min is " << min << "." << endl;
		cout << "The max is " << max << "." << endl;
		cout << "The mode is " << unique_seq[index_of_largest];
		cout << ". The number of times it appeared is " << largest_freq << "." << endl;
		
	}
	else 
		cout << "Sequence was too short!" << endl;

	return 0;
}
