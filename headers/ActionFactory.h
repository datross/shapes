#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H
#include "FileManager.h"
#include "Action.h"

#include <map>
#include <string>
#include <memory>

namespace idl {
	class ActionFactory	{
	private:
		ActionFactory();
		~ActionFactory();
		/* std::map<std::string, json> actions; */
		std::map<std::string, std::shared_ptr<Action> > actions;
		void preComputeActions(std::map<std::string, json>&);
		std::shared_ptr<Action> createAction(json jAction, string k);
		
	public:
		std::shared_ptr<Action> create(std::string type);
		static ActionFactory& getInstance();
		
		void init();
		void reset();
	};
}

#endif // !ACTION_FACTORY_H
