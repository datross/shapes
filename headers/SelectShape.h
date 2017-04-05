#ifndef SELECTSHAPE_H
#define SELECTSHAPE_H

#include "selection.h"


namespace idl {

	class SelectShape : public Shape, public Selection	{
	public:
		SelectShape(shared_ptr<Selection> s);
		~SelectShape();

		/* physics manipulation */
		/* void addForce(ofVec2f a); */
		/* void addScaleForce(ofVec2f a); */
		/* void addRotationForce(float a); */
		
		/* void addPosition(ofVec2f p); */
		/* void addScale(ofVec2f s); */
		/* void addRotation(float r); */
		
		/* ofColor getColor(); */
		/* ofColor getOriginColor(); */
		/* void setColor(ofColor c); */

		/* ofVec2f getPosition() { return position; } */
		/* std::string getId() {return id; } */
		/* void bezierNoise(ofVec2f movement); */
		
		void update(float timeStep);
		
		//void resetTransform();
		
		void draw();
	private:

	};

}

#endif // !SELECTSHAPE_H
