#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <sstream>
#include <vector>
#include <ofMain.h>

/**
 * @file Utility.h 
 * Some useful functions.
 */


/**
 * @brief Returns +1 if a >= 0, -1 else.
 * 
 * @param a The type you want (works with int, float double...)
 * @return T
 */
template<class T>
T sign(float a) {
	if(a >= 0)
		return 1;
	else
		return -1;
}

/**
 * @brief Convert s from type *src* to type *dst*.
 * 
 * Works with stringstream, so either *src* or *dst* must be of type std::string.
 * 
 * @param s Variable to convert.
 * @return dst
 */
template<class dst, class src>
dst convert(src s) {
	std::stringstream ss;
	ss << s;
	dst d;
	ss >> d;
	return d;
}

/**
 * @brief Splits the given string with the given separator.
 * 
 * @param str String to be splitted.
 * @param separator Separator. Default to ' '.
 * @return std::vector<std::string>
 */
std::vector<std::string> split(const std::string& str, char separator = ' ');


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

/**
* @brief Parse a string to an ofVec3f.
*
* @param s ...
* @return ofVec3f
*/
ofVec3f parseVec3(string s);


/**
* @brief Parse a string to an ofVec3f.
*
* @param s ...
* @return ofVec3f
*/
ofPoint parsePoint(string s);

#endif