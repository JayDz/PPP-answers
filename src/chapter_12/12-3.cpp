/*
	chapter 12 exercise 3
	page 434
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),450,300,"Exercise 3");
		
		Line line(Point(150,100),Point(150,250));
		line.set_color(Color::magenta);
		line.set_style(Line_style(Line_style::solid,12));
		
		Line line2(Point(85,250),Point(156,250));
		line2.set_color(Color::magenta);
		line2.set_style(Line_style(Line_style::solid,12));

		Line line3(Point(100,100),Point(205,100));
		line3.set_color(Color::magenta);
		line3.set_style(Line_style(Line_style::solid,12));

		Line line4(Point(250,100),Point(250,250));
		line4.set_color(Color::blue);
		line4.set_style(Line_style(Line_style::solid,12));

		Line line5(Point(250,250),Point(360,180));
		line5.set_color(Color::blue);
		line5.set_style(Line_style(Line_style::solid,12));

		Line line6(Point(250,100),Point(360,180));
		line6.set_color(Color::blue);
		line6.set_style(Line_style(Line_style::solid,12));

		Circle c(Point(290,175),10);
		c.set_color(Color::blue);
		c.set_fill_color(Color::blue);

		window.attach(line);
		window.attach(line2);
		window.attach(line3);
		window.attach(line4);
		window.attach(line5);
		window.attach(line6);
		window.attach(c);
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
