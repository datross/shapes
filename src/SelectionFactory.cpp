#include "SelectionFactory.h"
#include "Utility.h"

using namespace idl;


SelectionFactory & idl::SelectionFactory::getInstance(){
	static SelectionFactory instance;
	return instance;
}

shared_ptr<Selection> idl::SelectionFactory::create(json& jSelection) {
	try{
		cout << "SELECTION " << jSelection << endl;
		string type = jSelection["type"].get<string>();
		Selection* s = new Selection();
		float weight =jSelection["weight"].get<float>();
		if (type == "uniform") {
			s->uniform(weight);
			return shared_ptr<Selection>(s);
		}	
		if (type == "radial") {
			ofPoint pt = parsePoint(jSelection["point"]);
			float radius = jSelection["radius"].get<float>();
			s->radial(weight, pt, radius);
			return shared_ptr<Selection>(s);
		}
		if (type == "byId") {
			std::string id = jSelection["id"];
			s->byId(id);
			return shared_ptr<Selection>(s);
		}
		if (type == "byColor") {
			ofColor color = parseColor(jSelection["color"]);
			s->byColor(color);
			return shared_ptr<Selection>(s);
		}
		if (type == "random") {
			float threshold = parseColor(jSelection["threshold"]);
			s->random(threshold);
			return shared_ptr<Selection>(s);
		}
	}catch (exception& e) {
		cerr << e.what() << endl;
		return nullptr;
	}
}

SelectionFactory::SelectionFactory(){
}

SelectionFactory::~SelectionFactory(){
}
