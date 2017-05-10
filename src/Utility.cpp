#include "Utility.h"
#include <limits>

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

float energy(const std::vector<float> signal) {
	float e = 0;
	for(auto it = signal.begin(); it != signal.end(); ++it) {
		e += (*it) * (*it);
	}
	return e;
}

float parseFloat(string s) {
	if(s == "inf")
		return numeric_limits<float>::infinity();
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

ofColor parseColor(string s){
  	auto v = split(s, ' ');
	ofColor color(parseFloat(v[0]), 
		      parseFloat(v[1]), 
		      parseFloat(v[2]));
	if(v.size() == 4)
	  color.a = parseFloat(v[3]);
	return color;
}

vector<string> parseIds(string s){
	return split(s,' ');
}

ofVec2f clampVec2(ofVec2f v, float inf, float sup) {
	return ofVec2f(ofClamp(v.x, inf, sup), ofClamp(v.y, inf, sup));
}

ofColor pourcentVec3ToColor(ofVec3f v) {
	return ofColor(255 * v.x, 255 * v.y, 255 * v.z, 255 * v.x);
}

ofColor vec3ToColor(ofVec3f v) {
	return ofColor(v.x, v.y, v.z);
}

ofColor multiplyOfColor(ofColor a, ofColor b) {
	ofColor c = a * b;
	c.a = (float)(a.a * b.a) / 255.;
	return c;
}

ofColor substractOfColor(ofColor a, ofColor b) {
	ofColor c = a - b;
	c.a = max(0, a.a - b.a);
	return c;
}

ofColor addOfColor(ofColor a, ofColor b) {
	ofColor c = a + b;
	c.a = min(255, a.a + b.a);
	return c;
}


float distance(ofVec2f v1, ofVec2f v2) {
	return sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
}