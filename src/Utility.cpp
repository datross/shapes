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

float parseFloat(string s) {
	return convert<float, string>(s);
}

ofVec2f parseVec2(string s) {
	auto v = split(s, ' ');
	return ofVec2f(parseFloat(v[0]), parseFloat(v[1]));
}

ofVec3f parseVec3(string s) {
	auto v = split(s, ' ');
	return ofVec3f(parseFloat(v[0]), parseFloat(v[1]), 
		parseFloat(v[2]));
}

ofPoint parsePoint(string s){
	ofVec2f tmp = parseVec2(s);
	return ofPoint(tmp.x, tmp.y);
}
