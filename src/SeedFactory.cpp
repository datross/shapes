#include "SeedFactory.h"
#include "seedFunctions.h"
#include "Utility.h"

using namespace idl;
using namespace std;



SeedFactory::SeedFactory(){
	/* Adding every function to the map. */
	
	addFunction("time sinusoide", sinusoide, {1,1,0});
}	

void SeedFactory::addFunction(string type, function<ofVec3f(Seed&)> f,  std::vector<Setting> defaultsSettings) {
	functions[type] = make_pair(f, defaultsSettings);
}

SeedFactory::~SeedFactory(){
}

shared_ptr<Seed> SeedFactory::createSeed(string type) {
	auto arguments = split(type, ' ');
	
	/* If first argument is 'time', then it's a SeedTime. */
	if(arguments[0] == "time") {
		auto fct = functions.find(arguments[1]);
		/* if name of the function not found */
		if(fct == functions.end()) {
			cerr << "Seed's function's name unknown : " << arguments[0] << endl;
			return nullptr;
		}
		
		return shared_ptr<Seed>(new SeedTimeFunctor(fct->second.first, fct->second.second));
	}
	
	return nullptr;
}

SeedFactory& SeedFactory::getInstance() {
	static SeedFactory instance;
	return instance;
}





