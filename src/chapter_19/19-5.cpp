/*
	chapter 19 exercise 5
	page 682
*/
#include "std_lib_facilities.h"

class Int {
public:
	Int();
	explicit Int(int);
	Int(const Int&);
	Int& operator=(const Int&);

	Int operator+(const Int&);
	Int operator-(const Int&);
	Int operator*(const Int&);
	Int operator/(const Int&);
	
	void set_value(int);
	int value()const;
private:
	int val;
};

Int::Int(): val(0){}
Int::Int(const Int& v): val(v.val){}
Int::Int(int v): val(v) {}

Int& Int::operator=(const Int& v)
{
	if (this != &v)
		val = v.val;
	return *this;
}

Int Int::operator+(const Int& v)
{
	return Int(val + v.val);
}
Int Int::operator-(const Int& v)
{
	return Int(val - v.val);
}
Int Int::operator*(const Int& v)
{
	return Int(val * v.val);
}
Int Int::operator/(const Int& v)
{
	if (v.val != 0)
		return Int(val / v.val);
	return Int();
}

void Int::set_value(int n)
{
	val = n;
}

int Int::value()const 
{
	return val;
}

ostream& operator<<(ostream& os, const Int& val)
{
	os << val.value() << endl;
	return os;
}

istream& operator>>(istream& is, Int& val)
{
	int v;
	is >> v;
	val.set_value(v);
	return is;
}

int main()
{
	Int i(10);
	Int j(20);
	j = i;
	Int k = i + j;
	Int m = i - j;
	Int n = j / i;
	Int p = i * j;

	cout << i;
	cout << j;
	cout << k;
	cout << m;
	cout << n;
	cout << p;
	
	return 0;
}
