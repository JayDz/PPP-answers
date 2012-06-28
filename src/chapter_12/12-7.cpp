/*
	chapter 12 exercise 7
	page 434
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),600,400,"Exercise 7");

		Rectangle green_grass(Point(0,300),window.x_max(),100);
		green_grass.set_color(Color::green);
		green_grass.set_fill_color(Color::green);

		Circle sun(Point(0,0),100);
		sun.set_color(Color::yellow);
		sun.set_fill_color(Color::yellow);

		Rectangle house(Point(130,150),290,200);
		
		Polygon roof;
		roof.add(Point(275,25));
		roof.add(Point(50,150));
		roof.add(Point(500,150));

		Rectangle front_door(Point(245,230),50,70);

		Circle door_knob(Point(255,270),5);
		door_knob.set_fill_color(Color::black);

		Rectangle window1(Point(255,110),50,40);
		Rectangle frame1(Point(255,110),25,40);
		Rectangle frame2(Point(255,110),50,20);

		Rectangle window2(Point(350,245),50,40);
		Rectangle frame3(Point(350,245),25,40);
		Rectangle frame4(Point(350,245),50,20);

		Polygon chime;
		chime.add(Point(410,100));
		chime.add(Point(450,100));
		chime.add(Point(450,121));

		window.attach(chime);
		window.attach(window2);
		window.attach(frame3);
		window.attach(frame4);
		window.attach(frame2);
		window.attach(frame1);
		window.attach(window1);
		window.attach(door_knob);
		window.attach(front_door);
		window.attach(roof);
		window.attach(house);
		window.attach(sun);
		window.attach(green_grass);
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
