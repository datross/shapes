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
		Shape(ofPath & path, ofVec2f pos, ofVec2f _speed, ofVec2f _scale, float r);
		Shape(ofPath & path, ofVec2f pos);
		
		void addRotation(float);
		void addScale(ofVec2f s);
		void addSpeed(ofVec2f v);
		void addPosition(ofVec2f v);
		void rotatePosition(float r, ofVec3f pivot);
		
		ofVec2f getPosition() { return position; }
		
		void update();
		
		void draw();
	};

}

#endif
