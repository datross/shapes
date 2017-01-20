#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <memory>

#include "Modifier.h"

namespace idl {
	
	class Action {

	public:
		Action(float _duration, std::vector< std::shared_ptr<Modifier> > modifers);
		~Action();
		bool execute();
		void apply();

	protected:
		float duration;
		float birthTime;
		std::vector< std::shared_ptr<Modifier> > modifiers;
	};

}

#endif