#include "vec4.h"


Dnum dot( vec4 p, vec4 q)
{
	return p.x * q.x + p.y * q.y + p.z * q.z + p.w * q.w;
}

Dnum lenght(vec4 p)
{
	return sqrtf(dot(p,p).f);
}

vec4 normailze(vec4 p)
{
	return p * (1 / lenght(p).f);
}

vec4 lerp(vec4 p, vec4 q, float t)
{
	return p * (1 - t) + q * t;
}
