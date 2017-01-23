#ifndef SETTING_LIST_H
#define SETTING_LIST_H

#include "ofMain.h"
#include <string>
#include <iostream>
#include <vector>

namespace idl {

class SettingList {
private:
	ofParameterGroup list;
public:
	SettingList();
	SettingList(ofParameterGroup& group);
	
	template<class T>
	void set(std::string name, T & value) {
		list[name] = ofParameter<T>(value);
	}
	
	template<class T>
	T get(std::string name) {
		return list.get(name).cast<T>();
	}
	
	ofParameterGroup& data();
	
	void overridingFusion(SettingList& list);
};
	
}

#endif