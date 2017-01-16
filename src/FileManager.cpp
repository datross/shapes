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

json FileManager::loadFile(string path) {
	ifstream file(getPath(path));
	json j;
	j << file;
	return j;
}

std::string FileManager::getPath(std::string file) {
	return dirPath + "/" + 	file + ".json";
}