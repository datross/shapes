#include "ModifierFactory.h"
#include "SeedFactory.h"
#include "SeedConstant.h"
#include "SelectionFactory.h"
#include "Utility.h"
#include "ModifierRotation.h"
#include <string>

using namespace std;
using namespace idl;

ModifierFactory::ModifierFactory() {
}



ModifierFactory & idl::ModifierFactory::getInstance(){
	static ModifierFactory instance;
	return instance;
}

shared_ptr<Modifier> ModifierFactory::create(json jModifier) {
	string seedType = jModifier["seed"].get<string>();
	shared_ptr<Seed> seed = SeedFactory::getInstance().createSeed(seedType);
	string type = jModifier["type"];
	auto args = split(type, ' ');
	if (args[0] == "selection") {
		if (args[1] == "dependente") {
			if (args[2] == "rotation") {
				shared_ptr<Selection> select =  SelectionFactory::getInstance().create(jModifier["selection"]);
				float angle = jModifier["angle"].get<float>();
				bool indiv = jModifier["individual_origin"].get<bool>();
				ofPoint pivot(0, 0);
				if (jModifier.find("pivot") != jModifier.end()) {
					pivot = parsePoint(jModifier["pivot"].get<string>());
				}
				shared_ptr<Seed> seed = shared_ptr<Seed>(new SeedConstant());
				if (jModifier.find("seed") != jModifier.end()) {
					seed = SeedFactory::getInstance().
						createSeed(jModifier["seed"].get<string>());
				}
				return shared_ptr<Modifier>(new Rotator(*select, angle, indiv, pivot, seed));
			}
		}
	}
}

ModifierFactory::~ModifierFactory(){
}