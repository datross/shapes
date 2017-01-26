#include "SeedLeap.h"
#include <cmath>
#include "Hud.h"
#include <iostream>

using namespace idl;
using namespace std;

SeedLeap::SeedLeap(HandSide h, string f): hand(h) {
	     if(f == "position")  flag = POS;
	else if(f == "positionX") flag = POSX;
	else if(f == "positionY") flag = POSY;
	else if(f == "positionZ") flag = POSZ;
	else if(f == "grab")      flag = GRAB;
	else if(f == "pinch")     flag = PINCH;
	else if(f == "strength")  flag = STRENGTH;
	else if(f == "normalX")   flag = NORMALX;
	else if(f == "normalY")   flag = NORMALY;
	else if(f == "normalZ")   flag = NORMALZ;
	else if(f == "normal")    flag = NORMAL;
	else if(f == "speedX")    flag = SPEEDX;
	else if(f == "speedY")    flag = SPEEDY;
	else if(f == "speedZ")    flag = SPEEDZ;
	else if(f == "speed")     flag = SPEED;
	else cout << "Seed Leap Flag unknown : " << f << endl;
}

SeedLeap::~SeedLeap(){

}

ofVec3f SeedLeap::getValue() {
	LeapDevice & leap = LeapDevice::getInstance();
	
	/* index of the hand */
	int h;
	if (hand == RIGHT) {
		h = leap.getRightHand();
	}
	else {
		h = leap.getLeftHand();
	}
	if (h == -1)
		return ofVec3f(0);
	
	/* flag leap info */
	if (flag == POS) 
		return ofVec3f(leap.xPos(h), leap.yPos(h), leap.zPos(h));
	if (flag == POSX) {
		float tmp = abs(leap.xPos(h));
		return ofVec3f(tmp);
	}
	if (flag == POSY) {
		float tmp = abs(leap.yPos(h));
		Hud::getInstance().addEntry("Y", tmp);
		return ofVec3f(tmp);
	}
	if (flag == POSZ) {
		float tmp = abs(leap.zPos(h));
		Hud::getInstance().addEntry("Z", tmp);
		return ofVec3f(tmp);
	}
	if(flag == STRENGTH)
		return ofVec3f(leap.pinchStrength(h), leap.grabStrength(h), 0.);
	if (flag == GRAB)
		return ofVec3f(leap.grabStrength(h), leap.grabStrength(h), leap.grabStrength(h));
	if (flag == PINCH)
		return ofVec3f(leap.pinchStrength(h), leap.pinchStrength(h), leap.pinchStrength(h));
	if (flag == NORMALX)
		return ofVec3f(leap.xNormal(h));
	if (flag == NORMALY)
		return ofVec3f(leap.yNormal(h));
	if (flag == NORMALZ)
		return ofVec3f(leap.zNormal(h));
	if (flag == NORMAL)  {
		ofVec3f tmp(leap.xNormal(h), leap.yNormal(h), leap.zNormal(h));
		Hud::getInstance().addEntry("Normal", tmp);
		return tmp;
	}
	if (flag == SPEEDX)
		return ofVec3f(leap.xVelocity(h));
	if (flag == SPEEDY)
		return ofVec3f(leap.yVelocity(h));
	if (flag == SPEEDZ)
		return ofVec3f(leap.zVelocity(h));
	if (flag == SPEED)
		return ofVec3f(leap.xVelocity(h), leap.yVelocity(h), leap.zVelocity(h));
	return ofVec3f(0);
}
