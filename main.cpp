#include "colour.h"
#include "vec3.h"
#include <iostream>

int main() {
	// following ray tracing in a weekend. hoping to make something cool. @enoch
	// also, Pixar, DreamWorks, Disney, anyone else, please hire meeeeeeee!! @enoch.

	// image 
	const int image_width = 256;
	const int image_height = 256;

	// render

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";


	for (int j = 0; j < image_width; j++) {
		for (int i = 0; i < image_height; i++) {
			
			std::cerr << "\r writing line: " << j << "/256..." << std::flush;
			
			colour pixel_colour(double(i) / (image_width - 1),double(255 - j) / (image_height - 1),0.3);

			writeColour(std::cout, pixel_colour);

		}
	}

	std::cerr << "\n done :)\n";

}

