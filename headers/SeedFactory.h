#ifndef SEED_FACTORY_H
#define SEED_FACTORY_H

#include <map>
#include <string>
#include <functional>
#include "Seed.h"


namespace idl {
	/**
	 * @brief Singleton class, which enables creating predefined seeds (Seed), just using a string.
	 * Keys used to create seeds are the ones used in the map file.
	 * 
	 */
	class SeedFactory {
	public:
		
		/**
		 * @brief Creates a seed and returns it, according to the passed string.
		 * 
		 * @param type e.g "transition easy"
		 * @return Seed& Corresponding created seed.
		 */
		Seed& createSeed(std::string type) const;
		
		/**
		 * @brief Returns the singleton instance of the factory.
		 * 
		 * @return const idl::SeedFactory& A reference to the singleton instance
		 */
		static const SeedFactory& getInstance();
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
		 * @return void
		 */
		void addFunction(std::string type, function<ofVec3f()> f);

		/**
		 * @brief Stores std::functions with their key. The functions are defined in seedFunctions.h .
		 * 
		 */
		std::map<std::string, std::function<ofVec3f()> > functions;
	};
}
#endif // !SEED_FACTORY_H
	