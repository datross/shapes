#include "selection.h"

using namespace idl;
using namespace std;

Selection::Selection()
{

}

void Selection::uniform(World& world, float weight)
{
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		weights.push_back(ShapeSelected(&world.currentShape(), weight));
	}
}

void Selection::distance(World & world, float weight, ofPoint point, float radius) {
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		float dist = (point - world.currentShape().getPosition()).length();
		float w;
		if(dist > radius) {
			w = 0;
		} else {
			w = (1 - dist / radius) * weight;
		}
		weights.push_back(ShapeSelected(&world.currentShape(), w));
	}
}
