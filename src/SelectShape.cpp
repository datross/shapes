#include "SelectShape.h"
using namespace idl;

SelectShape::SelectShape(shared_ptr<Selection> s)
    : Shape::Shape() {
	shapes = s->getShapes();
    ofVec2f barycentre(0,0);
    for(auto s: shapes) {
        barycentre += s.shape->getPosition();
    }
    barycentre *= (float)shapes.size();
}


SelectShape::~SelectShape()
{
}

// /* physics manipulation */
// void SelectShape::addForce(ofVec2f a) {
//     for(auto s: shapes) {
//         s.shape->addForce(a);
//     }
// }

// void SelectShape::addScaleForce(ofVec2f a) {
    
// }

// void addRotationForce(float a);
		
// void addPosition(ofVec2f p);
// void addScale(ofVec2f s);
// void addRotation(float r);
		
// ofColor getColor();
// ofColor getOriginColor();
// void setColor(ofColor c);

// ofVec2f getPosition() { return position; }
// std::string getId() {return id; }
// void bezierNoise(ofVec2f movement);
		
void SelectShape::update(float timeStep) {
	/* update position, speed, scale, rotation etc.. */
	speed += acceleration * timeStep;
	scaleSpeed += scaleAcceleration * timeStep;
	rotationSpeed += rotationAcceleration * timeStep;

	position += speed * timeStep;
	scale += scaleSpeed * timeStep;
	rotation += rotationSpeed * timeStep;
	rotation = fmod(rotation, 360.);

    for(auto s: shapes) {
        s.shape->setOriginPosition(position);
    }

	/* update forces */
	acceleration = ofVec2f(0);
	scaleAcceleration = ofVec2f(0);
	rotationAcceleration = 0;
	
	
	addForce(-1. * speed * DAMPNESS_POSITION);
	addForce((positionOrigin - position) * GRAVITY_ORIGIN_POSITION);
	
	addScaleForce(-1 * scaleSpeed * DAMPNESS_SCALE);
	addScaleForce((scaleOrigin - scale) * GRAVITY_ORIGIN_SCALE);
	
	addRotationForce(-1 * rotationSpeed * DAMPNESS_ROTATION);
	addRotationForce(GRAVITY_ORIGIN_ROTATION * (rotationOrigin - rotation));
}
		
//void resetTransform();
		
void SelectShape::draw(){
}
