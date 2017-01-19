#include "ofMain.h"
#include "SeedTime.h"

using namespace idl;

SeedTime::SeedTime(std::vector<Setting> _settings)
	: settings(_settings) {
	start();
}

void SeedTime::start() {
	startTime = ofGetElapsedTimef();
}

float SeedTime::getStartTime() {
	return startTime;
}

float SeedTime::getAge(){
	return ofGetElapsedTimef() - startTime;
}

float& SeedTime::getSetting(unsigned i) {
	return settings[i];
}

unsigned SeedTime::getSettingsCount() {
	return settings.size();
}
