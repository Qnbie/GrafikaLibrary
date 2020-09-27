#include "O_spline.h"
/*
vec4 O_spline::s(vec4 r1, vec4 r2, vec4 r3, float t)
{
	return ai*pow((t-ti),2) + bi*(t-ti) + ci);
}

vec4 O_spline::r(float t)
{
	vec4 resoult = vec4(0,0,0,0);
	vec4 s1, s2;
    for (size_t i = 0; i < controlPoints.size() - 1; i++)
    {
        if (knots[i] <= t && t <= knots[i + 1]) {
            if (i == 0)
                s1 = s(
                    controlPoints[controlPoints.size() - 1],
                    controlPoints[i],
                    controlPoints[i + 1],
                    t);
            else
                s1 = s(
                    controlPoints[i - 1],
                    controlPoints[i],
                    controlPoints[i + 1],
                    t);
            if (i == controlPoints.size()-2)
                s2 = s(
                    controlPoints[i],
                    controlPoints[i + 1],
                    controlPoints[0],
                    t);
            else
                s2 = s(
                    controlPoints[i],
                    controlPoints[i + 1],
                    controlPoints[i + 2],
                    t);
            return (s1*(knots[i+1]-t)+ s2*(t-knots[i]))* (1/(knots[i+1]-knots[i]));
        }
    }
	return vec4();
}
*/