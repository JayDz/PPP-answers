/*
	chapter 19 exercise 6
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

int main()
{
	Number<int> i(10);
	Number<int> j(20);
	j = i;
	Number<int> k = i + j;
	Number<int> m = i - j;
	Number<int> n = j / i;
	Number<int> p = i * j;
	Number<int> q = i % j;
	
	Number<double> d(3.14);
	//The code below causes an error, since T can only be one type.
	//Number<double> dd = i % d;

	cout << i;
	cout << j;
	cout << k;
	cout << m;
	cout << n;
	cout << p;
	cout << q;
	cout << d;
	return 0;
}
