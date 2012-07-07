/*
	chapter 18 exercise 2
	page 643
*/
#include "std_lib_facilities.h"
#include <string.h>

char* findx(const char* s, const char* x)
{
	int s_size = strlen(s);
	int x_size = strlen(x);
	int k = 0;
	for (int i = 0; i < s_size; ++i) {
		if (!isspace(*(s+i))) { //skip any white-space, for example, tabs.
			if (*(s+i) != *(x+k)) {
				k = 0;
				// lets go to the next word in line, avoids returning true
				// when word is a sub-string. For example, searching for
				// spy within spyro will return true without this loop.
				while (*(s+i) != ' ') { 
					if (i < s_size)
						i++;
					else
						break;
				}
			}
			else {
				k++;
				if (k == x_size && !isalpha(*(s+i+1)))
					return const_cast<char*>(s+i-k+1);
			}
		}
	}
	return 0;
}

int main()
{
	cout << "Enter text: ";
	string text;
	getline(cin,text);

	cout << "Enter search term: ";
	string term;
	cin >> term;

	char* str = findx(text.c_str(),term.c_str());

	if (str)
		cout << str << endl;
	else 
		cout << term << " was not found.\n";
	
	return 0;
}
