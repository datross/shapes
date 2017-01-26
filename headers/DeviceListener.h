#ifndef DEVICELISTENER_H
#define DEVICELISTENER_H

#include "ofxLeapMotion2.h"
#include "Gesture.h"

#include <vector>

#define THRESHOLD_GRAB 0.4
#define THRESHOLD_PINCH 0.4

namespace idl {

	enum HandSide { LEFT, RIGHT };
	enum SeedLeapInfoFlag {
		POS,
		POSX,
		POSY,
		POSZ,
		GRAB,
		PINCH,
		STRENGTH,
		NORMALX,
		NORMALY,
		NORMALZ,
		NORMAL,
		SPEEDX,
		SPEEDY,
		SPEEDZ,
		SPEED
	};

/* In order to access protected members */
class LeapDevice : public ofxLeapMotion {
private:
// 	float ofVec2 hand_pos_prec[2];
	LeapDevice();

public:

	/* MIND the hands number */
	static LeapDevice& getInstance();
	float grabStrength(unsigned hand);
	float pinchStrength(unsigned hand);
	float xPos(int hand);
	float yPos(int hand);
	float zPos(int hand);
	float xNormal(int hand);
	float yNormal(int hand);
	float zNormal(int hand);
	float xVelocity(int hand);
	float yVelocity(int hand);
	float zVelocity(int hand);
	bool hasHand();
	int getRightHand();
	int getLeftHand();
};

class DeviceListener{
	LeapDevice& leapDevice;
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