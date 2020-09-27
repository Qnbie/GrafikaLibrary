#include "Catmul_rom.h"

vec4 Catmul_rom::Hermit(vec4 p0, vec4 v0, float t0, vec4 p1, vec4 v1, float t1, float t)
{
    vec4 a0 = p0;
    vec4 a1 = v0;
    vec4 a2 = (p1 - p0) * 3 * (1 / powf(t1 - t0, 2)) - (v1 + v0 * 2) * (1 / (t1 - t0));
    vec4 a3 = (p0 - p1) * 2 * (1 / powf(t1 - t0, 3)) + (v1 + v0) * (1 / powf(t1 - t0, 2));
    return a3 * powf(t-t0,3) + a2 * powf(t - t0, 2) + a1 * powf(t - t0, 1) + a0 * powf(t - t0, 0);
}

vec4 Catmul_rom::r(float t)
{
    for (size_t i = 0; i < controlPoints.size()-1; i++)
    {
        if (knots[i] <= t && t <= knots[i + 1]) {
            vec4 v0(0,0,0,0), v1(0,0,0,0);
            if (i == 0)
                v0 = v(
                    //controlPoints[controlPoints.size()-1], knots[knots.size()-1],
                    vec4(0,0,0,0),0,
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1]);
            else
                v0 = v(
                    controlPoints[i - 1], knots[i - 1],
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1]);
            if (i == controlPoints.size() - 2)
                v1 = v(
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1],
                    controlPoints[0], knots[0]);
            else
                v1 = v(
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1],
                    controlPoints[i + 2], knots[i + 2]);
            return Hermit(
                controlPoints[i], v0, knots[i], 
                controlPoints[i+1], v1, knots[i+1], t);
        }
    }
}
