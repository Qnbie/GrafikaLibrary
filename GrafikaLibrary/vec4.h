#pragma once
#include <math.h>

template <class T>
struct vec4
{
	T x, y, z, w;

	vec4(T x0, T y0, T z0, T w0) {
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->w = w0;
	}

	//alapműveletek
	vec4 operator+(const vec4 data);
	vec4 operator-(const vec4 data);
	vec4 operator*(const vec4 data);
	vec4 operator*(const T data);

	//további műveletek
	T dot(const vec4 data);
	T lenght();
	vec4 normailze();
	vec4 lerp(const vec4 data, const T t);
};

