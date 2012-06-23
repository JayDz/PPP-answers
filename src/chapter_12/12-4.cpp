/*
	chapter 12 exercise 4
	page 434
	NOTE: Could be WAY shorter if the use of vector<Rectangle> was possible, 
	or arrays (which haven't been covered yet).
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	try {
		Simple_window window(Point(100,100),500,500,"Exercise 4");
		Point p(50,50);
		int w = 50;
		int h = 50;
		const int pixel_shift = 50;

		//begin mess, sigh
		Rectangle r1(p,w,h);
		r1.set_color(Color::white);
		r1.set_fill_color(Color::white);
		window.attach(r1);
		
		p.x += pixel_shift;
		Rectangle r2(p,w,h);
		r2.set_color(Color::red);
		r2.set_fill_color(Color::red);
		window.attach(r2);

		p.x += pixel_shift;
		Rectangle r3(p,w,h);
		r3.set_color(Color::white);
		r3.set_fill_color(Color::white);
		window.attach(r3);
		
		p.x += pixel_shift;
		Rectangle r4(p,w,h);
		r4.set_color(Color::red);
		r4.set_fill_color(Color::red);
		window.attach(r4);

		p.x += pixel_shift;
		Rectangle r5(p,w,h);
		r5.set_color(Color::white);
		r5.set_fill_color(Color::white);
		window.attach(r5);

		p.x += pixel_shift;
		Rectangle r6(p,w,h);
		r6.set_color(Color::red);
		r6.set_fill_color(Color::red);
		window.attach(r6);

		p.x += pixel_shift;
		Rectangle r7(p,w,h);
		r7.set_color(Color::white);
		r7.set_fill_color(Color::white);
		window.attach(r7);

		p.x += pixel_shift;
		Rectangle r8(p,w,h);
		r8.set_color(Color::red);
		r8.set_fill_color(Color::red);
		window.attach(r8);
		//End of first row----------------------------------
		p.y += pixel_shift;
		p.x = 50;

		Rectangle r9(p,w,h);
		r9.set_color(Color::red);
		r9.set_fill_color(Color::red);
		window.attach(r9);

		p.x += pixel_shift;
		Rectangle r10(p,w,h);
		r10.set_color(Color::white);
		r10.set_fill_color(Color::white);
		window.attach(r10);
		
		p.x += pixel_shift;
		Rectangle r11(p,w,h);
		r11.set_color(Color::red);
		r11.set_fill_color(Color::red);
		window.attach(r11);

		p.x += pixel_shift;
		Rectangle r12(p,w,h);
		r12.set_color(Color::white);
		r12.set_fill_color(Color::white);
		window.attach(r12);

		p.x += pixel_shift;
		Graph_lib::Rectangle r13(p,w,h);
		r13.set_color(Color::red);
		r13.set_fill_color(Color::red);
		window.attach(r13);

		p.x += pixel_shift;
		Rectangle r14(p,w,h);
		r14.set_color(Color::white);
		r14.set_fill_color(Color::white);
		window.attach(r14);

		p.x += pixel_shift;
		Rectangle r15(p,w,h);
		r15.set_color(Color::red);
		r15.set_fill_color(Color::red);
		window.attach(r15);
		
		p.x += pixel_shift;
		Rectangle r16(p,w,h);
		r16.set_color(Color::white);
		r16.set_fill_color(Color::white);
		window.attach(r16);
		//end of second row----------------------
		p.y += pixel_shift;
		p.x = 50;

		Rectangle r17(p,w,h);
		r17.set_color(Color::white);
		r17.set_fill_color(Color::white);
		window.attach(r17);
		
		p.x += pixel_shift;
		Rectangle r18(p,w,h);
		r18.set_color(Color::red);
		r18.set_fill_color(Color::red);
		window.attach(r18);

		p.x += pixel_shift;
		Rectangle r19(p,w,h);
		r19.set_color(Color::white);
		r19.set_fill_color(Color::white);
		window.attach(r19);
		
		p.x += pixel_shift;
		Rectangle r20(p,w,h);
		r20.set_color(Color::red);
		r20.set_fill_color(Color::red);
		window.attach(r20);

		p.x += pixel_shift;
		Rectangle r21(p,w,h);
		r21.set_color(Color::white);
		r21.set_fill_color(Color::white);
		window.attach(r21);

		p.x += pixel_shift;
		Rectangle r22(p,w,h);
		r22.set_color(Color::red);
		r22.set_fill_color(Color::red);
		window.attach(r22);

		p.x += pixel_shift;
		Rectangle r23(p,w,h);
		r23.set_color(Color::white);
		r23.set_fill_color(Color::white);
		window.attach(r23);

		p.x += pixel_shift;
		Rectangle r24(p,w,h);
		r24.set_color(Color::red);
		r24.set_fill_color(Color::red);
		window.attach(r24);
		//end of third row-------------------------
		p.y += pixel_shift;
		p.x = 50;
		
		Rectangle r25(p,w,h);
		r25.set_color(Color::red);
		r25.set_fill_color(Color::red);
		window.attach(r25);

		p.x += pixel_shift;
		Rectangle r26(p,w,h);
		r26.set_color(Color::white);
		r26.set_fill_color(Color::white);
		window.attach(r26);

		p.x += pixel_shift;
		Rectangle r27(p,w,h);
		r27.set_color(Color::red);
		r27.set_fill_color(Color::red);
		window.attach(r27);

		p.x += pixel_shift;
		Rectangle r28(p,w,h);
		r28.set_color(Color::white);
		r28.set_fill_color(Color::white);
		window.attach(r28);

		p.x += pixel_shift;
		Rectangle r29(p,w,h);
		r29.set_color(Color::red);
		r29.set_fill_color(Color::red);
		window.attach(r29);

		p.x += pixel_shift;
		Rectangle r30(p,w,h);
		r30.set_color(Color::white);
		r30.set_fill_color(Color::white);
		window.attach(r30);

		p.x += pixel_shift;
		Rectangle r31(p,w,h);
		r31.set_color(Color::red);
		r31.set_fill_color(Color::red);
		window.attach(r31);
		
		p.x += pixel_shift;
		Rectangle r32(p,w,h);
		r32.set_color(Color::white);
		r32.set_fill_color(Color::white);
		window.attach(r32);
		//end of fourth row-------------------
		p.y += pixel_shift;
		p.x = 50;

		Rectangle r33(p,w,h);
		r33.set_color(Color::white);
		r33.set_fill_color(Color::white);
		window.attach(r33);
		
		p.x += pixel_shift;
		Rectangle r34(p,w,h);
		r34.set_color(Color::red);
		r34.set_fill_color(Color::red);
		window.attach(r34);

		p.x += pixel_shift;
		Rectangle r35(p,w,h);
		r35.set_color(Color::white);
		r35.set_fill_color(Color::white);
		window.attach(r35);
		
		p.x += pixel_shift;
		Rectangle r36(p,w,h);
		r36.set_color(Color::red);
		r36.set_fill_color(Color::red);
		window.attach(r36);

		p.x += pixel_shift;
		Rectangle r37(p,w,h);
		r37.set_color(Color::white);
		r37.set_fill_color(Color::white);
		window.attach(r37);

		p.x += pixel_shift;
		Rectangle r38(p,w,h);
		r38.set_color(Color::red);
		r38.set_fill_color(Color::red);
		window.attach(r38);

		p.x += pixel_shift;
		Rectangle r39(p,w,h);
		r39.set_color(Color::white);
		r39.set_fill_color(Color::white);
		window.attach(r39);

		p.x += pixel_shift;
		Rectangle r40(p,w,h);
		r40.set_color(Color::red);
		r40.set_fill_color(Color::red);
		window.attach(r40);
		//end of fifth row-------------------------
		p.y += pixel_shift;
		p.x = 50;
		
		Rectangle r41(p,w,h);
		r41.set_color(Color::red);
		r41.set_fill_color(Color::red);
		window.attach(r41);

		p.x += pixel_shift;
		Rectangle r42(p,w,h);
		r42.set_color(Color::white);
		r42.set_fill_color(Color::white);
		window.attach(r42);

		p.x += pixel_shift;
		Rectangle r43(p,w,h);
		r43.set_color(Color::red);
		r43.set_fill_color(Color::red);
		window.attach(r43);

		p.x += pixel_shift;
		Rectangle r44(p,w,h);
		r44.set_color(Color::white);
		r44.set_fill_color(Color::white);
		window.attach(r44);

		p.x += pixel_shift;
		Rectangle r45(p,w,h);
		r45.set_color(Color::red);
		r45.set_fill_color(Color::red);
		window.attach(r45);

		p.x += pixel_shift;
		Rectangle r46(p,w,h);
		r46.set_color(Color::white);
		r46.set_fill_color(Color::white);
		window.attach(r46);

		p.x += pixel_shift;
		Rectangle r47(p,w,h);
		r47.set_color(Color::red);
		r47.set_fill_color(Color::red);
		window.attach(r47);
		
		p.x += pixel_shift;
		Rectangle r48(p,w,h);
		r48.set_color(Color::white);
		r48.set_fill_color(Color::white);
		window.attach(r48);
		//end of sixth row---------------------------
		p.y += pixel_shift;
		p.x = 50;

		Rectangle r49(p,w,h);
		r49.set_color(Color::white);
		r49.set_fill_color(Color::white);
		window.attach(r49);
		
		p.x += pixel_shift;
		Rectangle r50(p,w,h);
		r50.set_color(Color::red);
		r50.set_fill_color(Color::red);
		window.attach(r50);

		p.x += pixel_shift;
		Rectangle r51(p,w,h);
		r51.set_color(Color::white);
		r51.set_fill_color(Color::white);
		window.attach(r51);
		
		p.x += pixel_shift;
		Rectangle r52(p,w,h);
		r52.set_color(Color::red);
		r52.set_fill_color(Color::red);
		window.attach(r52);

		p.x += pixel_shift;
		Rectangle r53(p,w,h);
		r53.set_color(Color::white);
		r53.set_fill_color(Color::white);
		window.attach(r53);

		p.x += pixel_shift;
		Rectangle r54(p,w,h);
		r54.set_color(Color::red);
		r54.set_fill_color(Color::red);
		window.attach(r54);

		p.x += pixel_shift;
		Rectangle r55(p,w,h);
		r55.set_color(Color::white);
		r55.set_fill_color(Color::white);
		window.attach(r55);

		p.x += pixel_shift;
		Rectangle r56(p,w,h);
		r56.set_color(Color::red);
		r56.set_fill_color(Color::red);
		window.attach(r56);
		//end of seventh row-------------------------
		p.y += pixel_shift;
		p.x = 50;
		
		Rectangle r57(p,w,h);
		r57.set_color(Color::red);
		r57.set_fill_color(Color::red);
		window.attach(r57);

		p.x += pixel_shift;
		Rectangle r58(p,w,h);
		r58.set_color(Color::white);
		r58.set_fill_color(Color::white);
		window.attach(r58);

		p.x += pixel_shift;
		Rectangle r59(p,w,h);
		r59.set_color(Color::red);
		r59.set_fill_color(Color::red);
		window.attach(r59);

		p.x += pixel_shift;
		Rectangle r60(p,w,h);
		r60.set_color(Color::white);
		r60.set_fill_color(Color::white);
		window.attach(r60);

		p.x += pixel_shift;
		Rectangle r61(p,w,h);
		r61.set_color(Color::red);
		r61.set_fill_color(Color::red);
		window.attach(r61);

		p.x += pixel_shift;
		Rectangle r62(p,w,h);
		r62.set_color(Color::white);
		r62.set_fill_color(Color::white);
		window.attach(r62);

		p.x += pixel_shift;
		Rectangle r63(p,w,h);
		r63.set_color(Color::red);
		r63.set_fill_color(Color::red);
		window.attach(r63);
		
		p.x += pixel_shift;
		Rectangle r64(p,w,h);
		r64.set_color(Color::white);
		r64.set_fill_color(Color::white);
		window.attach(r64);


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
