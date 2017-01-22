#ifndef SHAPE_H
#define SHAPE_H

#include "ofMain.h"

namespace idl {
	
#define DAMPNESS_POSITION 0.9
#define DAMPNESS_SCALE 0.9
#define DAMPNESS_ROTATION 1.
#define GRAVITY_ORIGIN_POSITION 2.
#define GRAVITY_ORIGIN_SCALE 10.
#define GRAVITY_ORIGIN_ROTATION 1.

	class Shape{
		/* physics parameters */
		ofVec2f position, speed, acceleration;
		ofVec2f positionOrigin;
		
		ofVec2f scale, scaleSpeed, scaleAcceleration;
		ofVec2f scaleOrigin;
		
		float rotation, rotationSpeed, rotationAcceleration;
		float rotationOrigin;
		
		float mass, massRotation, massScale;
	
		/* shape to draw */
		ofPath path;
	public:
		Shape();
		Shape(ofPath & path, ofVec2f pos, ofVec2f _speed, ofVec2f _scale, float r);
		Shape(ofPath & path, ofVec2f pos);
		
		/* physics manipulation */
		void addForce(ofVec2f a);
		void addScaleForce(ofVec2f a);
		void addRotationForce(float a);
		
		void addPosition(ofVec2f p);
		void addScale(ofVec2f s);
		void addRotation(float r);
		
		ofVec2f getPosition() { return position; }
		
		void update(float timeStep);
		
		//void resetTransform();
		
		void draw();
	};

}

#endif