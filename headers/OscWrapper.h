#ifndef OSCWRAPPER_H
#define OSCWRAPPER_H


#include "FileManager.h"
#include "ofxAbletonLive.h"

namespace idl {

class OscWrapper
{
private:
	json soundParameterList;
	OscWrapper();
	~OscWrapper();
	std::map<string, float> originalValues;
	/* interface with Ableton */
	ofxAbletonLive abletonSet;

public:
	static OscWrapper& getInstance();
	void update();
	void play() { abletonSet.play(); }
	void stop() { abletonSet.stop(); }
	void printAll() { abletonSet.printAll(); }
	float getOriginValue(string p);
	void sendValue(string parameter, float value);
};
}

#endif