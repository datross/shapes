#ifndef SEED_LEAP_H
#define SEED_LEAP_H

#include "Seed.h"
#include "DeviceListener.h"

namespace idl{

	class SeedLeap : public Seed {
	private:
		HandSide hand;
		SeedLeapInfoFlag flag;
	public:
		SeedLeap(HandSide h, std::string flag);
		~SeedLeap();
		virtual ofVec3f getValue();
		
	};
}
#endif // !SEED_HAND_POSIION_H
