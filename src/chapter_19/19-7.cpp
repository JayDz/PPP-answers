/*
	chapter 19 exercise 7
	page 682
*/
#include "std_lib_facilities.h"

template<class T>
class Number {
public:
	Number();
	explicit Number(T);
	Number(const Number<T>&);
	Number<T>& operator=(const Number<T>&);

	Number<T> operator+(const Number<T>&);
	Number<T> operator-(const Number<T>&);
	Number<T> operator*(const Number<T>&);
	Number<T> operator/(const Number<T>&);
	Number<T> operator%(const Number<T>&);

	void set_value(T);
	T value()const;
private:
	T val;
};

template<class T> Number<T>::Number(): val(0){}
template<class T> Number<T>::Number(const Number<T>& v): val(v.val){}
template<class T> Number<T>::Number(T v): val(v) {}

template<class T> Number<T>& Number<T>::operator=(const Number<T>& v)
{
	if (this != &v)
		val = v.val;
	return *this;
}

template<class T> Number<T> Number<T>::operator+(const Number<T>& v)
{
	return Number<T>(val + v.val);
}

template<class T> Number<T> Number<T>::operator-(const Number<T>& v)
{
	return Number<T>(val - v.val);
}

template<class T> Number<T> Number<T>::operator*(const Number<T>& v)
{
	return Number<T>(val * v.val);
}

template<class T> Number<T> Number<T>::operator/(const Number<T>& v)
{
	if (v.val != 0)
		return Number<T>(val / v.val);
	return Number<T>();
}

template<class T> Number<T> Number<T>::operator%(const Number<T>& v)
{
	return Number<T>(val % v.val);
}

template<class T> void Number<T>::set_value(T n)
{
	val = n;
}

template<class T> T Number<T>::value()const 
{
	return val;
}

template<class T> ostream& operator<<(ostream& os, const Number<T>& val)
{
	os << val.value() << endl;
	return os;
}

template<class T> istream& operator>>(istream& is, Number<T>& val)
{
	int v;
	is >> v;
	val.set_value(v);
	return is;
}

template<class T,class U> double f(vector<T>& vt, vector<U>& vu)
	//Unfortunately, this function needed to be changed. For example, we removed the
	//const qualifier from the parameters, and changed the syntax from sum += to sum = sum +.
	//Also, sum had to be made a paramerized type.
{
	T sum;
	int i = 0;
	while (i < vt.size() && i < vu.size()) {
		sum = sum + (vt[i]*vu[i]);
		++i;
	}
	return sum.value();
}

int main()
{
	vector<Number<int> > v1;
	vector<Number<int> > v2;

	v1.push_back(Number<int>(2));
	v1.push_back(Number<int>(3));
	v2.push_back(Number<int>(4));
	v2.push_back(Number<int>(5));

	cout << "The sum is: " << f(v1,v2) << endl; //output should be 23
	return 0;
}
