#ifndef OSCWRAPPER_H
#define OSCWRAPPER_H


#include "FileManager.h"
#include "ofxAbletonLive.h"

namespace idl {

class OscWrapper
{
private:
	ofxAbletonLive *oscInterface;
	json soundParameterList;
	std::map<string, float> originalValues;

public:
	OscWrapper();
	~OscWrapper();
	float getOriginValue(string p);
	void sendValue(string parameter, float value);

	void setOSCInterface(ofxAbletonLive * live);
};
}

#endif