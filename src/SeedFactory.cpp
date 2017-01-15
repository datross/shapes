#include "SeedFactory.h"
#include "seedFunctions.h"

using namespace idl;
using namespace std;



SeedFactory::SeedFactory(){

	//addSeed("sin", )
}	

void SeedFactory::addFunction(string type, function<ofVec3f()> f) {
	functions[type] = f;
}

SeedFactory::~SeedFactory(){
}

Seed& SeedFactory::createSeed(string type) const
{
}

const SeedFactory& SeedFactory::getInstance() {
	static SeedFactory instance;
	return instance;
}





