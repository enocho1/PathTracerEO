#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"
#include "colour.h"

class camera {
public:
	camera() {
		double aspect_ratio = 16.0 / 9.0;
		double view_height = 2.0;
		double view_width = view_height * aspect_ratio;
		double focal_length = 1.0;

		origin = P3D(0, 0, 0);
		horizontal_vec = V3D(view_width, 0, 0);
		vertical_vec = V3D(0, view_height, 0);
		top_left = origin - (horizontal_vec / 2) + (vertical_vec / 2) - V3D(0, 0, focal_length);
	}

	ray getRay(double u, double v) const {
		return ray(origin, (top_left + u * horizontal_vec - v * vertical_vec - origin));
	}
private:
	P3D origin;
	V3D horizontal_vec;
	V3D vertical_vec;
	P3D top_left;


};

#endif // !CAMERA_H

/*
// camera

	double view_height = 2.0;
	double view_width = view_height * aspect_ratio;
	double focal_length = 1.0;

	P3D origin(0, 0, 0);
	V3D horizontal_vec(view_width, 0, 0);
	V3D vertical_vec(0, view_height, 0);
	P3D top_left = origin - (horizontal_vec / 2) + (vertical_vec / 2) - V3D(0, 0, focal_length);

	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	*/

