#include "ofApp.h"
#include <iostream>
#include <cmath>

#include "Utility.h"
#include "SeedFactory.h"
#include "ActionFactory.h"

using namespace idl;
using namespace std;




//--------------------------------------------------------------
void ofApp::setup(){
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

	actions.push_front(ActionFactory::getInstance().create("grab"));

	deviceListener.setup();
	
	/* allocate gesture controller */
	gestureController.reset(new GestureController(deviceListener));

	/* open audio channels */
	ofSoundStreamSetup(2, 2, 44100, IDL_BUFFER_SIZE, 4);

	/* start channels */
	ofSoundStreamStart();
	
	/* pre-allocate global buffer */
	generalInputBuffer.allocate(IDL_BUFFER_SIZE, 2);
	
	/* soundListener points toward the global sound buffer */
	soundListener.setInputBuffer(&generalInputBuffer);
}

//--------------------------------------------------------------
void ofApp::update(){
	abletonSet.update();

	World& world = World::getInstance();
	
	soundListener.analyze();
	float env_bis = soundListener.getData().enveloppe;

	env -= 0.015;
	env = max(env, env_bis);
	env *= 2;
	env = 30;

	Selection selection;
	selection.radial(1, cursor, 200);
	Scalator m1(selection, ofVec2f(env, env), false, cursor, s1);
	Rotator m2(selection, 10, false, cursor, s2);
	//m1.apply();
	//m2.apply();
	
	cursor = ofPoint(mouseX, mouseY);
	
	
// 	auto gestures = deviceListener.getGestures();
// 	
// 	for(auto it = gestures.begin(); it != gestures.end(); ++it) {
// 		if(it->getType() == GestureTap)
// 			it->print();
// 	}
	
	auto act = gestureController->ComputeActions();

	for(auto a = act.begin(); a != act.end(); ++a) {
// 		if(!(*a)) cout << "pb" << endl;
		actions.push_front(*a);
	}
	
	cout << actions.size() << endl;
	
	executeActions();
	
	world.update();
	
	// leapmotion
	ofxLeapMotion &leap = deviceListener.getLeap();
	simpleHands = leap.getSimpleHands();
	if(leap.isFrameNew()) {
		
		leap.setMappingX(-230, 230, 0, ofGetWidth());
		leap.setMappingY(90, 490, ofGetHeight(), 0);
		leap.setMappingZ(-150, 150, -200, 200);
		
		simpleHands.clear();
		simpleHands = leap.getSimpleHands();
		
		if(!simpleHands.empty()) {
			cursor.x = simpleHands[0].handPos.x;
			cursor.y = simpleHands[0].handPos.y;
		}
		
		leap.markFrameAsOld();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	World& world = World::getInstance();
	ofFill();
	view.drawWorld(world);
	
	
	
	// leapmotion
	
/*	fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
	
	//cout << "hands number : " << simpleHands.size() << endl;
	
	for(int i = 0; i < simpleHands.size(); i++){
		bool isLeft        = simpleHands[i].isLeft;
		ofPoint handPos    = simpleHands[i].handPos;
		ofPoint handNormal = simpleHands[i].handNormal;
		
		cout << "isLeft : " << isLeft << endl;
		cout << "position : " << handPos<< endl;
		cout << "normal : " << handNormal << endl;
		
		for (int f=0; f<5; f++) {
			ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
			ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
			ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
			ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
		}
	}*/	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
		
	if (key == OF_KEY_RETURN) {
		abletonSet.printAll();
		return;
	}
	if (key == OF_KEY_DOWN ) {
		abletonSet.stop();
	}
	else
		abletonSet.play();	
	//live.setTempo(75);
	
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
	for(auto it = actions.begin(); it != actions.end(); ++it) {
		/* need to delete the action */
		auto next_it = it;
		++next_it;
		if(!(*it)->execute()) {
			actions.erase(it);
			it = next_it;
		}
	}
}
