#include "OscWrapper.h"

using namespace idl;

void OscWrapper::sendValue(string parameter, float value)
{
	json parameterJSON = soundParameterList[parameter];
	oscInterface->getTrack(parameterJSON["track"].get<string>())->getDevice(parameterJSON["device"].get<string>())->getParameter(parameterJSON["parameter"].get<string>())->setValue(value);
}

void OscWrapper::setOSCInterface(ofxAbletonLive * _live) {
	oscInterface = _live;
}

OscWrapper::OscWrapper(): soundParameterList(FileManager::getInstance().loadJSONFile("soundParameterList.json", false)) {
}


OscWrapper::~OscWrapper()
{

}