#ifndef SEED_H
#define SEED_H

#include "ofMain.h"

namespace idl {

class Seed {
public:
	Seed();
	~Seed();
	ofVec3f current() const;
	ofVec3f prec() const;
	ofVec3f step() const;
	
	void update();
private:
	virtual ofVec3f getValue() = 0;
	ofVec3f valuePrec, valueCurrent;
};

}

#endif // SEED_H
