/*
	exercise 5 chapter 25
	page 946
*/
#include <iostream>

int main()
{
	int i = 0;

	while (i = 15) //an unfortunate common beginner bug, using assignment operator instead of equality operator.
		std::cout << "To infinity!\n";
	
	return 0;
}
