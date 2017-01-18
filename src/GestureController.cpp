#include "GestureController.h"

using namespace idl;
using namespace std;

GestureController::GestureController(DeviceListener & _deviceListener, json _linkTable)
	: deviceListener(_deviceListener), linktable(_linkTable) {
}

vector<shared_ptr<Action > > GestureController::ComputeAction() {
	auto gestures = deviceListener.getGestures();
	
	
}

