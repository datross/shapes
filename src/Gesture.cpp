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
