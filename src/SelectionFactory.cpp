#include "SelectionFactory.h"
#include "Utility.h"

using namespace idl;
using namespace std;


SelectionFactory & idl::SelectionFactory::getInstance(){
	static SelectionFactory instance;
	return instance;
}

shared_ptr<Selection> idl::SelectionFactory::create(json& jSelection) {
	try{
		string type = jSelection["type"].get<string>();
		auto args = split(type, ' ');
		if (args[0] == "uniform") {
			float weight = jSelection["weight"].get<float>();
			return shared_ptr<Selection>(new SelectionUniform(weight));
		}
		if (args[0] == "radial") {
			float weight = jSelection["weight"].get<float>();
			ofPoint pt = parsePoint(jSelection["point"]);
			float radius = jSelection["radius"].get<float>();
			return shared_ptr<Selection>(new SelectionRadial(weight, pt, radius));
		}
		if (args[0] == "byId") {
			std::string id = jSelection["id"].get<string>();
			return shared_ptr<Selection>(new SelectionById(id));
		}
		if (args[0] == "byColor") {
			std::string color = jSelection["color"].get<string>();
			return shared_ptr<Selection>(new SelectionByColor(color));
		}
		if (args[0] == "random") {
			float threshold = jSelection["threshold"].get<float>();
			return shared_ptr<Selection>(new SelectionRandom(threshold));
		}

		if (args[0] == "composite"){
			if (args[1] == "intersection"){
				json& selections = jSelection["selections"];
				vector<shared_ptr<Selection>> selection_vector;
				for (auto it = selections.begin(); it != selections.end(); ++it) {
					shared_ptr<Selection> s2 = create(*it);
					selection_vector.push_back(s2);
				}
				return shared_ptr<Selection>(new SelectionIntersection(selection_vector));
			}
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
