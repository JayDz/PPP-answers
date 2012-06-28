/*
	chapter 12 exercise 6 part 1 - Shape that doesn't fit inside window.
	page 434

	The section of the Shape that fits into the window is drawn, the other is ignored.
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),600,400,"Exercise 6");
		Circle r(Point(0,0),1000);
		r.set_fill_color(Color::black);

		window.attach(r);
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
