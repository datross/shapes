#include "FileManager.h"
#include <fstream>
#include <iostream>

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
	cout << "Loading file : " << getPath(path) << endl;
	ifstream file(getPath(path));
	json j;
	if(!file) {
		cerr << "Cannot open file : " << getPath(path) << endl;
		return j;
	}
	j << file;
	return j;
}

ofxSVG FileManager::loadSVGFile(string path) {
	ofxSVG svg;
	cout << "Loading file : " << dirPath + "/" + path << endl;
	svg.load(dirPath + "/" + path);
	return svg;
}


std::string FileManager::getPath(std::string file) {
	return dirPath + "/" + 	file + ".json";
}