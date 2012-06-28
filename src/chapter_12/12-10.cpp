/*
	chapter 12 exercise 10
	page 435
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	try {
		Simple_window window(Point(100,30),600,700,"Exercise 10");

		//arrows (lines).
		Graph_lib::Line line1(Point(195,570),Point(230,495));
		Graph_lib::Line line2(Point(195,570),Point(125,300));
		Graph_lib::Line line3(Point(100,460),Point(120,300));
		Graph_lib::Line line4(Point(265,500),Point(435,425));
		Graph_lib::Line line5(Point(325,500),Point(325,300));
		Graph_lib::Line line6(Point(510,460),Point(475,390));
		Graph_lib::Line line7(Point(255,375),Point(315,300));
		Graph_lib::Line line8(Point(470,100),Point(380,50));
		Graph_lib::Line line9(Point(345,200),Point(345,50));
		Graph_lib::Line line10(Point(525,430),Point(355,50));
		Graph_lib::Line line11(Point(130,250),Point(130,120));
		Graph_lib::Line line12(Point(130,250),Point(345,50));
		Graph_lib::Line line13(Point(160,130),Point(290,220));
		Graph_lib::Line line14(Point(415,260),Point(525,390));


		window.attach(line1);
		window.attach(line2);
		window.attach(line3);
		window.attach(line4);
		window.attach(line5);
		window.attach(line6);
		window.attach(line7);
		window.attach(line8);
		window.attach(line9);
		window.attach(line10);
		window.attach(line11);
		window.attach(line12);
		window.attach(line13);
		window.attach(line14);
		
		Graph_lib::Rectangle r1(Point(285,50),120,50);
		r1.set_fill_color(Color::yellow);
		Graph_lib::Rectangle r2(Point(282,45),120,50);
		r2.set_fill_color(Color::yellow);
		Graph_lib::Rectangle r3(Point(279,40),120,50);
		r3.set_fill_color(Color::yellow);
		Graph_lib::Text text1(Point(295,75),"FLTK headers");

		window.attach(r3);
		window.attach(r2);
		window.attach(r1);
		window.attach(text1);

		Graph_lib::Rectangle r4(Point(450,100),120,50);
		r4.set_fill_color(Color::yellow);
		Graph_lib::Rectangle r5(Point(447,95),120,50);
		r5.set_fill_color(Color::yellow);
		Graph_lib::Rectangle r6(Point(444,90),120,50);
		r6.set_fill_color(Color::yellow);
		Graph_lib::Text text2(Point(470,125),"FLTK code");

		window.attach(r6);
		window.attach(r5);
		window.attach(r4);
		window.attach(text2);

		Graph_lib::Rectangle r7(Point(50,100),150,35);
		r7.set_fill_color(Color::yellow);
		Graph_lib::Text text3(Point(50,95),"Point.h:");
		text3.set_font(Font::times_bold);
		Graph_lib::Text text4(Point(70,122),"struct Point{...};");
		text4.set_font(Font::times_bold);

		window.attach(r7);
		window.attach(text3);
		window.attach(text4);

		Graph_lib::Rectangle r8(Point(270,200),150,100);
		r8.set_fill_color(Color::yellow);
		Graph_lib::Text text5(Point(268,195),"Window.h");
		text5.set_font(Font::times_bold);
		Graph_lib::Text text6(Point(275,225),"// window interface:");
		Graph_lib::Text text7(Point(275,245),"class Window{...};");
		text7.set_font(Font::times_bold);

		window.attach(r8);
		window.attach(text5);
		window.attach(text6);
		window.attach(text7);

		Graph_lib::Rectangle r9(Point(50,250),150,95);
		r9.set_fill_color(Color::yellow);
		Graph_lib::Text text8(Point(50,245),"Graph.h:");
		text8.set_font(Font::times_bold);
		Graph_lib::Text text9(Point(54,270),"// graphing interface:");
		Graph_lib::Text text10(Point(54,290),"struct Shape{...};");
		text10.set_font(Font::times_bold);

		window.attach(r9);
		window.attach(text8);
		window.attach(text9);
		window.attach(text10);

		Graph_lib::Rectangle r10(Point(170,375),120,50);
		r10.set_fill_color(Color::yellow);
		Graph_lib::Text text11(Point(170,370),"window.cpp:");
		text11.set_font(Font::times_bold);
		Graph_lib::Text text12(Point(185,405),"Window code");
		text12.set_font(Font::times_bold);

		window.attach(r10);
		window.attach(text11);
		window.attach(text12);

		Graph_lib::Rectangle r11(Point(395,335),150,95);
		r11.set_fill_color(Color::yellow);
		Graph_lib::Text text13(Point(395,332),"GUI.h:");
		text13.set_font(Font::times_bold);
		Graph_lib::Text text14(Point(400,355),"// GUI interface:");
		Graph_lib::Text text15(Point(400,375),"struct In_box{...};");
		text15.set_font(Font::times_bold);

		window.attach(r11);
		window.attach(text13);
		window.attach(text14);
		window.attach(text15);

		Graph_lib::Rectangle r12(Point(20,460),120,50);
		r12.set_fill_color(Color::yellow);
		Graph_lib::Text text16(Point(20,458),"Graph.cpp:");
		text16.set_font(Font::times_bold);
		Graph_lib::Text text17(Point(40,490),"Graph code");
		text17.set_font(Font::times_bold);

		window.attach(r12);
		window.attach(text16);
		window.attach(text17);
		
		Graph_lib::Rectangle r13(Point(190,460),180,50);
		r13.set_fill_color(Color::yellow);
		Graph_lib::Text text18(Point(190,455),"Simple_window.h:");
		text18.set_font(Font::times_bold);
		Graph_lib::Text text19(Point(195,480),"// window interface:");
		Graph_lib::Text text20(Point(195,495),"class Simple_window{...};");
		text20.set_font(Font::times_bold);

		window.attach(r13);
		window.attach(text18);
		window.attach(text19);
		window.attach(text20);

		Graph_lib::Rectangle r14(Point(435,460),85,40);
		r14.set_fill_color(Color::yellow);
		Graph_lib::Text text21(Point(435,458),"GUI.cpp:");
		text21.set_font(Font::times_bold);
		Graph_lib::Text text22(Point(445,485),"GUI code");
		text22.set_font(Font::times_bold);

		window.attach(r14);
		window.attach(text21);
		window.attach(text22);

		Graph_lib::Rectangle r15(Point(90,570),200,95);
		r15.set_fill_color(Color::yellow);
		Graph_lib::Text text23(Point(90,565),"chapter12.cpp:");
		text23.set_font(Font::times_bold);
		Graph_lib::Text text24(Point(95,590),"#include \"Graph.h\" ");
		text24.set_font(Font::times_bold);
		Graph_lib::Text text25(Point(95,610),"#include \"Simple_window.h\" ");
		text25.set_font(Font::times_bold);
		Graph_lib::Text text26(Point(95,630),"int main(){...}");
		text26.set_font(Font::times_bold);

		window.attach(r15);
		window.attach(text23);
		window.attach(text24);
		window.attach(text25);
		window.attach(text26);

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
