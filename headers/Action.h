#ifndef ACTION_H
#define ACTION_H

#include <time.h>
#include <vector>

#include "modifier.h"

namespace idl {
	
	class Action {

	public:
		Action(unsigned _duration);
		~Action();
		bool execute();
		virtual void apply() = 0;

	protected:
		unsigned duration;
		unsigned birthTime;
		std::vector<Modifier> modifers;
	};

}

#endif