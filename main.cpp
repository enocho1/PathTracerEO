#include "pteo.h"

#include "colour.h"
#include "scene.h"
#include "sphere.h"

// // camera class needs sorting out. @enoch
 #include "camera.h"

#include <iostream>



// again, this should go in its own class
double hitSphere(const P3D& center, double radius, const ray& r) {
	// using the following quadratic equation:
	// ( b^2 )t^2 + ( 2b(A-C) )t + ( (A-C)^2-r^2 ) = 0
	// we can calculate the params t, if any, at which the ray intersects the sphere

	//variables
	auto _b = r.direction();
	auto aMinusc = r.origin() - center;

	//quadratic
	double a = dot(_b, _b);
	double b = 2.0 * dot(_b, aMinusc);
	double c = dot(aMinusc, aMinusc) - radius * radius;

	double discrim = b * b - 4.0 * a * c;

	if (discrim < 0) {
		return -1.0;
	}
	else {
		return (-b - sqrt(discrim)) / (2.0 * a);
	}

}

//this really should go inside a separate class

colour rayColour(const ray& r, const primitive& sc) {
	//scene intersection check
	intersection intersection_info;
	if (sc.intersect(r, 0, infinity, intersection_info)) {
		return 0.5 * (intersection_info.normal + colour(1, 1, 1));
	}
	auto t = 0.5 * (1.0 + r.dir.y());
	return (1.0 - t) * colour(1, 1, 1) + t * colour(1.0, 0.7, 0.4);
}


int main() {
	// following ray tracing in a weekend. hoping to make something cool. @enoch
	// also: Pixar, DreamWorks, Disney, anyone else, please hire meeeeeeee!! @enoch.

	// image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int n_samples = 1;

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
				pixel_colour += rayColour(r, everything);
			}
			

			writeColour(std::cout, pixel_colour, n_samples);

		}
		//progress
		std::cerr << "\r PTEO rendering image... " << static_cast<int>(100 * (double)j / (image_height - 1)) << "%" << std::flush;
	}

	std::cerr << "\n done :)\n";

}

