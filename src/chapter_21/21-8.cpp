/*
	chapter 21 exercise 8
	page 767
*/
#include "std_lib_facilities.h"
#include <map>

class sort_by_value {
public:
	bool operator()(const pair<string,int>& a, const pair<string,int>& b)
	{
		return a.second < b.second;
	}
};

int main()
{
	map<string,int> words;
	
	string s;
	while (cin >> s) ++words[s];
	
	//Create a vector of pairs<>, that way we can utilize std::sort
	vector<pair<string,int> > v_words;
	for (map<string,int>::const_iterator p = words.begin(); p != words.end(); ++p)
		v_words.push_back(*p);
	sort(v_words.begin(),v_words.end(),sort_by_value());
	
	typedef vector<pair<string,int> >::const_iterator Iter;
	for (Iter p= v_words.begin(); p != v_words.end(); ++p)
		cout << (*p).second << ": " << (*p).first << endl;

	return 0;
}
