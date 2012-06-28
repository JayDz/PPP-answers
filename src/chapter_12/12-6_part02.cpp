/*
	chapter 12 exercise 6 part 2 - Window that doesn't fit on screen.
	page 434
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		// Windows will attempt to fit the oversized application window,
		// causing the borders of the window to become unreachable.
		Simple_window window(Point(100,100),13000,800,"Exercise 6");
		window.wait_for_button();
	}
	catch(exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	catch(...) {
		return 2;
	}
	return 0;
}
