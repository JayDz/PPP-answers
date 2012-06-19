/*
	chapter 11 exercise 8
	page 404
*/
#include "std_lib_facilities.h"

int main()
{
	try {
		cout << "Please enter input file name\n";
		string name;
		cin >> name;

		ifstream ifs(name.c_str());
		if (!ifs) error("Error opening ",name);

		vector<int> values;
		int val;
		while (ifs >> val)
			values.push_back(val);
		ifs.close();

		ofstream ofs(name.c_str(),ios_base::trunc|ios_base::binary);
		if (!ofs) error("Errror opening ",name);
		
		for (int i = 0; i < values.size(); ++i)
			ofs.write(as_bytes(values[i]),sizeof(int));
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
