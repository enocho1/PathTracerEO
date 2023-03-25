#pragma once
#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "primitive.h"

class sphere : public primitive {
public:
	sphere() : centre(P3D()), radius(0) {}
	sphere(P3D c, double r):centre(c), radius(r) {}
	
	virtual bool intersect(const ray& r, double t_min, double t_max, intersection &inter) const override;
public:
	P3D centre;
	double radius;
};

bool sphere::intersect(const ray& r, double t_min, double t_max, intersection& inter)const {
	// using the following quadratic equation:
	// ( b^2 )t^2 + ( 2b(A-C) )t + ( (A-C)^2-r^2 ) = 0
	// we can calculate the params t, if any, at which the ray intersects the sphere

	//variables
	auto _b = r.direction();
	auto aMinusc = r.origin() - centre;

	//quadratic
	double a = dot(_b, _b);
	double b = 2.0 * dot(_b, aMinusc);
	double c = dot(aMinusc, aMinusc) - radius * radius;

	double discrim = b * b - 4.0 * a * c;

	bool result = true;

	if (discrim < 0) {
		return false;
	}
	else {
		double root = (-b - sqrt(discrim)) / (2.0 * a);
		if (!(root <= t_max && root >= t_min)) {
			//first root was a dud! try the other one.
			root = (-b + sqrt(discrim)) / (2.0 * a);
			if (!(root <= t_max && root >= t_min)) {
				//the other root is bad too, abort mission
				return false;
			}
		}
		//root found, so i'll fill in the intersection struct and return true.
		inter.t = root;
		inter.p = r.at(root);
		V3D norm = normalized(centre - inter.p);
		inter.handleNormal(r, norm);
		return true;
	}

}

#endif // !SPHERE_H

