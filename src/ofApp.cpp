#include "ofApp.h"
#include <iostream>

using namespace idl;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);	
	ofSetFrameRate(60);
	
	
	const int nb_x = 46,
			  nb_y = 32;
	for(unsigned x = 0; x < nb_x; ++x) {
		for(unsigned y = 0; y < nb_y; ++y) {
			Shape shape;
			shape.path.rectangle(0,0,20,20);
			shape.path.setColor(ofColor(0,100,150));
			shape.position = ofVec2f(x * ofGetWidth() / nb_x, y * ofGetHeight() / nb_y);
			
			world.shapes.push_back(shape);
		}
	}
	
	leap.open();
	live.setup();
	//live.setup("192.168.1.105");*/
}

//--------------------------------------------------------------
void ofApp::update(){
	//live.update();
	
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
	live.update();
	live.printAll();
	//live.setTempo(75);
	live.play();	
	
	
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
