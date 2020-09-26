#pragma once
#include <iostream>
#include <math.h>

#include "dnum.h"

class vec4
{
public:
	float x, y, z, w;

	vec4(float x0 = 0, float y0 = 0, float z0 = 0, float w0 = 0) { x = x0; y = y0; z = z0; w = w0; }
	float& operator[](int j) { return *(&x + j); }
	float operator[](int j) const { return *(&x + j); }

	vec4 operator*(float a) const { return vec4(x * a, y * a, z * a, w * a); }
	vec4 operator/(float d) const { return vec4(x / d, y / d, z / d, w / d); }
	vec4 operator+(const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
	vec4 operator-(const vec4& v)  const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
	vec4 operator*(const vec4& v) const { return vec4(x * v.x, y * v.y, z * v.z, w * v.w); }
	void operator+=(const vec4 right) { x += right.x; y += right.y; z += right.z, w += right.z; }

	void print() {
		std::cout << "X: " << x << ", ";
		std::cout << "Y: " << y << ", ";
		std::cout << "Z: " << z << ", ";
		std::cout << "W: " << w << std::endl;
	}
};

Dnum dot(const vec4 p, const vec4 q);
Dnum lenght(const vec4 p);
vec4 normailze(const vec4 p);
vec4 lerp(const vec4 p, const vec4 q, const float t);