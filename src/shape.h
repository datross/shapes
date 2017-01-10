#ifndef SHAPE_H
#define SHAPE_H

#include "ofMain.h"

namespace idl {

struct Shape {
	ofVec2f position;
	ofVec2f speed;
	ofVec2f scale;
	float rotation;
	
	ofPath path;
	
	Shape();
};

}

#endif