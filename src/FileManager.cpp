#include "FileManager.h"
#include <fstream>

using namespace idl;
using namespace std;

FileManager::FileManager(string path)
	: dirPath(path) {
}


FileManager & FileManager::getInstance(string path) {
	static FileManager instance(path);
	return instance;
}

void FileManager::init(string path) {
	getInstance(path);
}

json FileManager::loadJSONFile(string path) {
	ifstream file(getPath(path));
	json j;
	if(!file) {
		cerr << "Cannot open file : " << path << endl;
		return j;
	}
	j << file;
	return j;
}

ofxSVG FileManager::loadSVGFile(string path) {
	ofxSVG svg;
	svg.load(dirPath + "/" + path);
	return svg;
}


std::string FileManager::getPath(std::string file) {
	return dirPath + "/" + 	file + ".json";
}