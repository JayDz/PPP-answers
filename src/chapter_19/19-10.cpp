/*
	chapter 19 exercise 10
	page 683
*/
#include "std_lib_facilities.h"

template<class T> class _auto_ptr {
	T* ptr;
	bool destroy;
public:
	_auto_ptr(T* p): ptr(p),destroy(true){ }
	~_auto_ptr() {  if (ptr && destroy) delete ptr; }

	T* release();
	T& operator*();
	const T& operator*()const;
	T* operator->();
	const T* operator->()const;
};

template<class T> T* _auto_ptr<T>::release()
{
	destroy = false;
	return ptr;
}

template<class T> T& _auto_ptr<T>::operator*()
{
	return *ptr;
}

template<class T> const T& _auto_ptr<T>::operator*()const
{
	return *ptr;
}

template<class T> T* _auto_ptr<T>::operator->()
{
	return ptr;
}

template<class T> const T* _auto_ptr<T>::operator->()const
{
	return ptr;
}

void* f()
{
	_auto_ptr<int> a(new int);
	*a = 100;
	return a.release();
}

int main()
{
	int* ptr = reinterpret_cast<int*>(f());
	cout << *ptr << endl;
	delete ptr;

	_auto_ptr<vector<int> > va(new vector<int>(2));
	(*va)[0] = 21;
	(*va)[1] = 22;
	
	cout << va->at(0) << " " << va->at(1) << endl;
	return 0;
}
