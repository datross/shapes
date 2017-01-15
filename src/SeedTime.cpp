#include "ofMain.h"
#include "SeedTime.h"

using namespace idl;

SeedTime::SeedTime() {
	start();
}

void SeedTime::start() {
	startTime = ofGetElapsedTimef();
}

float SeedTime::getStartTime() {
	return startTime;
}


