#include "shape.h"

using namespace idl;
//using namespace std;

static const ofVec2f DEFAULT_POS(0, 0);
static const ofVec2f DEFAULT_SPEED(0, 0);
static const ofVec2f DEFAULT_SCALE(1, 1);
static const float DEFAULT_ROTATION = 0.;

Shape::Shape()
	: position(DEFAULT_POS), 
	speed(DEFAULT_SPEED), 
	scale(DEFAULT_SCALE), 
	rotation(DEFAULT_ROTATION)
{
}

Shape::Shape(ofPath & _path, ofVec2f pos, ofVec2f _speed, ofVec2f _scale, float r)
	: positionOrigin(pos), speed(_speed), scaleOrigin(_scale), rotationOrigin(r), path(_path){
	speed = ofVec2f(0);
	scaleSpeed = ofVec2f(0);
	rotationSpeed = 0;
	
	mass = 1.;
	massRotation = 1.;
	massScale = 1.;
}

Shape::Shape(ofPath& path, ofVec2f pos) : Shape(){
	position = pos;
	path = path;
}

void Shape::addForce(ofVec2f a) {
	acceleration += a / mass;
}

void Shape::addScaleForce(ofVec2f a) {
	scaleAcceleration += a / massScale;
}

void Shape::addRotationForce(float a) {
	rotationAcceleration += a / massRotation;
}

void Shape::addPosition(ofVec2f p) {
	position += p;
}

void Shape::addRotation(float r){
	rotation += r;
}

void Shape::addScale(ofVec2f s){
	scale += s;
}

void Shape::draw(){
	ofPushMatrix();
	ofTranslate(position.x, position.y, 0.);
	ofRotate(rotation);
	ofScale(scale.x, scale.y, 1.);

	path.draw();

	ofPopMatrix();
}

// void Shape::resetTransform() {
// 	position = positionOrigin;
// 	scale = scaleOrigin;
// 	rotation = rotationOrigin;
// }

float invSqr(ofVec2f a, ofVec2f b) {
	float dist = (b - a).length();
	return 1. / (dist * dist);
}

void Shape::update() {
	/* update position, speed, scale, rotation etc.. */
	speed += acceleration;
	position += speed;
	
	scaleSpeed += scaleAcceleration;
	scale += scaleSpeed;
	
	rotationSpeed += rotationAcceleration;
	rotation += rotationSpeed;
	
	/* update forces */
	acceleration = -1. * speed * DAMPNESS_POSITION;
	acceleration += (positionOrigin - position).normalize() * invSqr(position, positionOrigin) * GRAVITY_ORIGIN_POSITION;
	
	scaleAcceleration = -1 * scaleSpeed * DAMPNESS_SCALE;
	scaleAcceleration += (scaleOrigin - scale).normalize() * invSqr(scale, scaleOrigin) * GRAVITY_ORIGIN_SCALE;
	
	rotationAcceleration = -1 * rotationSpeed * DAMPNESS_ROTATION;
	rotationAcceleration += GRAVITY_ORIGIN_ROTATION / ((rotationOrigin - rotation) * (rotationOrigin - rotation));
}