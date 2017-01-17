#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include "json.hpp"
#include "ofxSvg.h"
#include "ofMain.h"

using json = nlohmann::json;

/**
 * @file Contains the FileManager.
*/

namespace idl {

	/**
	* @brief Handles every interacing with actual JSON files on disk.
	*/
	class FileManager {
	private:
		
		/**
		 * @brief Path to the directory containing the dream files.
		 */
		ofDirectory sessionDirectory;
		
		FileManager(std::string path);
	public:
		
		/**
		 * @brief Constructs the FileManager, giving it the path.
		 * This function must be called once before any call to getInstance().
		 * 
		 * @param path Path to the directory containing the dream files.
		 * @return void
		 */
		static void init(std::string path);
		
		/**
		 * @brief Returns the singleton instance of the FileManager.
		 * 
		 * @param path Path to directory. This parameter has no importance after after having called init().
		 * @return A reference to the FileManager. 
		 */
		static FileManager & getInstance(std::string path = "");
		
		/**
		 * @brief Loads a file in the dream directory.
		 * 
		 * @param path File name.
		 * @return json
		 */
		json loadJSONFile(std::string path);
		
		/**
		 * @brief Loads an SVG file in the dream directory
		 * 
		 * @param path File name.
		 * @return ofxSVG
		 */
		ofxSVG loadSVGFile(std::string path);
	};
	
}

#endif