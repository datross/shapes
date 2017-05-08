#include "shape.h"
#include "Hud.h"

#include <cmath>

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

Shape::Shape(ofPath & _path, ofVec2f pos, ofVec2f _speed, ofVec2f _scale, float r, float t,std::string _id)
	: positionOrigin(pos), speed(_speed), scaleOrigin(_scale), rotationOrigin(r), path(_path), id(_id){

	position = positionOrigin;
	scale = scaleOrigin;
	rotation = rotationOrigin;

	speed = ofVec2f(0);
	scaleSpeed = ofVec2f(0);
	rotationSpeed = 0;
	mass = 1.;
	massRotation = 1.;
	massScale = 1.;
	
	acceleration = ofVec2f(0);
	scaleAcceleration = ofVec2f(0);
	rotationAcceleration = 0;

	ofColor color = ofColor(path.getFillColor().r,path.getFillColor().g, path.getFillColor().b, t*255);
	path.setColor(color);
	originColor = path.getFillColor();
}

ofColor Shape::getColor() {
	return path.getFillColor();
}

ofColor Shape::getOriginColor() {
	return originColor;
}

void Shape::setColor(ofColor c) {
	path.setFillColor(c);
}

Shape::Shape(ofPath& _path, ofVec2f pos) : Shape(){
	position = pos;
	path = _path;
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
	ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
	ofTranslate(position.x, position.y, 0.);
	ofRotate(rotation);
	ofScale(scale.x, scale.y, 1.);

	path.draw();

	ofPopMatrix();
}


void Shape::bezierNoise(ofVec2f movement){
	std::vector<ofPolyline> subpaths = path.getOutline();
	path.clear();
	srand(time(NULL));
	for (std::vector<ofPolyline>::iterator it = subpaths.begin() ; it != subpaths.end(); ++it){
		ofPoint random(ofRandom(-movement.x, movement.x),ofRandom(-movement.y, movement.y), 0);
		std::vector<ofPoint> points = (*it).getVertices();
		path.moveTo(points.at(0) + random);
		ofPoint randomX(ofRandom(-points.at(0).x, points.at(0).x),ofRandom(-points.at(0).y, points.at(0).y), 0);
		ofPoint randomY(ofRandom(-points.back().x, points.back().x),ofRandom(-points.back().y, points.back().y), 0);
		path.bezierTo(randomX, randomY, points.back());
		for (std::vector<ofPoint>::iterator itPoints = points.begin() ; itPoints != points.end(); ++itPoints){
				path.lineTo((*itPoints) + random);
		}
		path.newSubPath();
	}

}

// void Shape::resetTransform() {
// 	position = positionOrigin;
// 	scale = scaleOrigin;
// 	rotation = rotationOrigin;
// }

void Shape::update(float timeStep) {
	/* update position, speed, scale, rotation etc.. */
	speed += acceleration * timeStep;
	position += speed * timeStep;
	
	scaleSpeed += scaleAcceleration * timeStep;
	scale += scaleSpeed * timeStep;
	
	rotationSpeed += rotationAcceleration * timeStep;
	rotation += rotationSpeed * timeStep;
	
	rotation = fmod(rotation, 360.);
	
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
