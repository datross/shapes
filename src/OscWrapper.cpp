#include "OscWrapper.h"

using namespace idl;

static const string JSON_FILE = "soundParameterList.json";

OscWrapper & idl::OscWrapper::getInstance(){
	static OscWrapper instance;
	return instance;
}

void OscWrapper::sendValue(string parameter, float value){
	json parameterJSON = soundParameterList[parameter];
	oscInterface->getTrack(parameterJSON["track"].get<string>())->getDevice(parameterJSON["device"].get<string>())->getParameter(parameterJSON["parameter"].get<string>())->setValue(value);
}

void OscWrapper::setOSCInterface(ofxAbletonLive * _live) {
	oscInterface = _live;
}

OscWrapper::OscWrapper()
	: soundParameterList(FileManager::getInstance().loadJSONFile(JSON_FILE, false)) {
}

OscWrapper::~OscWrapper(){

}

float OscWrapper::getOriginValue(string p){
	auto tmp = originalValues.find(p);
	if (tmp == originalValues.end())
		return 0.;
	return tmp->second;
}
