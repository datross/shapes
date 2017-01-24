#include "DeviceListener.h"
#include <vector>

using namespace idl;
using namespace std;

/* --------------------- LeapDevice -------------------------- */

LeapDevice::LeapDevice() : ofxLeapMotion() {}

LeapDevice & idl::LeapDevice::getInstance(){
	static LeapDevice instance;
	return instance;
}

float LeapDevice::grabStrength(unsigned hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	auto tmp = hands[hand].grabStrength();
	ourMutex.unlock();
	return tmp;
}

float LeapDevice::pinchStrength(unsigned hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	auto tmp = hands[hand].pinchStrength();
	ourMutex.unlock();
	return tmp;
}

bool LeapDevice::hasHand(unsigned handId){
	ourMutex.lock();
	for(auto hand = hands.begin(); hand != hands.end(); ++hand){
		if ((*hand).id() == handId) {
			ourMutex.unlock();
			return true;
		}
	}
	ourMutex.unlock();
	return false;
}

bool LeapDevice::tapped(unsigned hand) {
	ourMutex.lock();
	auto gestures = ourController->frame().gestures();
	for(auto it = gestures.begin(); it != gestures.end(); ++it) {
		auto hands = (*it).hands();
		if(((*it).type() == Leap::Gesture::TYPE_SCREEN_TAP) && hasHand(hand)) {
			ourMutex.unlock();
			return true ;
		}
	}
	ourMutex.unlock();
	return false;
}

float LeapDevice::xPos(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	cout << "HAND : " << hand << endl;
	cout << "HANDs size : " << hands.size() << endl;
	float x = hands[hand].palmPosition().x;
	ourMutex.unlock();
	return x;
}

float LeapDevice::yPos(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float x = hands[hand].palmPosition().y;
	ourMutex.unlock();
	return x;
	
}

float idl::LeapDevice::zPos(int hand){
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float x = hands[hand].palmPosition().z;
	ourMutex.unlock();
	return x;
}

int idl::LeapDevice::getRightHand(){
	ourMutex.lock();
	int i = 0;
	for (auto& hand : hands) {
		if (hand.isRight()) {
			ourMutex.unlock();
			return i;
		}
		i++;
	}
	ourMutex.unlock();
	return -1;
}

int idl::LeapDevice::getLeftHand(){
	ourMutex.lock();
	int i = 0;
	for (auto& hand : hands) {
		if (hand.isLeft()) {
			ourMutex.unlock();
			return i;
		}
		i++;
	}
	ourMutex.unlock();
	return -1;
}

/* --------------------- DeviceListener -------------------------- */

DeviceListener::DeviceListener() : leapDevice(LeapDevice::getInstance()){
}

void DeviceListener::setup() {
	leapDevice.open();
	leapDevice.setupGestures();
}

DeviceListener::~DeviceListener() {
}

vector<idl::Gesture> DeviceListener::getGestures(){
	vector<idl::Gesture> gestures;
	vector<ofxLeapMotionSimpleHand> hands = leapDevice.getSimpleHands();
	unsigned nbHands = 0;
	for (auto it = hands.begin(); it != hands.end() && nbHands < 2; ++it, ++nbHands) {
		if (leapDevice.grabStrength(nbHands) > THRESHOLD_GRAB) {
			idl::Gesture grabGesture = idl::Gesture(it->isLeft, GestureGrab, leapDevice.grabStrength(nbHands));
			gestures.push_back(grabGesture);
		}

		if (leapDevice.pinchStrength(nbHands) > THRESHOLD_PINCH) {
			idl::Gesture pinchGesture = idl::Gesture(it->isLeft, GesturePinch, leapDevice.pinchStrength(nbHands));
			gestures.push_back(pinchGesture);
		}
		
		if (leapDevice.tapped(nbHands)) {
			idl::Gesture tapGesture = idl::Gesture(it->isLeft, GestureTap, leapDevice.tapped(nbHands));
			gestures.push_back(tapGesture);			
		}
		
		idl::Gesture xMoveGesture = idl::Gesture(it->isLeft, GestureXMove, leapDevice.xPos(nbHands));
		gestures.push_back(xMoveGesture);			
		
		idl::Gesture yMoveGesture = idl::Gesture(it->isLeft, GestureYMove, leapDevice.yPos(nbHands));
		gestures.push_back(yMoveGesture);			
	}
	return gestures;
}

bool DeviceListener::connectLeap()
{
	leapDevice.open();
	// TODO
	return true;
}
