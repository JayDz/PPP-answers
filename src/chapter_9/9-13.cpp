/*
	chapter 9 exercise 13
	page 335
*/
#include "std_lib_facilities.h"

class Rational {
public:
	Rational(double n, double d);

	void set_denominator(double d);
	void set_numerator(double n);
	double get_denominator() const { return denominator; }
	double get_numerator() const { return numerator; }
	
	double convert_to_double() const;
	class Divide_by_zero_error { };

	Rational& operator=(const Rational& right_hand);
private:
	double numerator;
	double denominator;
};

bool is_valid_denom(double d)
{
	if (d != 0) return true;
	return false;
}

Rational::Rational(double n, double d) 
	:numerator(n),denominator(d)
{
	if (!is_valid_denom(d)) throw Divide_by_zero_error();
}

void Rational::set_numerator(double n)
{
	numerator = n;
}

void Rational::set_denominator(double d)
{
	if (!is_valid_denom(d)) throw Divide_by_zero_error();
	denominator = d;
}

double Rational::convert_to_double() const
{
	return numerator / denominator;
}

Rational& Rational::operator=(const Rational& right_hand)
{
	set_numerator(right_hand.get_numerator());
	set_denominator(right_hand.get_denominator());
	return *this;
}

Rational operator+(const Rational& left, const Rational& right)
{
	double l_numerator = left.get_numerator();
	double l_denom     = left.get_denominator();
	double r_numerator = right.get_numerator();
	double r_denom     = right.get_denominator();
	
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
	double l_numerator = left.get_numerator();
	double l_denom     = left.get_denominator();
	double r_numerator = right.get_numerator();
	double r_denom     = right.get_denominator();

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
		double n1 = 1;
		double d1 = 2;
		Rational r1(n1,d1);

		double n2 = 1;
		double d2 = 2;
		Rational r2(n2,d2);

		Rational temp = r1/r2;
		cout << n1 << "/" << d1 << " divided by " << n2 << "/" << d2
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;
		
		temp = r1*r2;	
		cout << n1 << "/" << d1 << " multiplied by " << n2 << "/" << d2
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;

		temp = r1+r2;
		cout << n1 << "/" << d1 << " plus " << n2 << "/" << d2
			<< " is: " << temp.get_numerator() << "/" << temp.get_denominator()
			<< " or " << temp.convert_to_double() << endl;
		
		temp = r1-r2;
		cout << n1 << "/" << d1 << " minus " << n2 << "/" << d2
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
