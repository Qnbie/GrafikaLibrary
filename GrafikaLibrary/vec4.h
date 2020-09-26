#pragma once
#include <math.h>

template <class T>
class Vec4
{
public:
	T x, y, z, w;

	Vec4(T x0, T y0, T z0, T w0) {
		this->x = x0;
		this->y = y0;
		this->z = z0;
		this->w = w0;
	}

	//alapműveletek
	Vec4<T> operator+(Vec4<T> data) {
		return Vec4(
			x = x + data.x,
			y = y + data.y,
			z = z + data.z,
			w = w + data.w
		);
	}
	Vec4<T> operator-(const Vec4<T> data) {
		return Vec4(
			x = x - data.x,
			y = y - data.y,
			z = z - data.z,
			w = w - data.w
		);
	}
	Vec4<T> operator*(const Vec4 data) {
		return Vec4(
			x = x * data.x,
			y = y * data.y,
			z = z * data.z,
			w = w * data.w
		);
	}
	Vec4<T> operator*(const T data) {
		return Vec4(
			this->x = this->x * data,
			this->y = this->y * data,
			this->z = this->z * data,
			this->w = this->w * data
		);
	}

	//további műveletek
	T dot(const Vec4 data);
	T lenght();
	Vec4 normailze();
	Vec4 lerp(const Vec4 data, const T t);
};

