#include "SeedLeap.h"
#include <cmath>

using namespace idl;


SeedLeap::SeedLeap(HandSide h, LeapInfoFlag f): hand(h), flag(f){

}

SeedLeap::~SeedLeap(){

}

ofVec3f SeedLeap::getValue() {
	LeapDevice & leap = LeapDevice::getInstance();
	int h;
	if (hand == RIGHT) {
		h = leap.getRightHand();
	}
	else {
		h = leap.getLeftHand();
	}
	if (h == -1)
		return ofVec3f(0);
	if (flag == POS) 
		return ofVec3f(leap.xPos(h), leap.yPos(h), leap.zPos(h));
	if (flag == POSX) {
		float tmp = abs(leap.xPos(h)/60);
		ofVec3f lol(tmp, tmp, tmp);
		return lol;
	}
	if (flag == POSY)
		return ofVec3f(leap.yPos(h), leap.yPos(h), leap.yPos(h));
	if (flag == POSZ)
		return ofVec3f(leap.zPos(h), leap.zPos(h), leap.zPos(h));
	if(flag == STRENGTH)
		return ofVec3f(leap.pinchStrength(h), leap.grabStrength(h), 0.);
	if (flag == GRAB)
		return ofVec3f(leap.grabStrength(h), leap.grabStrength(h), leap.grabStrength(h));
	if (flag == PINCH)
		return ofVec3f(leap.pinchStrength(h), leap.pinchStrength(h), leap.pinchStrength(h));
	return ofVec3f(0);

}