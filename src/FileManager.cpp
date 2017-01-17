#include "FileManager.h"
#include "Utility.h"
#include <fstream>
#include <iostream>

using namespace idl;
using namespace std;

FileManager::FileManager(string path)
	: sessionDirectory(path) {
	if(!sessionDirectory.exists()) {
		cerr << "Error this directory doesn't exist : " << sessionDirectory.getAbsolutePath() << endl;
	}
}


FileManager & FileManager::getInstance(string path) {
	static FileManager instance(path);
	return instance;
}

void FileManager::init(string path) {
	getInstance(path);
}

json FileManager::loadJSONFile(string path, bool addPath) {
	if (addPath)
		path = sessionDirectory.getAbsolutePath() + "/" + path + ".json";
	cout << "Loading file : " << path << endl;
	ifstream file(path);
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
	path =  sessionDirectory.getAbsolutePath() + "/" + path + ".svg";
	cout << "Loading file : " << path << endl;
	svg.load(path);
	return svg;
}

void FileManager::initActions(std::map<std::string, json>& actions){
	ofDirectory dir(sessionDirectory.getAbsolutePath() + "/actions");
	auto files = dir.getFiles();
	for (auto& f : files) {
		auto fileName = split(f.getFileName(), '.')[0];
		actions[fileName] = loadJSONFile(f.path(), false);
	}
}

