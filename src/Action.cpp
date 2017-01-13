#include "Action.h"

using namespace idl;

Action::Action(unsigned _duration,  std::vector< std::shared_ptr<Modifier> > _modifiers) : duration(_duration), modifiers(_modifiers) {
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

void Action::apply()
{
	for(auto it = modifiers.begin(); it != modifiers.end(); ++it) {
		(*it)->apply();
	}
}

