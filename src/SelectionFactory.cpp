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
		cout << "type:" << type << endl;
		Selection* s = new Selection();
		if (type == "uniform") {
			float weight = jSelection["weight"].get<float>();
			s->uniform(weight);
			return shared_ptr<Selection>(s);
		}	
		if (type == "radial") {
			float weight = jSelection["weight"].get<float>();
			cout << "here" << endl;
			ofPoint pt = parsePoint(jSelection["point"]);
			cout << "Point:" << pt << endl;
			float radius = jSelection["radius"].get<float>();
			cout << "RAdius:" << radius << endl;
			s->radial(weight, pt, radius);
			return shared_ptr<Selection>(s);
		}
		if (type == "byId") {
			std::string id = jSelection["id"].get<string>();
			s->byId(id);
			return shared_ptr<Selection>(s);
		}
		if (type == "byColor") {
			std::string color = jSelection["color"].get<string>();
			s->byColor(color);
			return shared_ptr<Selection>(s);
		}
		if (type == "random") {
			float threshold = jSelection["threshold"].get<float>();
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
