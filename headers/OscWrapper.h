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
	OscWrapper();
	~OscWrapper();
public:
	static OscWrapper& getInstance();
	void sendValue(string parameter, float value);

	void setOSCInterface(ofxAbletonLive * live);
};
}

#endif