/*
	chapter 7 exercise 3
	page 251
*/
#include "std_lib_facilities.h"

// Follows Prof. Stroustrup's solution as shown in:
// http://www.stroustrup.com/Programming/Solutions/Ch7/e7-1.cpp

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const string constkey = "const";
const char con = 'C';

double expression();

class Variable {
public:
	string name;
	double value;
	bool is_var;
	Variable(string n, double v, bool c) :name(n), value(v), is_var(c) { }
};
vector<Variable> var_table;


double get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (s == var_table[i].name)
			return var_table[i].value;
	error("get: undefined variable ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) { 
			if (var_table[i].is_var)
				var_table[i].value = d;
			else
				error(s, " is const");
			return;
		}
		error("set: undefined variable", s);
}

class Token {
public:
	char kind; 
	double value; 
	string name;
	Token(char ch): kind(ch),value(0) { } 
	Token(char ch, double val): kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n){ }
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token);
	void ignore(char);
private:
	bool full;
	Token buffer;
};
Token_stream ts;

Token_stream::Token_stream()
	:full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("Full buffer.");
	buffer = t;
	full = true;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case print:
	case quit:
	case '(': 
	case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/': 
	case '%': 
	case '{': 
	case '}':
	case '=':
		return Token(ch);
	case '.': case '0': case '1': case '2': case '3': 
	case '4': case '5': case '6': case '7': case '8': 
	case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(number,val);
		}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let);
			if (s == constkey) return Token(con); 
			return Token(name,s);
		}
		error("Bad token");
	}
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("expected ')'");
			return d;
		}
	case '{':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != '}') error("expected '}'");
			return d;
		}
	case number:
		return t.value;
	case '-':
		return - primary();
	case '+':
		return primary();
	case name: 
		{
			Token next = ts.get();
			if (next.kind == '=') {
				double d = expression();
				set_value(t.name,d);
				return d;
			}
			else {
				ts.putback(next);
				return get_value(t.name);
			}
		}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			{
				double d = primary();
				if (d==0) error("Division by zero.");
				left /= d;
				t = ts.get();
				break;
			}
		case '%':
			{
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(term());
				if (i2 == 0) error("%: divide by zero");
				left = i1 % i2;
				t = ts.get();
				break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	
	while (true) {
		switch (t.kind) {
		case '+': 
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

bool is_declared(string var)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == var)
			return true;
	return false;
}

double define_name(string s, double val, bool var=false)
	// Taken from: http://www.stroustrup.com/Programming/Solutions/Ch7/e7-1.cpp
    // add (s,val,var) to var_table
{
    if (is_declared(s)) error(s," declared twice");
    var_table.push_back(Variable(s,val,var));
    return val;
}

double declaration(Token k)
	// Taken from: http://www.stroustrup.com/Programming/Solutions/Ch7/e7-1.cpp
	
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
	// k will be "let" or "con"(stant)
{
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name,d,k.kind==let);
    return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
	case con:
		return declaration(t.kind);
	default:
		ts.putback(t);
		return expression();
	}
}

void calculate()
{
	const string prompt = "> ";
	const string result = "= ";
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << statement() << endl;
		}
		catch (exception& e) {
			cerr << e.what() << endl;
			clean_up_mess();
		}
	}
}

int main()
{
	try {
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);
		calculate();
		return 0;
	}
	catch(exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	catch(...) {
		cerr << "exception\n";
		return 2;
	}
	return 0;
}
