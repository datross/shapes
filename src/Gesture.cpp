#include "Gesture.h"

using namespace idl;

idl::Gesture::Gesture() {
}

idl::Gesture::Gesture(bool _isLeft, GestureType _type, float _value) {
	isLeft = _isLeft;
	type   = _type;
	value  = _value;
}

idl::Gesture::~Gesture() {
}

std::string Gesture::getTypeString() {
	switch(type) {
		case GestureGrab  : return "grab";
		case GestureXMove : return "xmove";
		case GestureYMove : return "ymove";
		case GestureTap   : return "tap";
		case GesturePinch : return "pinch";
		default           : return ""; // TODO
	}
}
