#ifndef SEED_FACTORY_H
#define SEED_FACTORY_H

#include <utility>
#include <map>
#include <string>
#include <functional>
#include <memory>
#include <iostream>
#include "Seed.h"
#include "SeedTime.h"
#include "SeedTimeFunctor.h"


namespace idl {
	/**
	 * @brief Singleton class, which enables creating predefined seeds (Seed), just using a string.
	 * Keys used to create seeds are the ones used in the map file.
	 * 
	 */
	class SeedFactory {
	public:
		
		/**
		 * @brief Creates new seed and returns a pointer to it, according to the passed string.
		 * 
		 * @param type e.g "transition easy"
		 * @return std::shared_ptr<Seed> Corresponding created seed.
		 */
		std::shared_ptr<Seed> createSeed(std::string type);
		
		/**
		 * @brief Returns the singleton instance of the factory.
		 * 
		 * @return const idl::SeedFactory& A reference to the singleton instance
		 */
		static SeedFactory& getInstance();
	private:
		SeedFactory();
		~SeedFactory();
		
		/**
		 * @brief Adds a function to the map.
		 * 
		 * Not duplicate will be added.
		 * 
		 * @param type Function's key.
		 * @param f Function
		 * @param defaultsSettings Default settings for the future seed.
		 * @return void
		 */
		void addFunction(std::string type, function<ofVec3f(Seed&)> f, std::vector<Setting> defaultsSettings= {});

		/**
		 * @brief Stores std::functions with their key. The functions are defined in seedFunctions.h .
		 * 
		 */
		std::map<std::string, std::pair<std::function<ofVec3f(Seed&)>, std::vector<Setting> > > functions;
	};
}
#endif // !SEED_FACTORY_H
	