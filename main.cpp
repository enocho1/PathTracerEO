#include "pteo.h"

#include "colour.h"
#include "scene.h"
#include "sphere.h"

// // camera class needs sorting out. @enoch
#include "camera.h"

#include <iostream>



//this really should go inside a separate class

colour rayColour(const ray& r, const primitive& sc, int depth) {
	if (depth <= 0) return colour(0, 0, 0);
	
	//scene intersection check
	intersection intersection_info;
	if (sc.intersect(r, 0, infinity, intersection_info)) {
		//diffuse reflection
		P3D target = intersection_info.p + intersection_info.normal + randomBounce();
		//return 0.5 * (intersection_info.normal + colour(1, 1, 1));
		return 0.5 * rayColour(ray(intersection_info.p, target - intersection_info.p), sc, depth - 1);
	}
	auto t = 0.5 * (1.0 + r.dir.y());
	return (1.0 - t) * colour(1, 1, 1) + t * colour(0.5, 0.7, 1.0);
}


int main() {
	// following ray tracing in a weekend. hoping to make something cool. @enoch
	// also: Pixar, DreamWorks, Disney, anyone else, please hire meeeeeeee!! @enoch.

	// image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int n_samples = 100;
	const int max_depth = 50;

	//scene setup [wanna put that in a separate class too!]

	scene everything;
	everything.add(make_shared<sphere>(P3D(0, 0, -1), 0.5));
	everything.add(make_shared<sphere>(P3D(0, -100.5, -1), 100));

	// camera

	camera cam;

	// render

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";


	for (int j = 0; j < image_height; j++) {
		for (int i = 0; i < image_width; i++) {

			//sampling for antialiasing
			colour pixel_colour(0, 0, 0);
			for (int s = 0; s < n_samples; s++) {
				double u, v;
				u = (i + rando()) / (image_width - 1);
				v = (j + rando()) / (image_height - 1);
				ray r = cam.getRay(u, v);
				pixel_colour += rayColour(r, everything, max_depth);
			}


			writeColour(std::cout, pixel_colour, n_samples);

		}
		//progress
		std::cerr << "\r PTEO rendering image... " << static_cast<int>(100 * (double)j / (image_height - 1)) << "%" << std::flush;
	}

	std::cerr << "\n done :)\n";

}

