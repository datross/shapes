#include "ActionFactory.h"
#include "ModifierFactory.h"
#include <limits>

using namespace idl;
using namespace std;

ActionFactory::ActionFactory(){
  std::map<std::string, json> jActions;
  FileManager fileManager = FileManager::getInstance();
  fileManager.initActions(jActions);
  preComputeActions(jActions);
}

ActionFactory::~ActionFactory()
{
}

void ActionFactory::preComputeActions(std::map<std::string, json>& jActions) {
	for(auto a: jActions) {
		actions[a.first] = createAction(a.second, a.first);
	}
}

shared_ptr<Action> ActionFactory::createAction(json jAction, string key) {
	auto jModifiers = jAction["modifiers"];
	std::vector< std::shared_ptr<Modifier> > modifiers;
	for (auto& jModifier : jModifiers) {
	shared_ptr<Modifier> m = ModifierFactory::getInstance().create(jModifier);
	if (!m) continue;
	modifiers.push_back(m);
	}
	//cout << "NB MODIFIER" << modifiers.size() << endl;
	float duration = jAction["duration"].get<float>();
	/* if duration < 0, then it infinite */
	duration = duration < 0 ? numeric_limits<float>::infinity() : duration;
	return shared_ptr<Action>(new Action(duration, modifiers, key));
}	

shared_ptr<Action> ActionFactory::create(string type){
	actions[type]->setBirthTime(ofGetElapsedTimef());
	cout << "Create Action " << actions[type]->getId()<<endl;
	return actions[type];
}

ActionFactory & idl::ActionFactory::getInstance(){
  static ActionFactory instance;
  return instance;
}
