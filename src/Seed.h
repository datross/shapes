#ifndef SEED_H
#define SEED_H

#include "ofMain.h"

namespace idl {

	class Seed {
	public:
		Seed();
		~Seed();
		virtual ofVec3f get() =0;

	private:

	};

}

#endif // !SEED_H
