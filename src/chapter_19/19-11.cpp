/*
	chapter 19 exercise 11
	page 683
*/
#include "std_lib_facilities.h"

template<class T> class counted_ptr {
	T* ptr;
	int* count;
public:
	counted_ptr(): ptr(new T()),count(new int(1)) { }
	counted_ptr(const counted_ptr& p)
	{
		ptr   = p.ptr;
		count = p.count;
		
		*count += 1;
	}
	
	counted_ptr& operator=(const counted_ptr& p)
	{
		*count -= 1;
		ptr   = p.ptr;
		count = p.count;

		*count += 1;
		return *this;
	}
	
	~counted_ptr() 
	{
		if (*count > 0)
			*count -= 1;
		if (*count == 0) {
			delete ptr;
			ptr = 0;
		}
	}

	T& operator*();
	const T& operator*()const;
	T* operator->();
	const T* operator->()const;
	
	//small debug function.
	void print() { cout << "count is: " <<  *count << endl; }
};

template<class T> T& counted_ptr<T>::operator*()
{
	return *ptr;
}

template<class T> const T& counted_ptr<T>::operator*()const
{
	return *ptr;
}

template<class T> T* counted_ptr<T>::operator->()
{
	return ptr;
}

template<class T> const T* counted_ptr<T>::operator->()const
{
	return ptr;
}

void f()
{
	counted_ptr<int> a;
	*a = 100;
	counted_ptr<int> a2 = a;
	a.print(); //should output 2

	counted_ptr<int> b;
	*b = 200;
	counted_ptr<int> b2 = b;
	counted_ptr<int> b3 = b2;
	counted_ptr<int> b4 = b3;
	b.print(); //should output 4

	b = a;
	b.print(); //should output 3
	cout << *b << endl; //should output 100

	b2.print(); //should output 3
	cout << *b4 << endl; //should output 200
}

int main()
{
	f();
	counted_ptr<vector<int> > ptr;
	ptr->push_back(10);
	ptr->push_back(20);
	cout << (*ptr)[0] << endl; //should output 10
	cout << (*ptr)[1] << endl; //should output 20

	counted_ptr<vector<int> > ptr2 = ptr;
	ptr2.print(); //should output 2
	(*ptr2)[0] = 500;
	(*ptr2)[1] = 1000;
	cout << ptr->at(0) << endl; //should output 500
	cout << ptr->at(1) << endl; //should output 1000
	ptr.print(); //should output 2
	return 0;
}
