#include "SeedFactory.h"
#include "seedFunctions.h"
#include "DeviceListener.h"
#include "Utility.h"
#include "SeedLeap.h"
#include "SoundListener.h"
#include "SeedSoundEnvelope.h"
#include "SeedSoundSpectrum.h"

using namespace idl;
using namespace std;


SeedFactory::SeedFactory(){
	/* Adding every function to the map. */

	addFunction("sinusoide", sinusoide, {0,1,1,0});
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
		// dynamic_pointer_cast<SeedTime>(seed)->start();
		return seed;
	}
	if (arguments[0] == "leap") {
		LeapDevice& leap = LeapDevice::getInstance();
		HandSide hand;
		if (arguments[1] == "right") {
			hand = RIGHT;
		}
		else if (arguments[1] == "left") {
			hand = LEFT;
		}
		return shared_ptr<Seed>(new SeedLeap(hand, arguments[2]));
	}
	if(arguments[0] == "sound") {
		if(arguments[1] == "envelope") {
			return shared_ptr<Seed>(new SeedSoundEnvelope(&SoundListener::getInstance()));
		}
		if(arguments[1] == "spectrum") {
			switch(arguments.size()) {
				case 2: 
					return shared_ptr<Seed>(new SeedSoundSpectrum(&SoundListener::getInstance()
					));
				case 4:
					return shared_ptr<Seed>(new SeedSoundSpectrum(&SoundListener::getInstance(),
						convert<float, string>(arguments[2]), convert<float, string>(arguments[3])
					));
				case 6:
					return shared_ptr<Seed>(new SeedSoundSpectrum(&SoundListener::getInstance(),
						convert<float, string>(arguments[2]), convert<float, string>(arguments[3]),
						convert<float, string>(arguments[4]), convert<float, string>(arguments[5])
					));
				case 8:
					return shared_ptr<Seed>(new SeedSoundSpectrum(&SoundListener::getInstance(),
						convert<float, string>(arguments[2]), convert<float, string>(arguments[3]),
						convert<float, string>(arguments[4]), convert<float, string>(arguments[5]),
						convert<float, string>(arguments[6]), convert<float, string>(arguments[7])
					));
				default: break;
			}
		}
	}

	return nullptr;
}

SeedFactory& SeedFactory::getInstance() {
	static SeedFactory instance;
	return instance;
}
