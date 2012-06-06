/*
	chapter 8 exercise 14
	page 297
*/
#include "std_lib_facilities.h"

vector<int> char_count(const vector<string>& v)
{
	vector<int> lengths;
	for (int i = 0; i < v.size(); ++i)
		lengths.push_back(v[i].size());
	return lengths;
}

int find_shortest_str(const vector<int>& v)
{
	int index = 0;   //initial index of the shortest
	int value = v[0];//initial value of the shortest

	for (int i = 1; i < v.size(); ++i) {
		if (v[i] < value) {
			value = v[i];
			index = i;
		}
	}
	return index;
}	

int find_longest_str(const vector<int>& v)
{
	int index = 0; 
	int value = v[0];

	for (int i = 1; i < v.size(); ++i) {
		if (v[i] > value) {
			value = v[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	cout << "Enter input (enter \"quit\" to exit loop): ";
	vector<string> input;
	string val;
	while (cin >> val && val != "quit")
		input.push_back(val);
	
	if (input.size() < 1) error("Need some input.");

	vector<int> count = char_count(input);

	cout << "\nCharacter count:\n";
	for (int i = 0; i < input.size(); ++i)
		cout << input[i] << " has " << count[i] << " character[s].\n";
	
	cout << "\nThe shortest string is: " << input[find_shortest_str(count)] << endl;
	cout << "The longest string is: " << input[find_longest_str(count)] << endl;

	sort(input.begin(),input.end());
	cout << "Lexicographically first is: " << input[0] << endl;
	cout << "Lexicographically last is: " << input[input.size()-1] << endl;

	return 0;
}
