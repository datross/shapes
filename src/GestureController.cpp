#include "GestureController.h"

using namespace idl;
using namespace std;

GestureController::GestureController(DeviceListener & _deviceListener)
	: deviceListener(_deviceListener), linkTable(FileManager::getInstance().loadJSONFile("gestureMapping", true)) {
}

shared_ptr<Action> GestureController::ComputeAction(idl::Gesture gesture) {
	string request;
	auto tmp = linkTable.find(gesture.getTypeString());
	if(tmp == linkTable.end())
		return nullptr;
	return ActionFactory::getInstance().create(tmp->get<string>());
}

vector<shared_ptr<Action > > GestureController::ComputeActions() {
	auto gestures = deviceListener.getGestures();
	vector<shared_ptr<Action> > actions;
	for(auto g = gestures.begin(); g < gestures.end(); ++g) {
		auto ptr = ComputeAction(*g);
		if(ptr) {
			actions.push_back(ptr);
		}
	}
	return actions;
}

