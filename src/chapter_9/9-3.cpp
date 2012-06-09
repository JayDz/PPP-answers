/*
	chapter 9 exercise 3
	page 334
*/
#include "std_lib_facilities.h"

//helps avoid name collision between sort() and Name_pairs::sort()
vector<string>& sort_names(vector<string>& name);

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void sort();

	//functions needed for operator<< to function
	int get_size()const { return name.size(); }
	string get_name(int index)const { return name[index]; }
	double get_age(int index)const  { return age[index];  }

private:
	vector<string> name;
	vector<double> age;
};

ostream& operator<<(ostream& os, const Name_pairs& np)
{
	int size = np.get_size();
	for (int i = 0; i < size; ++i)
		os << np.get_name(i) << " is " << np.get_age(i) << " years old.\n";
	return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	if (a.get_size() != b.get_size()) return false;
	for (int i = 0; i < a.get_size(); ++i) {
		if (a.get_name(i) != b.get_name(i)) return false;
		if (a.get_age(i) != b.get_age(i)) return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a==b);
}

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
//needed because Name_pairs::sort() hides sort() when it is
//called within a member function. sort() is provided by std_lib_facilities.h.
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
		cout << pairs;
	
		cout << "\nSorted names:\n";
		pairs.sort();
		cout << pairs;
		cout << endl;
	
		cout << "\nLets put some more names in.\n";
		pairs.read_names();
		pairs.read_ages();
		cout << pairs;
	
		cout << "\nSorted names:\n";
		pairs.sort();
		cout << pairs;

		cout << "\nLets create another object:\n";
		Name_pairs pairs2;
		pairs2.read_names();
		pairs2.read_ages();
		cout << pairs2;
	
		cout << "\nLets check for equality\n";
		pairs2.sort(); //sort before checking since pairs is sorted also.

		if (pairs == pairs2) 
			cout << "The objects are equal.\n";
		if (pairs != pairs2) 
			cout << "The objects are not equal.\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
