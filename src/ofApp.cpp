#include "ofApp.h"
#include <iostream>
#include <cmath>

#include "Utility.h"
#include "SeedFactory.h"
#include "ActionFactory.h"
#include "OscWrapper.h"
#include "Hud.h"

using namespace idl;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){


	ofSetWindowTitle("Interactive Delaunay");

	World& world = World::getInstance();

	ofBackground(255,255,255);
	ofSetFrameRate(60);

	DreamBuilder dreamBuilder;
	dreamBuilder.buildWorld(world);

	View::getInstance().setGlitch(&postGlitch);

	deviceListener.setup();

	/* allocate gesture controller */
	gestureController.reset(new GestureController(deviceListener));

	/* allocate deepActino controller */
	deepActionController.reset(new DeepActionController(deviceListener));

	/* open audio channels */
	ofSoundStreamSetup(2, 2, 44100, IDL_BUFFER_SIZE, 4);

	ofSoundStreamStart();

	/* pre-allocate global buffer */
	generalInputBuffer.allocate(IDL_BUFFER_SIZE, 2);

	/* soundListener points toward the global sound buffer */
	SoundListener::getInstance().setInputBuffer(&generalInputBuffer);
	
	/* not in a transition state */
	transitState = 0;
	startTransitionTime = - TRANSITION_FADE_DURATION - 1;
}

//--------------------------------------------------------------
void ofApp::update(){
	/* update Ableton connection */
	OscWrapper::getInstance().update();

	World& world = World::getInstance();

	/* analyze audio IN */
	SoundListener::getInstance().analyze();

	/* TODO to remove */
	cursor = ofPoint(mouseX, mouseY);

	/* adds actions created by leap gestures */
	auto act = gestureController->ComputeActions();
	for(auto a = act.begin(); a != act.end(); ++a) {
		actions.push_front(*a);
	}

	/* adds actions created by deep controller */
	act = deepActionController->ComputeActions();
	for(auto a = act.begin(); a != act.end(); ++a) {
		actions.push_front(*a);
	}

	/* TODO debug : prints number of actions */
	Hud::getInstance().addEntry("Nb actions", actions.size());


	/* execute the action list on the world */
	executeActions();

	/* update every world's element */
	world.update();
	
	/* wait for transition */
	handleDream();

	/* draw world on fbo */
	View::getInstance().updateFbo();
}
//--------------------------------------------------------------
void ofApp::draw(){
	/* clear the buffer */
	ofFill();

	/* draw fbo in the window */
	View::getInstance().drawFbo();

	/* draw HUD */
	View::getInstance().drawHud();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case 'h': View::getInstance().toggleHud(); break;
		case 'f': View::getInstance().toggleFullScreen(); break;
		case 'k' : OscWrapper::getInstance().stop(); break;
		case 'l' : OscWrapper::getInstance().play(); break;
		case 't' : startTransitionTime = ofGetElapsedTimef(); transitState = true; break; 
		case OF_KEY_RETURN : OscWrapper::getInstance().printAll(); break;
		default: break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == 'm') {
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	cout << " x:" << x << "y:" << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::executeActions() {
	auto it = actions.begin();
// 	cout << "exe 1" << endl;
	while(it != actions.end()) {
		/* need to delete the action */
		if(!(*it)->execute()) {
			cout << "KILL Action " << (*it)->getId() << endl;
			(*it)->suicide();
			actions.erase(it++);
			//it = next_it;
		}else{
			++it;
		}
	}
// 	cout << "exe 2" << endl;
}

void ofApp::transitDream() {
	FileManager::getInstance().nextDream_UpdateWorld();
	ActionFactory::getInstance().reset();
	deepActionController->reset();
	gestureController->updateLinkTable();
	for (auto &a : actions) {
		a->suicide();
	}
	actions.clear();
}

void ofApp::handleDream() {
	float opacity = 0;
	bool changing = false;
	
	float d = ofGetElapsedTimef() - startTransitionTime;
	if(transitState == true) {
	  if(d < TRANSITION_FADE_DURATION) {
	    opacity = d / TRANSITION_FADE_DURATION;
	  } else {
	    transitDream();
		startTransitionTime = ofGetElapsedTimef() - TRANSITION_FADE_DURATION;
	    transitState = false;
	  }
		changing = true;
	}
	
	if(d > TRANSITION_FADE_DURATION && d < 2* TRANSITION_FADE_DURATION) {
	    opacity = 1 - (d - TRANSITION_FADE_DURATION) / TRANSITION_FADE_DURATION;
		changing = true;
	}
	
	if(changing) {
		ofColor v = View::getInstance().getVeilColor();
		View::getInstance().setVeilColor(ofColor(max((float)v.r, 0.0f),
												 max((float)v.g, 0.f),
												 max((float)v.b, 0.f),
												 max((float)v.a, 255.f * opacity)));
	}
}


