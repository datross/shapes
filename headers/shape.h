#ifndef SHAPE_H
#define SHAPE_H

#include "ofMain.h"

namespace idl {

	class Shape{
		ofVec2f position;
		ofVec2f speed;
		ofVec2f scale;
		float rotation;
	
		ofPath path;
	
	public:
		Shape();
		Shape(ofVec2f & pos, ofPath & path, ofVec2f & _speed, ofVec2f & _scale, float r);
		Shape(ofVec2f & pos, ofPath & path);
		void addRotation(float);
		ofVec2f getPosition() { return position; }
		void rotatePosition(float r, ofVec3f pivot);
		void draw();
	};

}

#endif