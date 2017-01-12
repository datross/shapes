#pragma once

#include "ofMain.h"

#include "world.h"
#include "view.h"
#include "selection.h"
#include "modifier_rotation.h"
#include "ofxLeapMotion2.h"
#include "ofxAbletonLive.h"

#include "DeviceListener.h"

class ofApp : public ofBaseApp {
public:
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
		buf = buffer;
	}
	void audioOut(ofSoundBuffer &buffer) {
			buffer.fillWithTone();
// 		buffer = buf;
	}
	
	ofSoundBuffer buf;
	float env;
    
private:
    idl::World world, world_transformed;
    idl::View view;
//     ofxLeapMotion leap;
	idl::DeviceListener deviceListener;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    
    ofxAbletonLive live;
    
    ofPoint cursor;
};
