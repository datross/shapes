#include "ofxSvg.h"
#include "DreamBuilder.h"
#include "Utility.h"

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
	json worldJson = FileManager::getInstance().loadJSONFile(currentDream + '/' + "world");
	
	json & shapesJson = worldJson["shapes"];
	for(auto it = shapesJson.begin(); it != shapesJson.end(); ++it) {
		Shape shape = parseShape(*it);
		world.addShape(shape);
	}
}

float DreamBuilder::parseFloat(string s) {
	return convert<float, string>(s);
}

ofVec2f DreamBuilder::parseVec2(string s) {
	auto v = split(s, ' ');
	return ofVec2f(convert<float, string>(v[0]),
				   convert<float, string>(v[1]));
}


