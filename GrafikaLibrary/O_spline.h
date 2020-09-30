#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class O_spline
{
	std::vector<vec4> controlPoints;
	std::vector<float>	knots;
	vec4 krausz_elliminator(
		float x1, float y1,
		float x2, float y2, 
		float x3, float y3, float t);

public:
	void AddControlpoint(vec4 point, float knot) {
		controlPoints.push_back(point);
		knots.push_back(knot);
	}
	vec4 r(float t);
};

