/*
	chapter 12 exercise 5
	page 434
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),600,400,"Exercise 5");

		Point start_position(100,50);
		Rectangle r(start_position,396,300);
		r.set_color(Color::yellow);
		r.set_fill_color(Color::yellow);
		
		Polygon p;
		p.add(Point(start_position.x-1,start_position.y-1));
		p.add(Point(start_position.x+r.width(),start_position.y-1));
		p.add(Point(start_position.x+r.width(),start_position.y+r.height()));
		p.add(Point(start_position.x-1,start_position.y+r.height()));
		p.set_color(Color::red);

		window.attach(p);
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
