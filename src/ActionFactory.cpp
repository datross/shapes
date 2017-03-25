#include "ActionFactory.h"
#include "ModifierFactory.h"
#include <limits>

using namespace idl;
using namespace std;

ActionFactory::ActionFactory(){
  std::map<std::string, json> jActions;
  FileManager fileManager = FileManager::getInstance();
  fileManager.initActions(jActions);
}

ActionFactory::~ActionFactory()
{
}

void ActionFactory::preComputeActions(std::map<std::string, json>& jActions) {
  for(auto a: jActions) {
    actions[a.first] = createAction(a.second);
  }
}

shared_ptr<Action> ActionFactory::createAction(json jAction) {
  auto jModifiers = jAction["modifiers"];
  std::vector< std::shared_ptr<Modifier> > modifiers;
  for (auto& jModifier : jModifiers) {
    shared_ptr<Modifier> m = ModifierFactory::getInstance().create(jModifier);
    if (!m) continue;
    modifiers.push_back(m);
  }
  cout << "NB MODIFIER" << modifiers.size() << endl;
  float duration = jAction["duration"].get<float>();
  /* if duration < 0, then it infinite */
  duration = duration < 0 ? numeric_limits<float>::infinity() : duration;
  return shared_ptr<Action>(new Action(duration, modifiers));
}

shared_ptr<Action> ActionFactory::create(string type){
  return actions[type];
}

ActionFactory & idl::ActionFactory::getInstance(){
  static ActionFactory instance;
  return instance;
}
