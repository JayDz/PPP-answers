/*
	chapter 8 exercise 7
	page 296
*/
#include "std_lib_facilities.h"

void get_names(vector<string>& name)
{
	cout << "Enter names (\"quit\" to exit loop): ";
	string input;
	while (cin >> input && input != "quit")
		name.push_back(input);
}

void get_ages(vector<double>& age, int num_ages)
{
	cout << "Enter their ages: ";
	for (int i = 0; i < num_ages; ++i) {
		int num;
		cin >> num;
		if (num <= 0) error("Invalid age.");
		if (!cin) error("Invalid input.");
		age.push_back(num);
	}
	cout << '\n';
}

void print_pairs(const vector<string>& name, const vector<double>& age)
{
	for (int i = 0; i < age.size(); ++i)
		cout << name[i] << " is " << age[i] << " years old.\n";
}

void update_pairs(vector<double>& age, const vector<string>& name, const vector<string>& name_copy)
{
	vector<double> new_ages;
	for (int i = 0; i < name.size(); ++i)
		for (int j = 0; j < name.size(); ++j)
			if (name[i] == name_copy[j])
				new_ages.push_back(age[j]);
	age = new_ages;
}

int main()
{
	try {
		vector<string> name;
		vector<double> age;

		get_names(name);
		get_ages(age,name.size());
		print_pairs(name,age);

		vector<string> name_copy = name;
		sort(name.begin(),name.end());
	
		update_pairs(age,name,name_copy);

		cout << "\nSorted pairs:\n\n";
		print_pairs(name,age);
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
