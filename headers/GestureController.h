#ifndef GESTURE_CONTROLLER_H
#define GESTURE_CONTROLLER_H

#include "ActionFactory.h"
#include "DeviceListener.h"
#include "FileManager.h"
#include <memory>
#include <vector>

namespace idl {

	/**
	 * @brief Computes action according to gestures sent by deviceListener.
	 */
	class GestureController {
	private:
		DeviceListener & deviceListener;
		
		/**
		 * @brief Stores links between gestures and actions.
		 */
		json linkTable;
		
		/**
		 * @brief Computes the action according to the gesture, and returns a pointer toward it.
		 */
		std::shared_ptr<Action> ComputeAction(Gesture gesture);
	public:
		GestureController(DeviceListener & deviceListener);
		
		std::vector<std::shared_ptr<Action> > ComputeActions();
		
		void updateLinkTable();
	};
}

#endif