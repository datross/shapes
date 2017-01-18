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
	: position(pos), speed(_speed), scale(_scale), rotation(r), path(_path){
}

Shape::Shape(ofPath& path, ofVec2f pos) : Shape(){
	position = pos;
	path = path;
}


void Shape::addRotation(float r){
	rotation += r;
}

void Shape::addScale(ofVec2f s){
	scale += s;
}

void Shape::rotatePosition(float r, ofVec3f pivot){
	position.rotate(r, pivot);
}

void Shape::draw(){
	ofPushMatrix();
	ofTranslate(position.x, position.y, 0.);
	ofRotate(rotation);
	ofScale(scale.x, scale.y, 1.);

	path.draw();

	ofPopMatrix();
}

void Shape::addSpeed(ofVec2f v){
	speed += v;
}

void Shape::update() {
	position += speed;
	speed = ofVec2f(0, 0);
}