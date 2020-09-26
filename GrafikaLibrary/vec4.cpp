#include "vec4.h"


template<class T>
vec4<T> vec4<T>::operator+(const vec4 data) {
	this->x += data.x;
	this->y += data.y;
	this->z += data.z;
	this->w += data.w;
}

template<class T>
vec4<T> vec4<T>::operator-(const vec4 data) {
	this->x -= data.x;
	this->y -= data.y;
	this->z -= data.z;
	this->w -= data.w;
}

//Vektoriális szorzat
template<class T>
vec4<T> vec4<T>::operator*(const vec4 data) {
	this->x = this->x * data.x;
	this->y = this->y * data.y;
	this->z = this->z * data.z;
	this->w = this->w * data.w;
}

template<class T>
vec4<T> vec4<T>::operator*(const T data) {
	this->x = this->x * data;
	this->y = this->y * data;
	this->z = this->z * data;
	this->w = this->w * data;
}

//skaláris szorzat
template<class T>
T vec4<T>::dot(const vec4 data) {
	return this->x * data.x + this->y * data.y + this->z * data.z + this->w * data * w;
}

template<class T>
T vec4<T>::lenght() {
	return sqrtf(this->dot(this));
}

template<class T>
vec4<T> vec4<T>::normailze() {
	return this * (1 / this->lenght);
}

template<class T>
vec4<T> vec4<T>::lerp(const vec4 data, const T t) {
	return this * (1 - t) + data * t;
}