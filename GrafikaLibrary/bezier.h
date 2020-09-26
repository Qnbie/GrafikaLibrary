#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class Bezier
{
	std::vector<Vec4<Dnum<float>>> controlPoints;
	float B(int j, float t);
public:
	void AddControlpoint(Vec4<Dnum<float>> point) {
		controlPoints.push_back(point);
	}
	Vec4<Dnum<float>>	r(float t);
};

