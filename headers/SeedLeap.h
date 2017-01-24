#ifndef SEED_LEAP_H
#define SEED_LEAP_H

#include "Seed.h"
#include "DeviceListener.h"

namespace idl{	

	class SeedLeap : public Seed {
	private:
		HandSide hand;
		LeapInfoFlag flag;
	public:
		SeedLeap(HandSide h, LeapInfoFlag flag);
		~SeedLeap();
		virtual ofVec3f getValue();
		
	};
}
#endif // !SEED_HAND_POSIION_H
