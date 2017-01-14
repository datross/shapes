#include "DeviceListener.h"
#include <vector>

using namespace idl;
using namespace std;

/* --------------------- LeapDevice -------------------------- */

LeapDevice::LeapDevice() : ofxLeapMotion() {}

float LeapDevice::grabStrength(unsigned hand) {
	if (hand >= hands.size()) {
		return 0;
	}
	return hands[hand].grabStrength();
}

float LeapDevice::pinchStrength(unsigned hand) {
	if (hand >= hands.size()) {
		return 0;
	}
	return hands[hand].pinchStrength();
}

bool hasHand(HandList hands, unsigned handId){
	for(auto hand = hands.begin(); hand != hands.end(); ++hand){
		if((*hand).id() == handId)
			return true;
	}
	return false;
}

bool LeapDevice::tapped(unsigned hand) {
	auto gestures = ourController->frame().gestures();
	for(auto it = gestures.begin(); it != gestures.end(); ++it) {
		auto hands = (*it).hands();
		//cout << (*it).type() << endl;
		if(((*it).type() == Leap::Gesture::TYPE_SCREEN_TAP) && hasHand(hands, hand)) {
			return true ;
		}
	}
	return false;
}

float LeapDevice::xMove(unsigned hand) {
	if(hand > hands.size())
		return 0;
	
	return hands[hand].palmPosition().x;
}
float LeapDevice::yMove(unsigned hand) {
	if(hand > hands.size())
		return 0;
	
	return hands[hand].palmPosition().y;
}

/* --------------------- DeviceListener -------------------------- */

DeviceListener::DeviceListener() {
}

void DeviceListener::setup() {
	leapDevice.open();
	leapDevice.setupGestures();
}

DeviceListener::~DeviceListener() {
}

vector<idl::Gesture> DeviceListener::getGesture()
{
	vector<idl::Gesture> gestures;
	vector<ofxLeapMotionSimpleHand> hands = leapDevice.getSimpleHands();
	unsigned nbHands = 0;
	for (auto it = hands.begin(); it != hands.end() && nbHands < 2; ++it, ++nbHands) {
		if (leapDevice.grabStrength(nbHands) > 0.1) {
			idl::Gesture grabGesture = idl::Gesture(it->isLeft, GestureGrab, leapDevice.grabStrength(nbHands));
			gestures.push_back(grabGesture);
		}

		if (leapDevice.pinchStrength(nbHands) > 0.1) {
			idl::Gesture pinchGesture = idl::Gesture(it->isLeft, GesturePinch, leapDevice.pinchStrength(nbHands));
			gestures.push_back(pinchGesture);
		}
		
		if (leapDevice.tapped(nbHands)) {
			idl::Gesture tapGesture = idl::Gesture(it->isLeft, GestureTap, leapDevice.tapped(nbHands));
			gestures.push_back(tapGesture);			
		}
		
		if (abs(leapDevice.xMove(nbHands)) > 0.01) {
			idl::Gesture xMoveGesture = idl::Gesture(it->isLeft, GestureXMove, leapDevice.xMove(nbHands));
			gestures.push_back(xMoveGesture);			
		}
		
		if (abs(leapDevice.yMove(nbHands)) > 0.01) {
			idl::Gesture yMoveGesture = idl::Gesture(it->isLeft, GestureYMove, leapDevice.yMove(nbHands));
			gestures.push_back(yMoveGesture);			
		}
	}
	return gestures;
}

bool DeviceListener::connectLeap()
{
	leapDevice.open();

	return true;
}
