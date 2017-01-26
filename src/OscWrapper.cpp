#include "OscWrapper.h"

using namespace idl;

static const string JSON_FILE = "soundParameterList";

OscWrapper & idl::OscWrapper::getInstance(){
	static OscWrapper instance;
	return instance;
}

void idl::OscWrapper::update(){
	abletonSet.update();
}

void OscWrapper::sendValue(string parameter, float value){
#if defined(_WIN64) || defined(_WIN32) || defined(__MACH__)
	json parameterJSON = soundParameterList[parameter];
	string device = parameterJSON["device"].get<string>();
	string track = parameterJSON["track"].get<string>();
	string param = parameterJSON["parameter"].get<string>();
	ofxAbletonLiveTrack *t = abletonSet.getTrack(track);
	if (!t) {
		cerr << "Track does not exist : " << parameterJSON["track"].get<string>() << endl;
		return;
	}
	t->getDevice(device)->getParameter(param)->setValue(value);
	//cout << device << " " << track << " " << param << " " << value << endl;
#endif
}

OscWrapper::OscWrapper()
	: soundParameterList(FileManager::getInstance().loadJSONFile(JSON_FILE, false)) {
	//loading ableton
	abletonSet.setup();
#if defined(_WIN64) || defined(_WIN32) || defined(__MACH__)
	while (!abletonSet.isLoaded()) {
		abletonSet.update();
	}
#endif
}

OscWrapper::~OscWrapper(){
	stop();
}

float OscWrapper::getOriginValue(string p){
	auto tmp = originalValues.find(p);
	if (tmp == originalValues.end())
		return 0.;
	return tmp->second;
}
