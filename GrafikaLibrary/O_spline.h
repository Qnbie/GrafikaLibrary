#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class O_spline
{
	std::vector<vec4> controlPoints;
	std::vector<float>	knots;
	//vec4 s(vec4 r1, vec4 r2, vec4 r3, float t);
public:
	void AddControlpoint(vec4 point, float knot) {
		controlPoints.push_back(point);
		knots.push_back(knot);
	}
	//vec4 r(float t);
};

