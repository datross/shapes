#ifndef HUD_H
#define HUD_H

#include "ofMain.h"
#include <vector>
#include <string>

#include "Utility.h"

#define HUD_LEFT_MARGIN 10
#define HUD_TOP_MARGIN 5

namespace idl {

class Hud {
private:
	std::vector<std::string> lines;
	float timePrec;
	
	ofTrueTypeFont font;
	
	Hud();
public:
	static Hud& getInstance();
	
	void draw(bool visible = true);
	void addEntry(std::string str);
	
	template<class T>
	void addEntry(std::string key, T value) {
		addEntry(key + " : " + convert<std::string, T>(value));
	}
};

}

#endif