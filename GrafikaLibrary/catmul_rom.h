#pragma once
#include "vec4.h"
#include "dnum.h"
#include <vector>

class Catmul_rom
{
	std::vector<vec4> controlPoints;
	std::vector<float>	knots;
	vec4 Hermit(
		vec4 p0, vec4 v0, float t0,
		vec4 p1, vec4 v1, float t1, 
		float t);
	vec4 v(
		vec4 r0, float t0,
		vec4 r1, float t1,
		vec4 r2, float t2) {
		return ((r2 - r1)* (1/(t2 - t1)) + (r1 - r0) * (1/(t1 - t0))) * 0.5;
	}
public:
	void AddControlpoint(vec4 point, float knot) {
		controlPoints.push_back(point);
		knots.push_back(knot);
	}
	vec4 r(float t);
};

