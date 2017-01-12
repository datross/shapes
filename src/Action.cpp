#include "Action.h"

using namespace idl;

Action::Action(unsigned _duration) : duration(_duration){
	birthTime = clock();
}

Action::~Action(){
}

bool Action::execute(){
	if (clock() - birthTime > duration)
		return false; /* to delete the action */
	apply();
	return true;
}


