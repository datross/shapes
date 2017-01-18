#include "ofxSvg.h"
#include "DreamBuilder.h"
#include "Utility.h"
#include "ActionFactory.h"

using namespace idl;

DreamBuilder::DreamBuilder() {
}

Shape DreamBuilder::parseShape(json j) {
	ofPath path = pathFromSvg("svg/" + j["path"].get<std::string>());
	Shape shape(path,
				parseVec2(j["position"]),
				parseVec2(j["speed"]),
				parseVec2(j["scale"]),
				parseFloat(j["rotation"]));
	
	return shape;
}

ofPath DreamBuilder::pathFromSvg(std::string path) {
	ofxSVG svg = FileManager::getInstance().loadSVGFile(path);
	/* TODO for the moment path to load is the first one */
	return svg.getPathAt(0);
}
	
void DreamBuilder::buildWorld(World& world) {
	/* first removes existing elements */
	world.clear();
	
	/* loading shapes file. */
	json worldJson = FileManager::getInstance().loadJSONFile("world", true);
	
	json & shapesJson = worldJson["shapes"];
	for(auto it = shapesJson.begin(); it != shapesJson.end(); ++it) {
		Shape shape = parseShape(*it);
		world.addShape(shape);
	}

	/*Laod all Actions*/
	ActionFactory::getInstance();
}


