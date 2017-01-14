#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <memory>

#include "modifier.h"

namespace idl {
	
	class Action {

	public:
		Action(unsigned _duration, std::vector< std::shared_ptr<Modifier> > modifers);
		~Action();
		bool execute();
		void apply();

	protected:
		unsigned duration;
		unsigned birthTime;
		std::vector< std::shared_ptr<Modifier> > modifiers;
	};

}

#endif