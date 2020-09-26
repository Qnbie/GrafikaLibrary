#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class catmul_rom
{
	std::vector<Vec4<Dnum<float>>> controlPoints;
	std::vector<float>	knots;
	Vec4<Dnum<float>> Hermit(
		Vec4<Dnum<float>> p0, Vec4<Dnum<float>> v0, float t0,
		Vec4<Dnum<float>> p1, Vec4<Dnum<float>> v1, float t1, 
		float t);
	Vec4<Dnum<float>> v(
		Vec4<Dnum<float>> r0, float t0,
		Vec4<Dnum<float>> r1, float t1,
		Vec4<Dnum<float>> r2, float t2) {
		return ((r2 - r1)* (1/(t2 - t1)) + (r1 - r0) * (1/(t1 - t0))) * 0.5;
	}
private:
	void AddControlpoint(Vec4<Dnum<float>> point, float knot) {
		controlPoints.push_back(point);
		knots.push_back(knot);
	}
	Vec4<Dnum<float>> r(float t);
};

