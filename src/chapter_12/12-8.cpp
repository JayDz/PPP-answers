/*
	chapter 12 exercise 8
	page 435
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),600,400,"Exercise 8");

		Circle blue(Point(170,150),50);
		blue.set_style(Line_style(Line_style::solid,5));
		blue.set_color(Color::blue);

		Circle black(Point(285,150),50);
		black.set_style(Line_style(Line_style::solid,5));
		black.set_color(Color::black);

		Circle red(Point(400,150),50);
		red.set_style(Line_style(Line_style::solid,5));
		red.set_color(Color::red);

		Circle yellow(Point(225,200),50);
		yellow.set_style(Line_style(Line_style::solid,5));
		yellow.set_color(Color::yellow);

		Circle green(Point(340,200),50);
		green.set_style(Line_style(Line_style::solid,5));
		green.set_color(Color::green);

		window.attach(blue);
		window.attach(black);
		window.attach(red);
		window.attach(yellow);
		window.attach(green);
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
