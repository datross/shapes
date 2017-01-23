#ifndef DREAM_BUILDER_H
#define DREAM_BUILDER_H

#include "FileManager.h"
#include "shape.h"
#include "world.h"
#include "GestureController.h"

namespace idl {

	class DreamBuilder {
	private:
		Shape parseShape(json j);
		
		/**
		 * @brief Creates an ofPath from a svg file.
		 * 
		 * @param path Real path to the real file.
		 * @return ofPath
		 */
		ofPath pathFromSvg(std::string path);

	public:
		DreamBuilder();
		
		void buildWorld(World& world);
		
// 		/**
// 		 * @brief 
// 		void initGestureController(GestureController & gestureController);
	};
	
}

#endif
