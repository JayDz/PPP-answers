/*
	chapter 18 exercise 8
	page 643
*/
#include "std_lib_facilities.h"

bool is_palindrome(const string& s)
{
	string copy;
	for (int i = s.length()-1; i >= 0; --i)
		copy += s[i];
	return copy == s;
}

bool is_palindrome(const char s[], int n)
{
	char* copy = new char[n];
	int ii = 0;
	for (int i = n-1; i >= 0; --i)
		copy[ii++] = s[i];
	copy[ii] = 0;
	
	for (int i = 0; i < n; ++i) {
		if (copy[i] != s[i]) { 
			delete[] copy;
			return false;
		}
	}
	delete[] copy;
	return true;
}

bool is_palindrome(const char* first, const char* last)
{
	int size = last - first;
	char* copy = new char[size+1];
	int ii = 0;
	for (int i = size; i >= 0; --i)
		copy[ii++] = *(first+i);
	copy[ii] = 0;
	
	for (int i = 0; i < size; ++i) {
		if (copy[i] != *(first+i)) {
			delete[] copy;
			return false;
		}
	}
	delete[] copy;
	return true;
}

int main()
{
	// output should look like: 1,1,1,0,0,0
	string str = "malayalam";
	cout << is_palindrome(str) << endl;
	char str2[] = "malayalam";
	cout << is_palindrome(str2,str.length()) << endl;
	char* str3 = "malayalam";
	cout << is_palindrome(str3,&str3[str.length()-1]) << endl;

	string str4 = "programming";
	cout << is_palindrome(str4) << endl;
	char str5[] = "programming";
	cout << is_palindrome(str5,str4.length()) << endl;
	char* str6 = "programming";
	cout << is_palindrome(str6,&str6[str4.length()-1]) << endl;

	return 0;
}
