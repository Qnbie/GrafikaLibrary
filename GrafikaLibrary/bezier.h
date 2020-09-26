#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class Bezier
{
	std::vector<vec4> controlPoints;
	float B(int j, float t);
public:
	void AddControlpoint(vec4 point) {
		controlPoints.push_back(point);
	}
	vec4 r(float t);
};

