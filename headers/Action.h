#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <memory>

#include "Modifier.h"

namespace idl {
	
	class Action {

	public:
		Action(float _duration, std::vector< std::shared_ptr<Modifier> > modifers, std::string id);
		~Action();
		bool execute();
		void apply();
		void suicide();
    void reset();
		std::string getId() { return id; }

	private:
		std::string id;
		float duration;
		float birthTime;
		std::vector< std::shared_ptr<Modifier> > modifiers;
    bool die;
		void setBirthTime(float time) { birthTime = time; }
	};

}

#endif
