#ifndef OF_APP_H
#define OF_APP_H

#include "ofMain.h"

#include "ofxLeapMotion2.h"
#include "ofxAbletonLive.h"

#include "world.h"
#include "view.h"
#include "selection.h"
#include "ModifierRotation.h"
#include "ModifierScale.h"
#include "Action.h"
#include "DeviceListener.h"
#include "SoundListener.h"
#include "Seed.h"
#include "SeedConstant.h"
#include "SeedTimeFunctor.h"
#include "SeedSoundEnvelope.h"
#include "SeedSoundSpectrum.h"
#include "DreamBuilder.h"
#include "GestureController.h"
#include "DeepActionController.h"
#include <list>
#include <memory>
#include "ofxMidi.h"


#define TRANSITION_FADE_DURATION 3

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
		//generalInputBuffer = buffer;
	}
	void audioOut(ofSoundBuffer &buffer) {
// 			buffer.fillWithTone();
		//buffer = generalInputBuffer;
	}

	/* ------------- Delaunay Interactive relative ------------- */

private:
	// TODO check these
	vector <ofxLeapMotionSimpleHand> simpleHands;
	ofPoint cursor;
	float env;
	std::shared_ptr<idl::Seed> s1, s2;

	/* -------------- members -------------- */

	/* stands for the leapmotion (or a mouse, keyboard etc..) */
	idl::DeviceListener deviceListener;

	/* sound buffer storing the input sound */
	ofSoundBuffer generalInputBuffer;

	/* Actions to apply next update */
	std::list<std::shared_ptr<idl::Action> > actions;

	/* Gesture Controller */
	std::shared_ptr<idl::GestureController> gestureController;

	/* DeepAction Controller */
	std::shared_ptr<idl::DeepActionController> deepActionController;

	/* mysterious problem... it needs to be here */
	ofxPostGlitch postGlitch;

	/* -------------- methods -------------- */

	/* execute every actions, and delete the outdated ones */
	void executeActions();
	
	// dream transition //////////////////////////////////////
	
	/* does dream transition */
	void transitDream();
	
	/* handle dream transition */
	void handleDream();
	bool transitState; // 0 : no transition
			   // 1 : transition
	float startTransitionTime;
};

#endif
