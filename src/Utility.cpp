#include "Utility.h"

using namespace std;

vector<string> split(const string& str, char separator) {
	vector<string> v;
	string slice;
	stringstream ss;
	ss << str;
	while(getline(ss, slice, separator))
		v.push_back(slice);
	return v;
}