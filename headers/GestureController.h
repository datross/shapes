#ifndef GESTURE_CONTROLLER_H
#define GESTURE_CONTROLLER_H

#include "ActionFactory.h"
#include "DeviceListener.h"
#include "FileManager.h"
#include <memory>
#include <vector>

namespace idl {

	/**
	 * @brief Computes action according to gesture sent by deviceListener.
	 */
	class GestureController {
	private:
		DeviceListener & deviceListener;
		
		/**
		 * @brief Stores links between gestures and actions.
		 */
		json linktable;
	public:
		GestureController(DeviceListener & deviceListener, json linkTable);
		
		std::vector<std::shared_ptr<Action> > ComputeAction();
	};
}

#endif