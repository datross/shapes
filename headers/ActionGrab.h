#ifndef ACTION_GRAB_H
#define ACTION_GRAB_H

#include "Action.h"

namespace idl {
	class ActionGrab : public Action{
	public:
		ActionGrab(int d);
		~ActionGrab();
		virtual bool apply();
	private:

	};
}

#endif // !ACTION_GRAB_H
