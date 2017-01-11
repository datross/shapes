#ifndef DEVICELISTENER_H
#define DEVICELISTENER_H

#include "ofxLeapMotion2.h"
#include "Gesture.h"

#include <vector>

namespace idl {

/* In order to access protected members */
class LeapDevice : public ofxLeapMotion {
private:
public:
	LeapDevice();

	/* MIND the hands number */
	float grabStrength(unsigned hand);
	float pinchStrength(unsigned hand);
	bool tapped(unsigned hand);
	float xMove(unsigned hand);
	float yMove(unsigned hand);
};

class DeviceListener
{
public:
	LeapDevice leapDevice;

	DeviceListener();
	~DeviceListener();

	std::vector<Gesture> getGesture();
	bool connectLeap();
};
}

#endif