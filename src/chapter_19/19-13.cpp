/*
	chapter 19 exercise 13
	page 683
*/
#include "std_lib_facilities.h"

class Tracer {
	string str;
public:
	explicit Tracer(string s);
	Tracer(const Tracer& t);

	Tracer& operator=(const Tracer& t);

	~Tracer();
};

Tracer::Tracer(string s)
	:str(s)
{
	cout << str << " Tracer::Tracer(string)" << endl;
}

Tracer::Tracer(const Tracer& t)
{
	str = t.str;
	cout << str << "Tracer::Tracer(const Tracer&)" << endl;
}

Tracer& Tracer::operator=(const Tracer& t)
{
	if (this != &t) 
		str = t.str;
	cout << str << " Tracer::operator=()" << endl;
	return *this;
}

Tracer::~Tracer()
{
	cout << str << " Tracer::~Tracer()" << endl;
}
//-----------------------------------------------------------------
Tracer globl("globl");

void f(Tracer f_copy)
{
	Tracer local_f("local_f");
}

void g()
{
	Tracer* local_g_fstore = new Tracer("local_g_store");
	delete local_g_fstore;
}

struct X { Tracer a; Tracer b; };

void h()
{
	X x = {Tracer("X.a"),Tracer("X.b")};
}

int main()
{
	Tracer local_main("local_main");
	f(local_main);

	g();
	h();

	Tracer local_main2("local_main2");
	local_main = local_main2;

	return 0;
}
