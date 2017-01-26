#include "DeepActionController.h"
#include "FileManager.h"

using namespace idl;
using namespace std;

const static float NO_HAND_DURATION = 5;

DeepActionController::DeepActionController(DeviceListener& _deviceListener) : deviceListener(_deviceListener) {
	awakeState = false;
	startTime = true;
	fallingAsleep = false;
	json j = FileManager::getInstance().loadJSONFile("deepActionsIndex", true);
	for(auto& d : j["deep"]) {
		deep.push_back(d.get<string>());
	}
	for(auto& d : j["sleep"]) {
		sleep.push_back(d.get<string>());
	}
	for(auto& d : j["awake"]) {
		awake.push_back(d.get<string>());
	}
}

bool DeepActionController::checkState(){
	if(awakeState && !deviceListener.getLeap().hasHand()){
		if(!fallingAsleep) {
			fallingAsleep = true;
			noHandTime = ofGetElapsedTimef();
		} else {
			if(ofGetElapsedTimef() - noHandTime > NO_HAND_DURATION){
				awakeState = false;
				fallingAsleep = false;
				return true;
			}
		}
	}
	if(deviceListener.getLeap().hasHand()){
		fallingAsleep = false;
		if(!awakeState) {
			awakeState = true;
			return true;
		}
		return false;
	}
	return false;
}

void DeepActionController::cleanCurrentActions(){
	for(auto& a : currentActions){
		a->suicide();
	}
	currentActions.clear();
}

void DeepActionController::addAction(string s){
	auto a = ActionFactory::getInstance().create(s);
	if(a)
		currentActions.push_back(a);
}

vector< shared_ptr< Action > > DeepActionController::ComputeActions() {
	if(!startTime && !checkState())
		return vector< shared_ptr< Action > >();
	cleanCurrentActions();
	if(awakeState){
		for(auto& s : awake){
			addAction(s);
		}
	}else{
		for(auto& s : sleep){
			addAction(s);
		}
	}
	if(startTime){
		vector< shared_ptr< Action > > actions;
		for(auto& s : deep){
			auto a = ActionFactory::getInstance().create(s);
			if(a)
				actions.push_back(a);
		}
		actions.insert(actions.end(), currentActions.begin(), currentActions.end());
		startTime = false;
		return actions;
	}
	return currentActions;
}
