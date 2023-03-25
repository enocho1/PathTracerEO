#pragma once
#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
	// methods
public:

	// constructor
	vec3() : e{ 0,0,0 } {}
	vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

	// accessing by DOF/Dimension
	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	// accessing by colour chanel
	double r() const { return e[0]; }
	double g() const { return e[1]; }
	double b() const { return e[2]; }

	// accessing by index
	double& operator[](int i) { return e[i]; }
	double operator[](int i) const { return e[i]; }

	// negation
	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

	// math
	vec3& operator +=(const vec3& v) {
		e[0] += v[0];
		e[1] += v[1];
		e[2] += v[2];

		return *this;

	}

	vec3& operator *=(const double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;

		return *this;
	}

	vec3& operator /=(const double t) {

		return *this *= 1 / t;
	}

	// returns the length of the vector squared;
	double norm2() {
		return  e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	// returns the length of the vector;
	double norm() {
		return sqrt(norm2());
	}

	// returns the length of the vector;
	double length() {
		return norm();
	}

	// returns the length of the vector squared;
	double length_squared() {
		return norm2();
	}

	// normalises the vector to length 1
	void normalize() {
		double n = norm();
		*this /= n;
	}


	// member variables
private:
	double e[3];

	//static stuff
public:
	inline static vec3 random() {
		return vec3(rando(), rando(), rando());
	}

	inline static vec3 random(double start_range, double end_range) {
		return vec3(rando(start_range, end_range), rando(start_range, end_range), rando(start_range, end_range));
	}
};



// some helper functions

inline std::ostream& operator <<(std::ostream& out, const vec3& v) {
	return out << v[0] << " " << v[1] << v[2];
}

inline  vec3 operator +(const vec3& u, const vec3& v) {
	return vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline  vec3 operator -(const vec3& u, const vec3& v) {
	return vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline  vec3 operator *(const vec3& u, const vec3& v) {
	return vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

inline  vec3 operator *(double t, const vec3& v) {
	return vec3(t * v[0], t * v[1], t * v[2]);
}

inline  vec3 operator *(const vec3& u, double t) {
	return t * u;
}

inline  vec3 operator /(const vec3& u, double t) {
	return (1.0 / t) * u;
}

// dot product of two vectors u and v.
inline double dot(const vec3& u, const vec3& v) {
	return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

// cross product of two vectors u and v
inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u[1] * v[2] - u[2] * v[1],
		u[2] * v[0] - u[0] * v[2],
		u[0] * v[1] - u[1] * v[0]);
}

// returns a normalised copy of the vector (length 1)
inline vec3 normalized(vec3 v) {
	return v / v.norm();
}

inline vec3 randomBounce() {
	for (int i = 0; i < 20; i++) {
		auto p = vec3::random(-1, 1);
		if (p.length_squared() < 1) {
			return p;
		}
	}
	//give up if it's taking too long
	return vec3::random(0.577, 0.577);

}

//some aliases for vec3 [for code readability] i think. @enoch

using point3 = vec3;
using P3D = vec3;
using V3D = vec3;
using colour = vec3;
using color = vec3;

#endif // !VEC3_H

