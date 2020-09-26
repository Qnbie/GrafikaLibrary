#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class Lagrange
{
	std::vector<Vec4<Dnum<float>>> controlPoints;
	std::vector<float>	knots;
	float L(int j, float t);

public:
	void AddControlpoint(Vec4<Dnum<float>> point, float knot) {
		controlPoints.push_back(point);
		knots.push_back(knot);
	}
	Vec4<Dnum<float>>	r(float t);
};

