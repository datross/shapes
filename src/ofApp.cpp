#include "ofApp.h"
#include <iostream>

using namespace idl;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);	
	ofSetFrameRate(60);
	
	
	world.setup();
	leap.open();
	live.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	live.update();
	world_transformed = world;
	
	Selection selection;
	selection.distance(world_transformed, 1, cursor, 200);
	Rotator rotator(selection, 30, false, cursor);
	rotator.apply();
	
	cursor = ofPoint(mouseX, mouseY);
	
	// leapmotion
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
	ofFill();
	view.drawWorld(world_transformed);
	
	// leapmotion
	
	fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
	
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
	}	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//live.setup();
	//live.update();
	if(key == OF_KEY_RETURN)
		live.printAll();
	else
		live.play();	
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
