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
	Book() { }

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
class Patron {
public:
	Patron(string user, string c_number, double fee=0);
	Patron() { }

	string get_username() const { return username; }
	string get_card_number() const { return card_number; }
	double get_fees_owed() const { return fees_owed; }
	
	void set_fee(double amount);
private:
	string username;
	string card_number;
	double fees_owed;
};

Patron::Patron(string user, string c_number, double fee)
	:username(user),card_number(c_number),fees_owed(fee)
{
}
	
void Patron::set_fee(double amount)
{
	fees_owed = amount;
}

//helper function
bool owes_fee(const Patron& p)
{
	if (p.get_fees_owed() > 0) 
		return true;
	return false;
}
/********************************************************************/
class Library {
public:
	void add_book(Book);
	void add_patron(Patron);
	void checkout(const string& isbn, const string& card_num, const Chrono::Date& date);
	vector<string> debt_list() const;
	
	class Book_error { };
	class Patron_error { };
	class Fees_owed_error { };
private:
	vector<Book> book;
	vector<Patron> patron;
	
	struct Transaction {
		Book b;
		Patron p;
		Chrono::Date d;
	};
	
	vector<Transaction> transactions;
};

void Library::add_book(Book b)
{
	book.push_back(b);
}

void Library::add_patron(Patron p)
{
	patron.push_back(p);
}

void Library::checkout(const string& isbn, const string& card_num, const Chrono::Date& date)
{
	//Lets find the book containing the same ISBN as isbn.
	int index_of_book = 0;
	bool found_book = false;
	for (int i = 0; i < book.size(); ++i) {
		if (book[i].get_isbn() == isbn) {
			index_of_book = i;
			found_book = true;
		}
	}
	if (!found_book) throw Book_error();

	//Lets find the patron
	int index_of_patron = 0;
	bool found_patron = false;
	for (int i = 0; i < patron.size(); ++i) {
		if (patron[i].get_card_number() == card_num) {
			index_of_patron = i;
			found_patron = true;
		}
	}
	if (!found_patron) throw Patron_error();
	if (owes_fee(patron[index_of_patron])) throw Fees_owed_error();
	
	if (!book[index_of_book].check_out()) throw Book_error();
	
	Transaction t;
	t.b = book[index_of_book];
	t.p = patron[index_of_patron];
	t.d = date;	 
	
	transactions.push_back(t);
}

vector<string> Library::debt_list() const 
{
	vector<string> names;
	for (int i = 0; i < patron.size(); ++i)
		if (owes_fee(patron[i]))
			names.push_back(patron[i].get_username());
	return names;
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

void menu()
{
	cout << "\nLibrary Management System\n";
	cout << "\t(1). Add book\n";
	cout << "\t(2). Add patron\n";
	cout << "\t(3). Check-out book\n";
	cout << "\t(4). List patron debt list\n";
	cout << "\t(5). quit\n";
	cout << "> ";
}

void clean_buffer()
{
	char ch;
	cin.get(ch);
}
int main()
{
	Library lib;
	bool exit = false;
	while (exit == false) {
		try {
			menu();
			int choice;
			cin >> choice;
			if (!cin) error("**cin is corrupted. Exiting program.**");

			clean_buffer();

			switch (choice) {
			case 1:
			{
				cout << "Enter book ISBN: ";
				string isbn;
				cin >> isbn;
				
				clean_buffer();
				cout << "Enter book title: ";
				string title;
				read_line(title);

				cout << "Enter author name: ";
				string author;
				read_line(author);
				
				cout << "Enter book genre:\n";
				cout << "\t1. fiction\n";
				cout << "\t2. non-fiction\n";
				cout << "\t3. periodical\n";
				cout << "\t4. biography\n";
				cout << "\t5. children\n";
				cout << "> ";
				int genre;
				cin >> genre;

				cout << "Enter date of copyright (year month day): ";
				int year, month, day;
				cin >> year >> month >> day;
				Chrono::Date date(year,Chrono::Date::Month(month),day);

				Book book(isbn,title,author,date,Book::Genre(genre),true);
				lib.add_book(book);
				break;
			}
			case 2:
			{
				cout << "Enter patron's full name: ";
				string full_name;
				read_line(full_name);

				cout << "Enter patron's card number: ";
				string card_num;
				read_line(card_num); //some card numbers have spaces.
				
				cout << "Fees owed by " << full_name << ": ";
				double fees;
				cin >> fees;

				Patron patron(full_name,card_num,fees);
				lib.add_patron(patron);
				break;
			}
			case 3:
			{
				cout << "Enter patron's card number: ";
				string card_num;
				read_line(card_num);

				cout << "Enter book ISBN: ";
				string isbn;
				cin >> isbn;
				if (!is_isbn(isbn)) throw Book::Invalid_input();

				cout << "Enter today's date (year month day): ";
				int year, month, day;
				cin >> year >> month >> day;
				Chrono::Date date(year,Chrono::Date::Month(month),day);

				lib.checkout(isbn,card_num,date);
				break;
			}
			case 4:
			{
				vector<string> names = lib.debt_list();
				cout << "The following patrions owe fees:\n";
				for (int i = 0; i < names.size(); ++i)
					cout << names[i] << endl;
				break;
			}
			case 5:
				exit = true;
				break;
			default:
				cout << "Invalid Choice.\n";
			}
		}
		catch(Chrono::Date::Invalid e) {
			cerr << "**Invalid date entered.**\n";
			cout << "**Please re-enter data.**\n";
		}
		catch(Book::Invalid_input e) {
			cerr << "**Invalid input entered.**\n";
			cout << "**Please re-enter data.**\n";
		}
		catch(Library::Book_error e) {
			cerr << "**The book is not available.**\n";
			cout << "**Please re-enter data.**\n";
		}
		catch(Library::Patron_error e) {
			cerr << "**The patron does not exist.**\n";
			cout << "**Please re-enter data.**\n";
		}
		catch(Library::Fees_owed_error e) {
			cerr << "**The patron cannot check-out because of owed fees.**\n";
			cout << "**Please re-enter data.**\n";
		}
		catch(runtime_error e) {
			cerr << e.what() << endl;
			return -1;
		}
		catch(...) {
			cerr << "Unknown error occured.\n";
			return -2;
		}
	}
	return 0;
}
