/*
	chapter 19 exercise 12
	page 683
*/
#include "std_lib_facilities.h"

class File_handle {
	ifstream file;
public:
	explicit File_handle(const char* str);
	~File_handle();
};

File_handle::File_handle(const char* str)
{
	file.open(str,ios_base::in);
	if (!file) error(str, " could not be opened.");
}

File_handle::~File_handle()
{
	file.close();
}

int main()
{
	try {
		cout << "Enter filename: ";
		string file_name;
		cin >> file_name;

		File_handle file(file_name.c_str());
	}
	catch(exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}
