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
public:
	OscWrapper();
	~OscWrapper();
	void sendValue(string parameter, float value);

	void setOSCInterface(ofxAbletonLive * live);
};
}

#endif