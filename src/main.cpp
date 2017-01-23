#include "ofMain.h"
#include "ofApp.h"
#include "FileManager.h"

#include <iostream>

using namespace std;
using namespace idl;

int main(int argc, char * argv[]){
// 	ofSetupOpenGL(1024,768,OF_GAME_MODE);			// <-------- setup the GL context
	ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context
	
	/* Init FileManager */
	
	/* Default path */
	ofDirectory dirPath(ofFilePath::getCurrentExeDir() + "/../dreams/");
	
	/* else we take first argument of command line */
	if(argc > 1) {
		dirPath.open(ofFilePath::getCurrentWorkingDirectory() + "/" + argv[1]);
	}
	
	cout << "Directory path : " << dirPath.getAbsolutePath() << endl;
	FileManager::init(dirPath.getAbsolutePath());

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	return ofRunApp(new ofApp());
}
