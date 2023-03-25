#pragma once
#ifndef SCENE_H
#define SCENE_H
#include "primitive.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class scene : public primitive{
public:
	scene() {}
	scene(shared_ptr<primitive> thing) { add(thing); }

	//remove all collections, items and primitives from scene
	void clear() { items.clear(); }

	//add collection, item or primitive to the scene
	void add(shared_ptr<primitive> thing) { items.push_back(thing);}

	// trace a ray and see if it hits anything
	virtual bool intersect(const ray& r, double t_min, double t_max, intersection& inter) const override;



public:
	std::vector<shared_ptr<primitive>> items;

};

bool scene::intersect(const ray& r, double t_min, double t_max, intersection& inter) const {
	
	intersection placeholder_intersection;
	bool intersected = false;
	double t_closest = t_max;

	for (const auto& thing : items) {
		if (thing->intersect(r, t_min, t_closest, placeholder_intersection) ){
			intersected = true;
			t_closest = placeholder_intersection.t;
			inter = placeholder_intersection;
		}
	}

	return intersected;
}

#endif // !SCENE_H
