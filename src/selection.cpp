#include "selection.h"

using namespace idl;
using namespace std;

Selection::Selection()
{

}

void Selection::uniform(World& world, float weight)
{
	for(world.selectFirstShape(); world.isCurrentShape(); world.selectNextShape()) {
		weights.push_back(ShapeSelected(&world.currentShape(), weight));
	}
}

void Selection::distance(World & world, float weight, ofPoint point, float radius) {
	for(world.selectFirstShape(); world.isCurrentShape(); world.selectNextShape()) {
		float dist = (point - world.currentShape().position).length();
		float w;
		if(dist > radius) {
			w = 0;
		} else {
			w = (1 - dist / radius) * weight;
		}
		weights.push_back(ShapeSelected(&world.currentShape(), w));
	}
}
