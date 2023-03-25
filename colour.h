#pragma once

#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"

#include <iostream>

void writeColour(std::ostream& out, colour pixel_col, int n) {

	//chanels
	double r = pixel_col.r();
	double g = pixel_col.g();
	double b = pixel_col.b();

	auto s = 1.0 / n;

	//scale by samples(n)
	r *=s;
	g *= s;
	b *= s;

	// clamp the values and rescale to 256 range
	out << static_cast<int>(255.999 * clamp(r, 0.0, 0.9999)) << " "
		<< static_cast<int>(255.999 * clamp(g, 0.0, 0.9999)) << " "
		<< static_cast<int>(255.999 * clamp(b, 0.0, 0.9999)) << "\n";
}
#endif // !COLOUR_H
