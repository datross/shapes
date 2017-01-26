#ifndef DEEP_ACTION_CONTROLLER_H
#define DEEP_ACTION_CONTROLLER_H

#include <vector>
#include "DeviceListener.h"
#include "Action.h"
#include "ActionFactory.h"

namespace idl {
	
	class DeepActionController {
	private:
		DeviceListener & deviceListener;
		
		std::vector<std::string> deep;
		std::vector<std::string> sleep;
		std::vector<std::string> awake;
		
		std::vector< std::shared_ptr<Action> > currentActions;
		
		bool awakeState, startTime, fallingAsleep;
		float noHandTime;
		
		bool checkState();
		void cleanCurrentActions();
		void addAction(string s);
		
	public:
		DeepActionController(DeviceListener & deviceListener);
		
		std::vector<std::shared_ptr<Action> > ComputeActions();
	};
	
}

#endif