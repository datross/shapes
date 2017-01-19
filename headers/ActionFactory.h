#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H
#include "FileManager.h"
#include "Action.h"

#include <map>
#include <string>
#include <memory>

namespace idl {
	class ActionFactory	{
	public:
		std::shared_ptr<Action> create(std::string type);
		static ActionFactory& getInstance();

	private:
		ActionFactory();
		~ActionFactory();
		std::map<std::string, json> actions;
	};
}

#endif // !ACTION_FACTORY_H