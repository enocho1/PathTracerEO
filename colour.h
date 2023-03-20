#pragma once

#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"

#include <iostream>

void writeColour(std::ostream& out, colour pixelCol) {
	out << static_cast<int>(255.999 * pixelCol.r()) << " "
		<< static_cast<int>(255.999 * pixelCol.g()) << " "
		<< static_cast<int>(255.999 * pixelCol.b()) << "\n";
}
#endif // !COLOUR_H
