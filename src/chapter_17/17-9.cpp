/*
	chapter 17 exercise 9
	page 610
*/
#include "std_lib_facilities.h"

int main()
{
	//Stack grows toward lower addresses.
	//------------------
	int x;
	int y;
	int z;

	int* ptr = &x;
	cout << ptr << endl;
	ptr = &y;
	cout << ptr << endl;
	ptr = &z;
	cout << ptr << endl;
	//------------------
	//Free store grows toward higher addresses.
	//------------------
	ptr = new int[3];
	cout << &ptr[0] << endl;
	cout << &ptr[1] << endl;
	cout << &ptr[2] << endl;
	delete[] ptr;

	return 0;
}
