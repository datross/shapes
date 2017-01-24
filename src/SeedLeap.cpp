#include "SeedLeap.h"


using namespace idl;


SeedLeap::SeedLeap(HandSide h, LeapInfoFlag f): hand(h), flag(f){

}

SeedLeap::~SeedLeap(){

}

ofVec3f SeedLeap::getValue(){
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

	if(flag == POSITION)
		return ofVec3f(leap.xPos(hand), leap.yPos(hand), 0.);
	if(flag == STRENGTH)
		return ofVec3f(leap.pinchStrength(hand), leap.grabStrength(hand), 0.);
}
