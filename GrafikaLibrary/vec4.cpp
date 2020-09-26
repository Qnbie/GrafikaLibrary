#include "vec4.h"

//skaláris szorzat
template<class T>
T Vec4<T>::dot(const Vec4<T> data) {
	return this->x * data.x + this->y * data.y + this->z * data.z + this->w * data * w;
}

template<class T>
T Vec4<T>::lenght() {
	return sqrtf(this->dot(this));
}

template<class T>
Vec4<T> Vec4<T>::normailze() {
	return this * (1 / this->lenght);
}

template<class T>
Vec4<T> Vec4<T>::lerp(const Vec4<T> data, const T t) {
	return this * (1 - t) + data * t;
}