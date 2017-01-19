#ifndef DEVICELISTENER_H
#define DEVICELISTENER_H

#include "ofxLeapMotion2.h"
#include "Gesture.h"

#include <vector>

#define THRESHOLD_GRAB 0.4
#define THRESHOLD_PINCH 0.4

namespace idl {

/* In order to access protected members */
class LeapDevice : public ofxLeapMotion {
private:
// 	float ofVec2 hand_pos_prec[2];
public:
	LeapDevice();

	/* MIND the hands number */
	float grabStrength(unsigned hand);
	float pinchStrength(unsigned hand);
	bool tapped(unsigned hand);
	float xPos(unsigned hand);
	float yPos(unsigned hand);
};

class DeviceListener{
	LeapDevice leapDevice;
public:
	DeviceListener();
	~DeviceListener();

	void setup();
	LeapDevice& getLeap(){ return leapDevice; }
	std::vector<Gesture> getGestures();
	bool connectLeap();
};
}

#endif