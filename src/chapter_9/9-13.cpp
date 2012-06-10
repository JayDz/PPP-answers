/*
	chapter 9 exercise 13
	page 335
*/
#include "std_lib_facilities.h"

class Rational {
public:
	Rational(int n, int d);

	void set_denominator(int d);
	void set_numerator(int n);
	int get_denominator() const { return denominator; }
	int get_numerator() const { return numerator; }
	
	double convert_to_double() const;
	void reduce();
	class Divide_by_zero_error { };

	Rational& operator=(const Rational& right_hand);
private:
	int numerator;
	int denominator;
};

// Code taken from: http://www.stroustrup.com/Programming/Solutions/Ch9/e9-13.cpp
int gcd(int x, int y)
	// greatest common denominator
	// Euclid's algorithm (using remainder)
{
	x = abs(x);
	y = abs(y);
	while (y) {
		int t = y;
		y = x%y;
		x = t;
	}
	return x;
}

bool is_valid_denom(int d)
{
	if (d != 0) return true;
	return false;
}

Rational::Rational(int n, int d) 
	:numerator(n),denominator(d)
{
	if (!is_valid_denom(d)) throw Divide_by_zero_error();
	reduce();
}

void Rational::reduce()
{
	int cd = gcd(numerator,denominator);
	if (cd > 1) {
		numerator /= cd;
		denominator /= cd;
	}
}

void Rational::set_numerator(int n)
{
	numerator = n;
	reduce();
}

void Rational::set_denominator(int d)
{
	if (!is_valid_denom(d)) throw Divide_by_zero_error();
	denominator = d;
	reduce();
}

double Rational::convert_to_double() const
{
	return double(numerator) / denominator;
}

Rational& Rational::operator=(const Rational& right_hand)
{
	set_numerator(right_hand.get_numerator());
	set_denominator(right_hand.get_denominator());
	return *this;
}

Rational operator+(const Rational& left, const Rational& right)
{
	int l_numerator = left.get_numerator();
	int l_denom     = left.get_denominator();
	int r_numerator = right.get_numerator();
	int r_denom     = right.get_denominator();
	
	if (l_denom != r_denom) {
		l_numerator *= r_denom;
		l_denom     *= r_denom;

		r_numerator *= l_denom;
		r_denom     *= l_denom;
	}
	return Rational(l_numerator + r_numerator, l_denom);
}

Rational operator-(const Rational& left, const Rational& right)
{
	int l_numerator = left.get_numerator();
	int l_denom     = left.get_denominator();
	int r_numerator = right.get_numerator();
	int r_denom     = right.get_denominator();

	if (l_denom != r_denom) {
		l_numerator *= r_denom;
		l_denom     *= r_denom;

		r_numerator *= l_denom;
		r_denom     *= l_denom;
	}

	return Rational(l_numerator - r_numerator, l_denom);
}

Rational operator*(const Rational& left, const Rational& right)
{
	return Rational(left.get_numerator()*right.get_numerator(),
					left.get_denominator()*right.get_denominator());
}

Rational operator/(const Rational& left, const Rational& right)
{
	return Rational(left.get_numerator()*right.get_denominator(),
					left.get_denominator()*right.get_numerator());
}

bool operator==(const Rational& left, const Rational& right)
{
	return ((left.get_numerator() == right.get_numerator()) && 
			left.get_denominator() == right.get_denominator());
}

bool operator!=(const Rational& left, const Rational& right)
{
	return !(left == right);
}

int main()
{
	try {
		int n1 = 2;
		int d1 = 4;
		Rational r1(n1,d1);

		int n2 = 4;
		int d2 = 8;
		Rational r2(n2,d2);

		Rational temp = r1/r2;
		cout << r1.get_numerator() << "/" << r1.get_denominator() << " divided by " 
			<< r2.get_numerator() << "/" << r2.get_denominator()
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;
		
		temp = r1*r2;	
		cout << r1.get_numerator() << "/" << r1.get_denominator() << " multiplied by " 
			<< r2.get_numerator() << "/" << r2.get_denominator()
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;

		temp = r1+r2;
		cout << r1.get_numerator() << "/" << r1.get_denominator() << " plus " 
			<< r2.get_numerator() << "/" << r2.get_denominator()
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;
		
		temp = r1-r2;
		cout << r1.get_numerator() << "/" << r1.get_denominator() << " minus " 
			<< r2.get_numerator() << "/" << r2.get_denominator()
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;

		cout << "Is " << n1 << "/" << d1 << " == " << n2 << "/" << d2 << "? "
			<< (r1 == r2) << endl;

		cout << "Is " << n1 << "/" << d1 << " != " << n2 << "/" << d2 << "? "
			<< (r1 != r2) << endl;
	}
	catch(Rational::Divide_by_zero_error e) {
		cerr << "Cannot divide by zero.\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
