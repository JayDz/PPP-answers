/*
	chapter 12 exercise 9
	page 435
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),900,650,"Exercise 9 - The Beautiful picture");

		Image image(Point(0,0),"my_picture.jpg");
		Text caption(Point(350,630),"The beatiful picture.");

		window.attach(caption);
		window.attach(image);
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
