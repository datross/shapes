#include "DeviceListener.h"
#include <vector>
#include "Hud.h"

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

float LeapDevice::xPos(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float x = hands[hand].palmPosition().x / 300;
	ourMutex.unlock();
	return x;
}

float LeapDevice::yPos(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float y = hands[hand].palmPosition().y / 540;
	ourMutex.unlock();
	return y;

}

float LeapDevice::zPos(int hand){
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float z = hands[hand].palmPosition().z / 300;
	ourMutex.unlock();
	return z;
}

float LeapDevice::xNormal(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float x = hands[hand].palmNormal().x;
	ourMutex.unlock();
	return x;
}

float LeapDevice::yNormal(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float y = hands[hand].palmNormal().y;
	ourMutex.unlock();
	return y;
}

float LeapDevice::zNormal(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float z = hands[hand].palmNormal().z;
	ourMutex.unlock();
	return z;
}

float LeapDevice::xVelocity(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float x = hands[hand].palmVelocity().x;
	ourMutex.unlock();
	return x;
}

float LeapDevice::yVelocity(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float y = hands[hand].palmVelocity().y;
	ourMutex.unlock();
	return y;
}

float LeapDevice::zVelocity(int hand) {
	ourMutex.lock();
	if (hand >= hands.size()) {
		ourMutex.unlock();
		return 0;
	}
	float z = hands[hand].palmVelocity().z;
	ourMutex.unlock();
	return z;
}

bool idl::LeapDevice::hasHand(){
	return hands.size() > 0 ;
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
