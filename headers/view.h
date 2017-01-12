#ifndef VIEW_H
#define VIEW_H

#include "ofMain.h"
#include "world.h"

namespace idl {

struct View {	
	View();
	void drawShape(Shape&);
	void drawWorld(World&);
};
	
}

#endif