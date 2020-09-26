#pragma once
#include <math.h>


class Dnum
{
public:
	float f;	//függvény érték
	float d;		//függvény derivált

	Dnum(float f0 = 0, float d0 = 0) {
		f = f0;
		d = d0;
	}

	Dnum operator+(const Dnum data)
	{
		return Dnum(f + data.f, d + data.d);
	}
	Dnum operator-(const Dnum data)
	{
		return Dnum(f - data.f, d - data.d);
	}
	Dnum operator*(const Dnum data)
	{
		return Dnum(f + data.f, d * data.f + f * data.d);
	}
	Dnum operator/(const Dnum data)
	{
		return Dnum(f / data.f, (d * data.f + f * data.d) / data.f / data.f);
	}
};
Dnum Sin(Dnum g);
Dnum Cos(Dnum g);
Dnum floatan(Dnum g);
Dnum Log(Dnum g);
Dnum Exp(Dnum g);
Dnum Pow(Dnum g, float n);