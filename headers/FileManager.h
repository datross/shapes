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
		
		/**
		 * @brief Name of the dream currently loaded.
		 */
		std::string currentDream;
		
		/**
		 * @brief List of the dreams names
		 */
		std::vector<std::string> dreams;
		unsigned dream_index;
		
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
		 * @param dreamDir If true, the file is loading in the currentDream directory.
		 * @return json
		 */
		json loadJSONFile(std::string path, bool dreamDir = false);
		
		/**
		 * @brief Loads an SVG file in the dream directory
		 * 
		 * @param path File name.
		 * @return ofxSVG
		 */
		ofxSVG loadSVGFile(std::string path);

		/**
		* @brief Loads an background video (.mov) file in the dream directory
		*
		* @param path File name.
		* @return ofVideoPlayer
		*/
		ofVideoPlayer loadMovBackground(std::string path);

		/**
		* @brief File a actions' map with namefile and his corresponding json action
		* 
		* @param actions Map to fill
		*/
		void initActions(std::map<std::string, json>& actions);
		
		/**
		 * @brief Simple setter.
		 * 
		 * @param currentDream Name of the dream
		 */
		void setCurrentDream(std::string currentDream);
		
		/**
		 * @brief Change current dream
		 */
		void nextDream();
	};
	
}

#endif
