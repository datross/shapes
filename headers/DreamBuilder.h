#ifndef DREAM_BUILDER_H
#define DREAM_BUILDER_H

#include "FileManager.h"
#include "shape.h"
#include "world.h"

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
		
		/**
		 * @brief Corresponds to the dream subdirectory
		 */
		std::string currentDream;
		
		/**
		 * @brief Parse a string to a float
		 * 
		 * @param s ...
		 * @return float
		 */
		float parseFloat(std::string s);
		
		/**
		 * @brief Parse a string to an ofVec2f.
		 * 
		 * @param s ...
		 * @return ofVec2f
		 */
		ofVec2f parseVec2(std::string s);
	public:
		DreamBuilder();
		
		void buildWorld(World& world);
		
		/* TODO probablement temporaire */
		void setDream(std::string dream) {
			currentDream = dream;
		}
	};
	
}

#endif