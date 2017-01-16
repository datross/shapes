#include "ofMain.h"
#include "ofApp.h"
#include "FileManager.h"

#include <iostream>

using namespace std;
using namespace idl;

int main(int argc, char * argv[]){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	
	/* Init FileManager */
	
	/* Default path */
	std::string path = argv[0];
	
	/* else we take first argument of command line */
	if(argc > 1) {
		path = argv[1];
	}
	
	cout << "Directory path :" << path << endl;
	idl::FileManager::init(path);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	return ofRunApp(new ofApp());
}
