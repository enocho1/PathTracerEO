#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
	ray() {}
	ray(const P3D& origin, const V3D& direction):
		orig(origin), dir(direction) {
		// kinda makes sense to do it here in case i forget somewhere else. @enoch
		dir = normalized(dir);
	}
	
	P3D origin() const { return orig; }
	P3D direction() const { return dir; }

	// trace along the ray with parameter t
	P3D at(double t) const {
		return orig + t * dir;
	}
public:
	P3D orig;
	V3D dir;
	




};
#endif // !RAY_H
