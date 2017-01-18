#include "ActionFactory.h"
#include "ModifierFactory.h"


using namespace idl;


ActionFactory::ActionFactory(){
	FileManager fileManager = FileManager::getInstance();
	fileManager.initActions(actions);
}

ActionFactory::~ActionFactory()
{
}

shared_ptr<Action> ActionFactory::create(string type){
	try {
		std::map<string, json>::iterator j = actions.find(type);
		if (j == actions.end()) {
			cerr << "Cannot create action " << type << " is undefined" << endl;
			return nullptr;
		}
		json jAction = j->second;
		auto jModifiers = jAction["modifiers"];
		std::vector< std::shared_ptr<Modifier> > modifiers;
		for (auto& jModifier : jModifiers) {
			shared_ptr<Modifier> m = ModifierFactory::getInstance().create(jModifier);
			if (!m) continue;
			modifiers.push_back(m);
		}
		unsigned duration = jAction["duration"].get<unsigned>();
		return shared_ptr<Action>(new Action(duration, modifiers));
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		return nullptr;
	}
}

ActionFactory & idl::ActionFactory::getInstance(){
	static ActionFactory instance;
	return instance;
}
