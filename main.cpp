#include "colour.h"
#include "vec3.h"
#include "ray.h"
// // camera class needs sorting out. @enoch
// #include "camera.h"

#include <iostream>

//this really should go inside a separate class

colour rayColour(const ray& r) {
	double t = 0.5 * (1.0 + r.dir.y());
	return (1.0 - t) * colour(1, 1, 1) + t * colour(0.5, 1.0, 1.0);
	//return (1.0 - t) * colour(1, 1, 1) + t * colour(0.0, 0.0, 0.0);
}

int main() {
	// following ray tracing in a weekend. hoping to make something cool. @enoch
	// also, Pixar, DreamWorks, Disney, anyone else, please hire meeeeeeee!! @enoch.

	// image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	// camera

	double view_height = 2.0;
	double view_width = view_height * aspect_ratio;
	double focal_length = 1.0;

	P3D origin(0, 0, 0);
	V3D horizontal_vec(view_width, 0, 0);
	V3D vertical_vec(0, view_height, 0);
	P3D top_left = origin - (horizontal_vec / 2) + (vertical_vec / 2) - V3D(0, 0, focal_length);

	// render

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";


	for (int j = 0; j < image_height; j++) {

		std::cerr << "\r writing line: " << j << "/256..." << std::flush;

		for (int i = 0; i < image_width; i++) {

			P3D u, v;

			u = (double(i) / (image_width - 1))*horizontal_vec;
			v = (double(j) / (image_height- 1))*vertical_vec;

			ray r(origin, (top_left + u - v - origin));
			colour pixel_colour = rayColour(r);

			// colour pixel_colour(double(i) / (image_width - 1), double(255 - j) / (image_height - 1), 0.3);

			writeColour(std::cout, pixel_colour);

		}
	}

	std::cerr << "\n done :)\n";

}

