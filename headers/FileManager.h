#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <json.hpp>
#include <ofxSvg.h>

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
		std::string dirPath;
		
		FileManager(std::string path);
		
		/**
		 * @brief Returns the path of the file, according to dirPath and some conventions.
		 * 
		 * @param file Name of the file, or "module". It hasn't any extension.
		 * @return Absolute path to the file.
		 */
		std::string getPath(std::string file);
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


		/**
		* @brief File a actions' map with namefile and his corresponding json action
		* 
		* @param actions Map to fill
		*/
		void initActions(std::map<std::string, json>& actions);
	};
	
}

#endif