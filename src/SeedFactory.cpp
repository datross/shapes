#include "SeedFactory.h"
#include "seedFunctions.h"

using namespace idl;
using namespace std;



SeedFactory::SeedFactory(){

	//addSeed("sin", )
}	

void SeedFactory::addSeed(string type, function<ofVec3f()> f) {
	seeds[type] = f;
}

SeedFactory::~SeedFactory(){
}

void idl::SeedFactory::createSeed(string type) const
{
}

const SeedFactory& SeedFactory::getInstance() {
	static SeedFactory instance;
	return instance;
}





