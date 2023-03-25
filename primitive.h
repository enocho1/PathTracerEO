#pragma once
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "ray.h"

//information needed to "understand" an intersection

struct intersection
{
	//where in space did this intersection occur?
	P3D p;
	
	//what is the surface normal to the primitive at this point in space?
	V3D	normal;
	
	//how far along the ray are we? 
	double t;

	//are we on the outside?
	bool exterior;

	//handle interior/exterior stuff
	inline void handleNormal(const ray& r, const V3D& n) {
		exterior = dot(r.dir, n) < 0; //dot the ray with the outward facing normal vector
		if (exterior) {
			normal = n; 
		}
		else {
			normal = -n; // invert the normal if we're on the inside
		}
	}
	

};

// anything that a ray can intersect
class primitive {
public:
	virtual bool intersect(const ray& r, double t_min, double t_max, intersection& inter) const = 0;

};
#endif // !PRIMITIVE_H

