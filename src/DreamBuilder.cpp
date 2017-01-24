#include "ofxSvg.h"
#include "DreamBuilder.h"
#include "Utility.h"
#include "ActionFactory.h"
#include "OscWrapper.h"

using namespace idl;

DreamBuilder::DreamBuilder() {
}

Shape DreamBuilder::parseShape(json j) {
	ofPath path = pathFromSvg("svg/" + j["path"].get<std::string>());
	Shape shape(path,
				parseVec2(j["position"]),
				parseVec2(j["speed"]),
				parseVec2(j["scale"]),
				parseFloat(j["rotation"]),
				j["id"]);
	
	return shape;
}

ofPath DreamBuilder::pathFromSvg(std::string path) {
	ofxSVG svg = FileManager::getInstance().loadSVGFile(path);
	/* TODO for the moment path to load is the first one */
	ofPath pathSvg = svg.getPathAt(0);
	for (int i = 1; i < svg.getNumPath(); i++){
		pathSvg.newSubPath();
		pathSvg.append(svg.getPathAt(i));
	}
	return pathSvg;
}
	
void DreamBuilder::buildWorld(World& world) {
	/* first removes existing elements */
	world.clear();
	
	/* loading shapes file. */
	json worldJson = FileManager::getInstance().loadJSONFile("world", true);
	
	/*loading background video*/
	json & backgroundJson = worldJson["background"];
	ofVideoPlayer background = FileManager::getInstance().loadMovBackground(backgroundJson["path"]);
	world.addBackground(background);

	/*loading dream masks*/
	json & masksJson = worldJson["masks"];
	ofxSVG svg = FileManager::getInstance().loadSVGFile("svg/masks/" + masksJson["path"].get<std::string>());
	for (int i = 0; i < svg.getNumPath(); i++){
		ofPath path;
		path = svg.getPathAt(i);
		Shape shape(path, ofVec2f(0,0));
		world.addMask(shape);
	}

	json & shapesJson = worldJson["shapes"];
	for(auto it = shapesJson.begin(); it != shapesJson.end(); ++it) {
		Shape shape = parseShape(*it);
		world.addShape(shape);
	}

	/*Loading all Actions*/
	ActionFactory::getInstance();

	/*Loading sound Modifier*/
	OscWrapper::getInstance();
}


