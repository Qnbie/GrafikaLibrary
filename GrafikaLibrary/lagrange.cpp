#include "lagrange.h"

float Lagrange::L(int j, float t)
{
    float result = 1;
    for (size_t i = 0; i < knots.size(); i++)
    {
        if (i!=j) result = result * (t - knots[j]) / (knots[i] - knots[j]);
    }
    return result;
}

Vec4<Dnum<float>> Lagrange::r(float t)
{
    Dnum<float> tmp(0);
    Vec4<Dnum<float>> result(tmp, tmp, tmp, tmp);
    for (size_t i = 0; i < controlPoints.size(); i++) {
        result = result + (controlPoints[i] * L(i, t));
    }
    return result;
}
