#include "SeedFactory.h"
#include "seedFunctions.h"
#include "DeviceListener.h"
#include "Utility.h"
#include "SeedLeap.h"

using namespace idl;
using namespace std;


SeedFactory::SeedFactory(){
	/* Adding every function to the map. */

	addFunction("sinusoide", sinusoide, {1,1,0});
	addFunction("linearFade", linearFade, {0,1,1});
	addFunction("wiggle", wiggle, {1,1});
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
	if (arguments[0] == "leap") {
		LeapDevice& leap = LeapDevice::getInstance();
		HandSide hand;
		if (arguments[1] == "right") {
			hand = RIGHT;
		}
		else if (arguments[2] == "left") {
			hand = LEFT;
		}
		if (arguments[1] == "position") 
			return shared_ptr<Seed>(new SeedLeap(hand, POS));
		if (arguments[1] == "positionX")
			return shared_ptr<Seed>(new SeedLeap(hand, POSX));
		if (arguments[1] == "positionY")
			return shared_ptr<Seed>(new SeedLeap(hand, POSY));
		if (arguments[1] == "positionZ")
			return shared_ptr<Seed>(new SeedLeap(hand, POSZ));
		if (arguments[1] == "strength") 
			return shared_ptr<Seed>(new SeedLeap(hand, STRENGTH));
		if (arguments[1] == "grab")
			return shared_ptr<Seed>(new SeedLeap(hand, GRAB));
		if (arguments[1] == "pinch")
			return shared_ptr<Seed>(new SeedLeap(hand, PINCH));
	}

	return nullptr;
}

SeedFactory& SeedFactory::getInstance() {
	static SeedFactory instance;
	return instance;
}
