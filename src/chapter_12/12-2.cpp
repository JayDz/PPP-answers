/*
	chapter 12 exercise 2
	page 434
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),600,400,"Exercise 2");

		Rectangle rect(Point(250,150),100,30);
		Text label(Point(275,170),"Howdy!");

		window.attach(rect);
		window.attach(label);

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
