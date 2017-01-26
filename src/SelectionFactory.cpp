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
		cout << "SELECTION " << jSelection << endl;
		string type = jSelection["type"].get<string>();
		auto args = split(type, ' ');
		cout << "type:" << type << endl;
		Selection* s = new Selection();
		if (args[0] == "uniform") {
			float weight = jSelection["weight"].get<float>();
			s->uniform(weight);
			return shared_ptr<Selection>(s);
		}	
		if (args[0] == "radial") {
			float weight = jSelection["weight"].get<float>();
			cout << "here" << endl;
			ofPoint pt = parsePoint(jSelection["point"]);
			cout << "Point:" << pt << endl;
			float radius = jSelection["radius"].get<float>();
			cout << "RAdius:" << radius << endl;
			s->radial(weight, pt, radius);
			return shared_ptr<Selection>(s);
		}
		if (args[0] == "byId") {
			std::string id = jSelection["id"].get<string>();
			s->byId(id);
			return shared_ptr<Selection>(s);
		}
		if (args[0] == "byColor") {
			std::string color = jSelection["color"].get<string>();
			s->byColor(color);
			return shared_ptr<Selection>(s);
		}
		if (args[0] == "random") {
			float threshold = jSelection["threshold"].get<float>();
			s->random(threshold);
			return shared_ptr<Selection>(s);
		}

		if (args[0] == "composite"){
			if (args[1] == "intersection"){
				json& selections = jSelection["selections"];
				vector<shared_ptr<Selection>> selection_vector;
				for(auto it = selections.begin(); it != selections.end(); ++it){
					shared_ptr<Selection> s2 = create(*it);
					selection_vector.push_back(s2);
				}
				s->intersection(selection_vector);
				return shared_ptr<Selection>(s);
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
