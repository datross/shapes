#include "SeedFactory.h"
#include "seedFunctions.h"
#include "Utility.h"

using namespace idl;
using namespace std;


SeedFactory::SeedFactory(){
	/* Adding every function to the map. */
	
	addFunction("sinusoide", sinusoide, {1,1,0});
}	

void SeedFactory::addFunction(string type, function<ofVec3f(SeedTime&)> f,  std::vector<Setting> defaultsSettings) {
	functions[type] = make_pair(f, defaultsSettings);
}

SeedFactory::~SeedFactory(){
}

/**
 * @brief Allows to convert an array of string to a Settings array.
 * 
 * @param vecStr String array.
 * @return Settings array.
 */
vector<Setting> parseSettings(vector<string> vecStr) {
	vector<Setting> settings;
	for(auto it = vecStr.begin(); it != vecStr.end(); ++it) {
		settings.push_back(convert<Setting, string>(*it));
	}
	return settings;
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
		
		vector<Setting> settings = fct->second.second;
		/* if parameters are detailed in the request */
		if(arguments.size() > 2) {
			settings = parseSettings(vector<string>(arguments.begin()+2, arguments.end()));
		}
		auto seed =  shared_ptr<Seed>(new SeedTimeFunctor(fct->second.first, settings));
		dynamic_pointer_cast<SeedTime>(seed)->start();
		return seed;
	}

	return nullptr;
}

SeedFactory& SeedFactory::getInstance() {
	static SeedFactory instance;
	return instance;
}





