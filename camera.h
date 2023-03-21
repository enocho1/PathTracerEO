#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"
#include "colour.h"

class camera {
public:
	P3D orig;
	V3D up_vector;
	double view_height; //viewport height
	double view_width; //viewport width
	double focal_length;
	double aspect_ratio;

	// i'll finish this up later. @enoch


};

#endif // !CAMERA_H

