#pragma once
#ifndef PTEO_H
#define PTEO_H

#include <cmath>
#include <limits>
#include <memory>

//using

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265359;

//utility functions

inline double degToRad(double d) {
	return d * pi / 180;
}

inline double radToDeg(double r) {
	return r * 180 / pi;
}

//random real in the range [0,1]
inline double rando() {
	return rand() / (RAND_MAX + 1.0);
}

//random real in a given range range
inline double rando(double start_range, double end_range) {
	return start_range + (end_range - start_range) * rando();
}

//clamp within range
inline double clamp(double x, double start_range, double end_range) {
	return std::max(std::min(x, end_range), start_range);
	
	//// alternative implementation from ray tracing in a weekend
	//// maybe it's faster idk, 
	//if (x < start_range) return start_range;
	//if (x > end_range) return end_range;
	//return x;
}


//common headers

#include "ray.h"
#include "vec3.h"

#endif // !PTEO_H

