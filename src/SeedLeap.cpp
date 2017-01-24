#include "SeedLeap.h"


using namespace idl;


SeedLeap::SeedLeap(HandSide h, LeapInfoFlag f): hand(h), flag(f){

}

SeedLeap::~SeedLeap(){

}

ofVec3f SeedLeap::getValue() {
	LeapDevice & leap = LeapDevice::getInstance();
	unsigned h;
	if (hand == RIGHT) {
		h = leap.getRightHand();
	}
	else {
		h = leap.getLeftHand();
	}
	if (h == -1)
		return ofVec3f(0);

	if (flag == POS) 
			return ofVec3f(leap.xPos(hand), leap.yPos(hand), leap.zPos(hand));
	if (flag == POSX)
		return ofVec3f(leap.xPos(hand), leap.xPos(hand), leap.xPos(hand));
	if (flag == POSY)
		return ofVec3f(leap.yPos(hand), leap.yPos(hand), leap.yPos(hand));
	if (flag == POSZ)
		return ofVec3f(leap.zPos(hand), leap.zPos(hand), leap.zPos(hand));
	if(flag == STRENGTH)
		return ofVec3f(leap.pinchStrength(hand), leap.grabStrength(hand), 0.);
	if (flag == GRAB)
		return ofVec3f(leap.grabStrength(hand), leap.grabStrength(hand), leap.grabStrength(hand));
	if (flag == PINCH)
		return ofVec3f(leap.pinchStrength(hand), leap.pinchStrength(hand), leap.pinchStrength(hand));

}