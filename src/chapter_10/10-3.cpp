/*
	chapter 10 exercise 3
	page 372
*/
#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
	Reading(int h, double t) :hour(h),temperature(t) {}
};

ifstream& operator>>(ifstream& is, Reading& r)
{
	int hour;
	double temp;
	is >> hour >> temp;	
	if (hour < 0 || hour > 13) // very unlikely to happen since we created the file ourself.
		error("Hour out of range.");
	
	r.hour = hour;
	r.temperature = temp;
	return is;
}
	
void read_from_stream(ifstream& is, vector<Reading>& reads)
{
	const int default_val = 0;
	Reading r(default_val,default_val);	//Reading constructor requires two arguments.
	while (is >> r) 
		reads.push_back(r);
}

void check_stream_state(const ifstream& is)
{
	if (!is.eof()) 
		// We should've only exited when we encountered an end-of-file. 
		// Any other state (bad,fail) is an error.
		error("Error reading input.");
}

double calc_mean(const vector<Reading>& reads)
{
	double mean = 0;
	for (int i = 0; i < reads.size(); ++i)
		mean += reads[i].temperature;
	mean = mean/reads.size();

	return mean;
}

double calc_median(const vector<Reading>& reads)
{
	vector<double> temperatures; //will hold all of the temperatures so we can sort.
	for (int i = 0; i < reads.size(); ++i)
		temperatures.push_back(reads[i].temperature);

	sort(temperatures.begin(),temperatures.end());

	if (temperatures.size() % 2 == 0)
		return ((temperatures[temperatures.size()/2]) +
			(temperatures[temperatures.size()/2-1]))/2;
	else
		return temperatures[temperatures.size()/2];
}

int main()
{
	try {
		string filename = "raw_temps.txt";
		ifstream is(filename.c_str());
		if (!is) error("Error opening file.");

		vector<Reading> reads;
		read_from_stream(is,reads);
		check_stream_state(is);
		
		double mean = calc_mean(reads);
		cout << "The mean is: " << mean << endl;

		double median = calc_median(reads);
		cout << "The median is: " << median << endl;
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}
