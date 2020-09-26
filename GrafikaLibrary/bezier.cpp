#include "bezier.h"

float Bezier::B(int i, float t)
{
    int n = controlPoints.size() - 1;
    float choose = 1;
    for (size_t j = 0; j <= i; j++)
    {
        choose *= (float)(n - j + 1) / i;
    }
    return choose * pow(t, i) * pow(1 - t, n - i);
}

Vec4<Dnum<float>> Bezier::r(float t)
{
    Vec4<Dnum<float>> resoult(0, 0, 0, 0);
    for (size_t i = 0; i < controlPoints.size(); i++)
    {
        resoult = resoult + controlPoints[i] * B(i, t);
    }
    return resoult;
}
