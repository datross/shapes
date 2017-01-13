#pragma once

#include "ofMain.h"

#include "ofxLeapMotion2.h"
#include "ofxAbletonLive.h"

#include "world.h"
#include "view.h"
#include "selection.h"
#include "modifier_rotation.h"
#include "ModifierScale.h"
#include "Action.h"
#include "DeviceListener.h"
#include "SoundListener.h"
#include "Seed.h"
#include "SeedConstant.h"

#include <list>

class ofApp : public ofBaseApp {
public:
	
	/* ------------- openFrameWorks relative ------------- */
	
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
	void audioIn(ofSoundBuffer &buffer) {
		generalInputBuffer = buffer;
	}
	void audioOut(ofSoundBuffer &buffer) {
// 			buffer.fillWithTone();
// 		buffer = buf;
	}
	
	/* ------------- Delaunay Interactive relative ------------- */
	
	
private:
	// TODO check these
    idl::World world;
    idl::View view;
    vector <ofxLeapMotionSimpleHand> simpleHands;
	ofPoint cursor;
	float env;
	
	/* -------------- members -------------- */
	
	/* stands for the leapmotion (or a mouse, keyboard etc..) */
	idl::DeviceListener deviceListener;
    
	/* process input sound */
	idl::SoundListener soundListener;
	
	/* sound buffer storing the input sound */
	ofSoundBuffer generalInputBuffer;
	
	/* interface with Ableton */
    ofxAbletonLive abletonSet;
	
	/* Actions to apply next update */
	std::list<idl::Action*> actions;
	
	/* -------------- methods -------------- */
	
	/* execute every actions, and delete the outdated ones */
	void executeActions();
};
