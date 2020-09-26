#include "lagrange.h"

float Lagrange::L(int j, float t)
{
    float result = 1.0f;
    for (size_t i = 0; i < knots.size(); i++)
    {
        if (i != j) result = result * (t - knots[i]) / (knots[j] - knots[i]);
    }
    return result;
}

vec4 Lagrange::r(float t)
{
    vec4 result = vec4(0, 0, 0, 0);
    for (size_t i = 0; i < controlPoints.size(); i++) {
        result.print();
        result = result + (controlPoints[i] * L(i, t));
    }
    return result;
}
