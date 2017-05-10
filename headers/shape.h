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

	static const ofVec2f DEFAULT_POS(0, 0);
	static const ofVec2f DEFAULT_SPEED(0, 0);
	static const ofVec2f DEFAULT_SCALE(1, 1);
	static const float DEFAULT_ROTATION = 0.;

	class Shape{
	protected:
		void initDefault(ofVec2f pos=DEFAULT_POS, ofVec2f _speed=DEFAULT_SPEED, ofVec2f _scale=DEFAULT_SCALE, float r=DEFAULT_ROTATION);
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
		Shape(ofVec2f pos);
		Shape(ofPath & path, ofVec2f pos, ofVec2f _speed, ofVec2f _scale, float r, float t, std::string _id);
		Shape(ofPath & path, ofVec2f pos);
		
		void setOriginPosition(ofVec2f pos);
		void setOriginScale(ofVec2f scale);
		void setOriginRotation(float rotation);

		/* physics manipulation */
		void addForce(ofVec2f a);
		void addScaleForce(ofVec2f a);
		void addRotationForce(float a);
		
		void addPosition(ofVec2f p);
		void addScale(ofVec2f s);
		void addRotation(float r);
		
		ofColor getColor();
		ofColor getOriginColor();
		void setColor(ofColor c);

		ofVec2f getPosition() { return position; }
		std::string getId() {return id; }
		void bezierNoise(ofVec2f movement);
		
		virtual void update(float timeStep);
		
		//void resetTransform();
		
		ofPath & getPath() { return path; }
		
		void draw();
	};

}

#endif
