/*
	chapter 12 exercise 1
	page 434
*/
#include "std_lib_facilities.h" //for exception type.
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),600,400,"Exercise one");

		Rectangle r(Point(100,100),200,100);
		r.set_color(Color::blue);

		Polygon p;
		p.add(Point(300,100));
		p.add(Point(500,100));
		p.add(Point(500,200));
		p.add(Point(300,200));
		p.set_color(Color::red);

		window.attach(r);
		window.attach(p);

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
