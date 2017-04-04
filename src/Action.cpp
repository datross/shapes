#include "Action.h"

#include "ofMain.h"

using namespace idl;

Action::Action(float _duration,  std::vector< std::shared_ptr<Modifier> > _modifiers, std::string key) : duration(_duration), modifiers(_modifiers), id(key), die(false) {
	birthTime = ofGetElapsedTimef();
}

Action::~Action(){
}

bool Action::execute() {
	/* the order is important. If animation duration is 0, then it would be 
	 * applied once. */
	apply();
	if (ofGetElapsedTimef()- birthTime > duration || die)
		return false; /* to delete the action */
	return true;
}

void Action::apply(){
	for(auto it = modifiers.begin(); it != modifiers.end(); ++it) {
		(*it)->apply();
	}
}

void Action::suicide() {
  for(auto modif : modifiers) {
    modif->reset();
  }
  die = true;
}

void Action::reset() {
  die = false;
  setBirthTime(ofGetElapsedTimef());
}
