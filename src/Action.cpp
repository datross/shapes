#include "Action.h"

using namespace idl;

Action::Action(int d) : duration(d){
}

Action::~Action(){
}

bool Action::execute(){
	age += clock();
	if (age > duration)
		return false; //to delete the action
	return apply();
}