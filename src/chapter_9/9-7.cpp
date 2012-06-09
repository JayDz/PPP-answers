/*
	chapter 9 exercise 7
	page 334
*/
#include "std_lib_facilities.h"

/********************************************************************/
// This should be in a file called Chrono.h
namespace Chrono {
	class Date {
	public:
		enum Month {
		jan = 1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
		};
		
		class Invalid { };
		
		Date(int y, Month m, int d);
		Date();

		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};
	
	bool is_date(int y, Date::Month m, int d);
	bool leapyear(int y);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
}
/********************************************************************/
// This should be in a file called Chrono.cpp
// Note: removed functions which were not implemented.
namespace Chrono {
	
	Date::Date(int yy, Month mm, int dd)
		:y(yy),m(mm),d(dd)
	{
		if (!is_date(yy,mm,dd)) throw Invalid();
	}
	
	Date& default_date()
	{
		static Date dd(2001,Date::jan,1);
		return dd;
	}
	
	Date::Date()
		:y(default_date().year()),
		m(default_date().month()),
		d(default_date().day())
	{
	}
	
	void Date::add_year(int n)
	{
		if (m == feb && d == 29 && !leapyear(y+n)) {
			m = mar;
			d = 1;
		}
		y+=n;
	}
	
	//helper functions
	
	bool is_date(int y, Date::Month m, int d)
	{
		if (d <= 0) return false;
		int days_in_month = 31;
		if (m < Date::jan || m > Date::dec) return false; //check for valid month.
		switch (m) {
		case Date::feb:
			days_in_month = (leapyear(y))?29:28;
			break;
		case Date::apr:
		case Date::jun:
		case Date::sep:
		case Date::nov:
			days_in_month = 30;
			break;
		}
		
		if (days_in_month < d) return false;
		
		return true;
	}
	
	bool leapyear(int y)
	{
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
				&& a.month() == b.month()
				&& a.day() == b.day();
	}
	
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
					<< ',' << d.month()
					<< ',' << d.day() << ')';
	}
	
	istream& operator>>(istream& is, Date& date)
	{
		int y,m,d;
		char ch1,ch2,ch3,ch4;
		
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
		return is;
	}
	
	enum Day { 
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};
}
/********************************************************************/
class Book {
public:
	enum Genre {
		fiction = 1, nonfiction, periodical, biography, children
	};
	Book(string _isbn,string _title, string _author, Chrono::Date d, Book::Genre g, bool avai);
	string get_isbn() const { return isbn; }
	string get_title() const { return title;}
	string get_author() const { return author; } 
	Chrono::Date get_date() const { return copyright_date; }
	bool book_available() const { return is_available; }
	string get_genre() const;

	bool check_out(); // returns true if we were able to check out the book.
	bool check_in();  // returns false if we failed to check the book in (was it ever checked out?).
	class Invalid_input {};	
private:
	string isbn;
	string title;
	string author;
	Chrono::Date copyright_date;
	bool   is_available;
	Genre genre;
};

bool is_isbn(const string&);
bool is_genre(Book::Genre);

Book::Book(string _isbn,string _title,string _author, Chrono::Date d, Book::Genre g, bool a)
	:isbn(_isbn),title(_title),author(_author),copyright_date(d),is_available(a),genre(g)
{
	if (!is_isbn(_isbn) || !is_genre(g)) throw Invalid_input();
}

bool Book::check_out() 
{
	if (book_available()) {
		is_available = false;
		return true;
	}
	return false;
}

bool Book::check_in()
{
	if (!book_available()) {
		is_available = true;
		return true;
	}
	return false;
}

string Book::get_genre() const
{
	switch (genre) {
	case fiction:    return string("fiction");
	case nonfiction: return string("nonfiction");
	case periodical: return string("periodical");
	case biography:  return string("biography");
	case children:   return string("children");
	}
}

ostream& operator<<(ostream& os, const Book& book)
{
	os << "The title is: " << book.get_title() << endl;
	os << "The author is: " << book.get_author() << endl;
	os << "The genre is: " << book.get_genre() << endl;
	os << "The ISBN is: " << book.get_isbn() << endl;

	return os;
}

bool operator==(const Book& a, const Book& b)
{
	return (a.get_isbn() == b.get_isbn());
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

//helper functions
bool is_isbn(const string& isbn)
{
	const char seperator = '-';
	int seperator_count = 0; // if isbn is valid it should have three dashes.

	//check last character first.
	if (isalpha(isbn[isbn.size()-1]) == false
			&& isdigit(isbn[isbn.size()-1]) == false)
		return false;
	
	for (int i = 0; i < isbn.size()-1; ++i) { //size()-1 so it avoids the last character.
		char ch = isbn[i];
		if (!isdigit(ch) && ch != seperator) return false;
		if (ch == seperator) ++seperator_count;
	}

	if (seperator_count != 3) return false;
	else return true;
}

bool is_genre(Book::Genre g)
{
	if (g < Book::fiction || g > Book::children) return false;
	return true;
}
/********************************************************************/
void read_line(string& str)
{
	bool found_nl = false;
	char ch;
	while (!found_nl) {
		cin.get(ch);
		if (isspace(ch) && ch == 10) //look out for a newline.
			found_nl = true;
		else
			str += ch;
	}
}

int main()
{
	try {
		cout << "Book registration:\n";
		cout << "Enter book title: ";
		string title;
		read_line(title);

		cout << "Enter author name: ";
		string author;
		read_line(author);

		cout << "Enter ISBN number: ";
		string isbn;
		cin >> isbn;

		cout << "Enter copyright date (year month day): ";
		int year;
		int m;
		int day;
		cin >> year >> m >> day;
		
		cout << "Enter genre:\n";
		cout << "\t1. fiction\n";
		cout << "\t2. non-fiction\n";
		cout << "\t3. periodical\n";
		cout << "\t4. biography\n";
		cout << "\t5. children\n";
		int genre;
		cin >> genre;

		Chrono::Date date(year,Chrono::Date::Month(m),day);
		Book entry1(isbn,title,author,date,Book::Genre(genre),true);
		cout << entry1;
			
	}
	catch(Chrono::Date::Invalid e) {
		cerr << "Invalid date entered.\n";
		return -1;
	}
	catch(Book::Invalid_input e) {
		cerr << "Invalid input entered.\n";
		return -2;
	}
	catch(...) {
		cerr << "Unknown error occured.\n";
	}
	return 0;
}
