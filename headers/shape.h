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
	protected:
		/* physics parameters */
		ofVec2f position, speed, acceleration;
		ofVec2f positionOrigin;
		
		ofVec2f scale, scaleSpeed, scaleAcceleration;
		ofVec2f scaleOrigin;
		
		float rotation, rotationSpeed, rotationAcceleration;
		float rotationOrigin;
		
		float mass, massRotation, massScale;

		std::string id;
	
		/* shape to draw */
		ofPath path;
		ofColor originColor;
	public:
		Shape();
		Shape(ofPath & path, ofVec2f pos, ofVec2f _speed, ofVec2f _scale, float r, std::string _id);
		Shape(ofPath & path, ofVec2f pos);
		
		/* physics manipulation */
		virtual void addForce(ofVec2f a);
		virtual void addScaleForce(ofVec2f a);
		virtual void addRotationForce(float a);
		
		virtual void addPosition(ofVec2f p);
		virtual void addScale(ofVec2f s);
		virtual void addRotation(float r);
		
		ofColor getColor();
		ofColor getOriginColor();
		void setColor(ofColor c);

		ofVec2f getPosition() { return position; }
		std::string getId() { return id; }
		
		virtual void update(float timeStep);
		
		//void resetTransform();
		
		void draw();
	};

}

#endif
