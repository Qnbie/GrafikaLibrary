#include "catmul_rom.h"

Vec4<Dnum<float>> catmul_rom::Hermit(Vec4<Dnum<float>> p0, Vec4<Dnum<float>> v0, float t0, Vec4<Dnum<float>> p1, Vec4<Dnum<float>> v1, float t1, float t)
{
    Vec4<Dnum<float>> a0 = p0;
    Vec4<Dnum<float>> a1 = v0;
    Vec4<Dnum<float>> a2 = (p1 - p0) * 3 * (1 / powf(t1 - t0, 2)) - (v1 + v0 * 2) * (1 / (t1 - t0));
    Vec4<Dnum<float>> a3 = (p0 - p1) * 2 * (1 / powf(t1 - t0, 3)) + (v1 + v0 * 2) * (1 / powf(t1 - t0, 2));
    return a3 * powf(t-t0,3) + a2 * powf(t - t0, 2) + a1 * powf(t - t0, 1) + a0 * powf(t - t0, 0);
}

Vec4<Dnum<float>> catmul_rom::r(float t)
{
    for (size_t i = 0; i < controlPoints.size()-1; i++)
    {
        if (knots[i] <= t && t <= knots[i + 1]) {
            Vec4<Dnum<float>> v0(0,0,0,0), v1(0,0,0,0);
            if (i == 0)
                v0 = v(
                    Vec4<Dnum<float>>(0,0,0,0), 0,
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1]);
            else
                v0 = v(
                    controlPoints[i - 1], knots[i - 1],
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1]);
            if (i == controlPoints.size() - 2)
                v1 = v(
                    controlPoints[i - 1], knots[i - 1],
                    controlPoints[i], knots[i],
                    Vec4<Dnum<float>>(0, 0, 0, 0), 0);
            else
                v1 = v(
                    controlPoints[i - 1], knots[i - 1],
                    controlPoints[i], knots[i],
                    controlPoints[i + 1], knots[i + 1]);
            return Hermit(
                controlPoints[i], v0, knots[i], 
                controlPoints[i+1], v1, knots[i+1], t);
        }
    }
}
