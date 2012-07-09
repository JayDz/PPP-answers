/*
	chapter 19 exercise 3
	page 682
*/
#include "std_lib_facilities.h"

template<class N,class V>
class Pair {
public:
	Pair(N name, V value);
	N n;
	V v;
};

template<class N,class V> Pair<N,V>::Pair(N name, V value)
	:n(name),v(value){}

template<class N,class V>
class Table {
public:
	V get(N);
	void set(N n,V v);
	V declare(N n, V v);
private:
	vector<Pair<N,V> > pair_table;
	bool is_declared(N n);
};

template<class N,class V> V Table<N,V>::get(N n)
{
	for (int i = 0; i < pair_table.size(); ++i)
		if (n == pair_table[i].n)
				return pair_table[i].v;
	error("get: undefined variable ", n);
}

template<class N,class V> void Table<N,V>::set(N n, V v)
{
	for (int i = 0; i < pair_table.size(); ++i) {
		if (pair_table[i].n == n) {
			pair_table[i].v = v;
			return;
		}
	}
	error("set: undefined variable ", n);
}

template<class N,class V> bool Table<N,V>::is_declared(N n)
{
	for (int i = 0; i < pair_table.size(); ++i)
		if (pair_table[i].n == n)
			return true;
	return false;
}

template<class N,class V> V Table<N,V>::declare(N n, V v)
{
	if (is_declared(n)) error(n, " declared twice");
	pair_table.push_back(Pair<N,V>(n,v));
	return v;
}

int main()
{
	try {
		Table<string,int> table;
		table.declare("x",10);
		table.declare("y",20);

		cout << table.get("x") << endl;
		cout << table.get("y") << endl;

		table.set("x",100);
		table.set("y",200);

		cout << table.get("x") << endl;
		cout << table.get("y") << endl;
	}
	catch(exception& e) {
		cerr << e.what() << endl;
	}
	return 0;
}
