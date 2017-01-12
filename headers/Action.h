#ifndef ACTION_H
#define ACTION_H

#include <time.h>
#include <vector>

#include "modifier.h"

namespace idl {
	
	class Action {

	public:
		Action(int _duration);
		~Action();
		bool execute();
		virtual bool apply() = 0;

	protected:
		int duration;	
		clock_t age;
		std::vector<Modifier> modifers;
	};

}

#endif