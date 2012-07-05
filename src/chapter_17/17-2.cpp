/*
	chapter 17 exercise 2
	page 609
*/
#include "std_lib_facilities.h"

int main()
{
	int* i  = new int[2];
	int* ip = &i[1];

	double* d  = new double[2];
	double* dp = &d[1];

	bool* b  = new bool[2];
	bool* bp = &b[1];
	
	// we must use reinterpret_cast operator, otherwise we'll get the number of elements between
	// pointers instead of bytes between pointers.
	cout << "Size of int is: "    << reinterpret_cast<int>(ip) - reinterpret_cast<int>(i) << endl;
	cout << "Size of double is: " << reinterpret_cast<int>(dp) - reinterpret_cast<int>(d) << endl;
	cout << "Size of bool is: "   << reinterpret_cast<int>(bp) - reinterpret_cast<int>(b) << endl;

	// verify
	cout << "\nVerify:\n";
	cout << "sizeof(int) is: "    << sizeof(int) << endl;
	cout << "sizeof(double) is: " << sizeof(double) << endl;
	cout << "sizeof(bool) is: "   << sizeof(bool) << endl;

	delete[] i;
	delete[] d;
	delete[] b;
	return 0;
}
