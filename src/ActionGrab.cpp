#include "ActionGrab.h"

using namespace idl;

ActionGrab::ActionGrab(int duration) : Action(duration){
	age = clock();
}

ActionGrab::~ActionGrab(){
	
}

bool ActionGrab::apply(){
	return true;
}
