/*
	exercise 3 chapter 25
	page 946
*/
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	signed int pattern;
	cout << "SIGNED INT---------------------\n";

	//All zeros
	pattern = 0x00000000;
	cout << "All zeros: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//All ones
	pattern = ~pattern;
	cout << "All ones: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//Alternating ones and zeros
	pattern = pattern & 0xAAAAAAAA;
	cout << "Alternating ones and zeros: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//Alternating zeros and ones
	pattern = ~pattern;
	cout << "Alternating zeros and ones: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//1100 pattern
	pattern = pattern ^ 0x99999999;
	cout << "1100 pattern: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";
	
	//0011 pattern
	pattern = pattern ^ 0xFFFFFFFF;
	cout << "0011 pattern: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//all-one bytes and all-zero bytes pattern
	pattern = pattern ^ 0xCC33CC33;
	cout << "all-one bytes and all-zero bytes: " << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//all-zero bytes and all-ones bytes pattern
	pattern = ~pattern;
	cout << "all-zero bytes and all-ones bytes:" << pattern << '\n';
	cout << bitset<8*sizeof(signed int)>(pattern) << "\n\n";

	//---------------------------------------------------------------
	
	unsigned int pattern2;
	cout << "UNSIGNED INT---------------------\n";

	//All zeros
	pattern2 = 0x00000000;
	cout << "All zeros: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	//All ones
	pattern2 = ~pattern2;
	cout << "All ones: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	//Alternating ones and zeros
	pattern2 = pattern2 & 0xAAAAAAAA;
	cout << "Alternating ones and zeros: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	//Alternating zeros and ones
	pattern2 = ~pattern2;
	cout << "Alternating zeros and ones: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	//1100 pattern
	pattern2 = pattern2 ^ 0x99999999;
	cout << "1100 pattern: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";
	
	//0011 pattern
	pattern2 = pattern2 ^ 0xFFFFFFFF;
	cout << "0011 pattern: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	//all-one bytes and all-zero bytes pattern
	pattern2 = pattern2 ^ 0xCC33CC33;
	cout << "all-one bytes and all-zero bytes: " << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	//all-zero bytes and all-ones bytes pattern
	pattern2 = ~pattern2;
	cout << "all-zero bytes and all-ones bytes:" << pattern2 << '\n';
	cout << bitset<8*sizeof(unsigned int)>(pattern2) << "\n\n";

	return 0;
}
