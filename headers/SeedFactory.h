#ifndef SEED_FACTORY_H
#define SEED_FACTORY_H

#include <map>
#include <string>
#include <functional>
#include "Seed.h"


namespace idl {
	class SeedFactory {
	public:

		void createSeed(std::string type) const;
		static const SeedFactory& getInstance();
	private:
		SeedFactory();
		void addSeed(std::string type, function<ofVec3f()>);
		~SeedFactory();


		std::map<std::string, std::function<ofVec3f()> > seeds;
	};
}
#endif // !SEED_FACTORY_H
	