#ifndef GESTURE_H
#define GESTURE_H

#include <iostream>
#include <string>

namespace idl {

	/* different types of gesture. */
	enum GestureType { 
		GestureGrab, 
		GestureXMove, 
		GestureYMove, 
		GestureTap, 
		GesturePinch
	};

	/* stores a gesture, with its type, its hand, and parameter. */
	class Gesture
	{
		bool isLeft;
		GestureType type;
		float value;

	public:
		Gesture();
		Gesture(bool isLeft, GestureType type, float value);
		~Gesture();

		bool        isRight()  const { return !isLeft; }
		GestureType getType()  const { return type;    }
		float       getValue() const { return value;   }
		
		std::string getTypeString();
		
		/* debug */
		void print() {
			std::cout << "hand : " << isLeft ? "Left" : "Right";
			std::cout << " type : " << type;
			std::cout << " value : " << value;
			std::cout << std::endl;
		}
	};

}
#endif
