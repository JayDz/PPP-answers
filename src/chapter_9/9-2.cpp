/*
	chapter 9 exercise 2
	page 334
*/
#include "std_lib_facilities.h"

//helps avoid name collision between sort() and Name_pairs::sort()
vector<string>& sort_names(vector<string>& name);

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();

private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names()
{
	cout << "Please enter a series of names (enter \"quit\" to exit loop): ";
	string input;
	while (cin >> input && input != "quit")
		name.push_back(input);
}

void Name_pairs::read_ages()
{
	if (name.size() > 0) {
		int index = 0;
		if (age.size() > 0) //we've been here before! Lets not overwrite previous ages.
			index = age.size();
			
		for (int i = index; i < name.size(); ++i) {
			cout << "Please enter the age of " << name[i] << ": ";
			int input;
			cin >> input;
			if (!cin)
				error("Bad input received. Cannot continue.");
			else if (input < 0) {
				cout << "Invalid age.\n";
				--i; // Dangerous, needed to re-prompt for the correct name[i].
			}
			else
				age.push_back(input);
		}
	}
	else
		cout << "Please enter names first.\n";
}

void Name_pairs::print() const
{
	for (int i = 0; i < name.size(); ++i)
		cout << name[i] << " is " << age[i] << " years old.\n";
}

void Name_pairs::sort()
{
	if (name.size() == 0 || 0 == age.size()) {
		cout << "Nothing to sort.\n";
		return;
	}
	vector<string> name_copy = name; //Follow strategy from exercise 7 of chapter 8.
	name = sort_names(name);

	vector<double> new_ages;
	for (int i = 0; i < name.size(); ++i) 
		for (int j = 0; j < name.size(); ++j)
			if (name[i] == name_copy[j])
				new_ages.push_back(age[j]);
	
	age = new_ages; //age now contains an up-to-date order of ages.
}

//helper function:
//needed because Name_pairs::sort() hides sort() when
//called in a member function. sort() is provided by std_lib_facilities.h.
//Without helper function, we get a compile-time error from g++.
vector<string>& sort_names(vector<string>& name)
{
	sort(name.begin(),name.end());
	return name;
}

int main()
{
	try {
		Name_pairs pairs;
	
		pairs.read_names();
		pairs.read_ages();
		cout << endl;
		pairs.print();
	
		cout << "\nSorted names:\n";
		pairs.sort();
		pairs.print();
		cout << endl;
	
		cout << "\nLets put some more names in.\n";
		pairs.read_names();
		pairs.read_ages();
		pairs.print();
	
		cout << "\nSorted names:\n";
		pairs.sort();
		pairs.print();
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
