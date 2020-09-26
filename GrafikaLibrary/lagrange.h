#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class Lagrange
{
	std::vector<vec4> controlPoints;
	std::vector<float>	knots;
	float L(int j, float t);

public:
	void AddControlpoint(vec4 point, float knot) {
		controlPoints.push_back(point);
		knots.push_back(knot);
	}
	vec4 r(float t);
};
