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

	std::string gestType;

	switch(type) {
	case GestureGrab: gestType = "grab"; break;
		case GestureXMove : gestType = "xmove"; break;
		case GestureYMove : gestType = "ymove"; break;
		case GestureTap   : gestType = "tap"; break;
		case GesturePinch : gestType = "pinch"; break;
		default           : return "";  break;
	}
	if (isLeft)
		gestType = "left-" + gestType;
	else
		gestType = "right-" + gestType;

	return gestType;
}
