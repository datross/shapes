#include "ofApp.h"
#include <iostream>
#include <cmath>

#include "Utility.h"
#include "SeedFactory.h"
#include "ActionFactory.h"

#include "Hud.h"
#include "ofxMidi.h"

using namespace idl;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);	
// 	ofSetFrameRate(60);
	
	ofSetWindowTitle("Interactive Delaunay");
	
	view.setOfApp(this);

	signal.openPort(1); // by name
	
	//s1 = SeedFactory::getInstance().createSeed("time sinusoide");
// 	s1 = shared_ptr<Seed>(new SeedSoundSpectrum(soundListener, 0,0.1,0.1,1));
// 	s2 = SeedFactory::getInstance().createSeed("time sinusoide");


	//loading ableton
	abletonSet.setup();
//#if defined(_WIN64) || defined(_WIN32) || defined(__MACH__)
//	while (!abletonSet.isLoaded()) {
//		abletonSet.update();
//	}
//#endif

	World& world = World::getInstance();

	ofBackground(255,255,255);
	ofSetFrameRate(60);
	
	FileManager::getInstance().setCurrentDream("childish");

	DreamBuilder dreamBuilder;
	dreamBuilder.buildWorld(world);
	
	/*s1 = SeedFactory::getInstance().createSeed("time sinusoide 1 50 0");
	s2 = SeedFactory::getInstance().createSeed("time sinusoide 1 50 0");*/

	shared_ptr<Action> action = ActionFactory::getInstance().create("deepRotation");
	if(action)
		actions.push_front(action);

	deviceListener.setup();
	
	/* allocate gesture controller */
	gestureController.reset(new GestureController(deviceListener));

	/* open audio channels */
	ofSoundStreamSetup(2, 2, 44100, IDL_BUFFER_SIZE, 4);
	
	/* pre-allocate global buffer */
	generalInputBuffer.allocate(IDL_BUFFER_SIZE, 2);
	
	/* soundListener points toward the global sound buffer */
	soundListener.setInputBuffer(&generalInputBuffer);
}

//--------------------------------------------------------------
void ofApp::update(){
	/* update Ableton connection */
	abletonSet.update();

	World& world = World::getInstance();
	
	/* analyze audio IN */
	soundListener.analyze();
	
	/* TODO to remove */
	cursor = ofPoint(mouseX, mouseY);
	
	/* adds actions created by leap gestures */
	auto act = gestureController->ComputeActions();
	for(auto a = act.begin(); a != act.end(); ++a) {
		actions.push_front(*a);
	}
	
	/* TODO debug : prints number of actions */
	Hud::getInstance().addEntry("Nb actions", actions.size());
	
	/* reset world transform before executing actions */
	world.resetTransform();
	
	/* execute the action list on the world */
	executeActions();
	
	/* update every world's element */
	world.update();
	
	
	
	/* TODO this should be removed */
	//ofxLeapMotion &leap = deviceListener.getLeap();
	//simpleHands = leap.getSimpleHands();
	//if(leap.isFrameNew()) {
	//	
	//	leap.setMappingX(-230, 230, 0, ofGetWidth());
	//	leap.setMappingY(90, 490, ofGetHeight(), 0);
	//	leap.setMappingZ(-150, 150, -200, 200);
	//	
	//	simpleHands.clear();
	//	simpleHands = leap.getSimpleHands();
	//	
	//	if(!simpleHands.empty()) {
	//		cursor.x = simpleHands[0].handPos.x;
	//		cursor.y = simpleHands[0].handPos.y;
	//	}
	//	
	//	leap.markFrameAsOld();
	//}
}
//--------------------------------------------------------------
void ofApp::draw(){
	World& world = World::getInstance();
	
	/* clear the buffer */
	ofFill();
	
	/* draw world elements */
	view.drawWorld(world);

	/* draw HUD */
	view.drawHud();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'h') {
		view.toggleHud();
	}
	if(key == 'f') {
		view.toggleFullScreen();
	}
	if (key == OF_KEY_RETURN) {
		abletonSet.printAll();
		return;
	}
	if (key == OF_KEY_DOWN ) {
		abletonSet.stop();
	}
	if (key == 'm') {
		signal.listPorts();
		signal.sendNoteOn(1, 72, 64);
	}
	else
		abletonSet.play();	
	//live.setTempo(75);


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == 'm') {
		signal.sendNoteOff(1, 72, 64);
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
// 	for(auto it = actions.begin(); it != actions.end(); ++it) {
// 		/* need to delete the action */
// 		auto next_it = it;
// 		++next_it;
// 		if(!(*it)->execute()) {
// 			actions.erase(it);
// 			//it = next_it;
// 		}
// 	}
	
	auto it = actions.begin();
	while(it != actions.end()) {
		/* need to delete the action */
		if(!(*it)->execute()) {
			actions.erase(it++);
			//it = next_it;
		}else{
			++it;
		}
	}
}
