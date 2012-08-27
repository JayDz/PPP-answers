/*
	chapter 21 exercise 6
	page 756

	Differences between implementations:
	By using set<Fruit,Fruit_order>, we use the copy mechanism which avoids
	the situation of the set having dangling pointers as set<Fruit*,Fruit_comparison>
	has when we reach the end of scope. Also, we must now deal with passing the lower 
	level pointers around (e.g. bool operator()(const Fruit* a, const Fruit* b)).
*/
#include "std_lib_facilities.h"
#include <set>

struct Date {
	//short version, no error checking.
	int month;
	int day;
	int year;

	Date(int m, int d, int y): month(m),day(d),year(y){}
};

struct Fruit {
	string name;
	int count;
	double unit_price;
	Date last_sale_date;

	Fruit(string n, int c, double up, Date date):
		name(n),count(c),unit_price(up),last_sale_date(date){}
};

struct Fruit_comparison {
	bool operator()(const Fruit* a, const Fruit* b)
	{
		return a->name < b->name;
	}
};

ostream& operator<<(ostream& os, const Fruit* f)
{
	os << f->name;
	return os;
}

int main()
{
	set<Fruit*,Fruit_comparison> fruits;
	
	//create fruits
	Fruit a("Apple",5,1.25,Date(4,27,2012));
	Fruit b("Cherry",3,0.40,Date(1,1,2012));
	Fruit c("Avocado",10,1.00,Date(12,25,2012));
	Fruit d("jambul",4,3.50,Date(11,11,2012));
	Fruit e("Eggplant",15,2.40,Date(3,1,2012));
	Fruit f("Grape",20,0.75,Date(8,27,2012));

	fruits.insert(&a);
	fruits.insert(&b);
	fruits.insert(&c);
	fruits.insert(&d);
	fruits.insert(&e);
	fruits.insert(&f);

	for (set<Fruit*,Fruit_comparison>::const_iterator p	= fruits.begin(); p != fruits.end(); ++p)
		cout << *p << endl;

	return 0;
}
