#pragma once
#include <math.h>

template <class T>
class Dnum
{
public:
	float f;	//függvény érték
	T d;		//függvény derivált

	Dnum(float f0 = 0, float d0 = 0) {
		f = f0;
		d = d0;
	}

	Dnum operator+(Dnum data) 
	{
		return Dnum<T>(f + data.f, d + data.d);
	}
	Dnum operator-(Dnum data)
	{
		return Dnum<T>(f - data.f, d - data.d);
	}
	Dnum operator*(Dnum data)
	{
		return Dnum<T>(f + data.f, d * data.f + f * data.d);
	}
	Dnum operator/(Dnum data)
	{
		return Dnum<T>(f / data.f, (d * data.f + f * data.d) / data.f / data.f);
	}
};
template<class T>
Dnum<T> Sin(Dnum<T> g);
template<class T>
Dnum<T> Cos(Dnum<T> g);
template<class T>
Dnum<T> Tan(Dnum<T> g);
template<class T>
Dnum<T> Log(Dnum<T> g);
template<class T>
Dnum<T> Exp(Dnum<T> g);
template<class T>
Dnum<T> Pow(Dnum<T> g, float n);