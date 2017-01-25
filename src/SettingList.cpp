#include "SettingList.h"

using namespace idl;
using namespace std;

SettingList::SettingList() {
}

SettingList::SettingList(ofParameterGroup& group)
	: list(group) {
}

ofParameterGroup& SettingList::data() {
	return list;
}


void SettingList::overridingFusion(SettingList& _list) {
	for (auto p : _list.data()) {
		list.add(*p);
	}
}
