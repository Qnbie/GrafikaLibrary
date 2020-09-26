#include "bezier.h"

float Bezier::B(int i, float t)
{
    int n = controlPoints.size() - 1;
    float choose = 1;
    for (int j = 1; j <= i; j++)
    {
        choose *= (float)(n - j + 1) / j;
    }
    return choose * pow(t, i) * pow(1 - t, n - i);
}

vec4 Bezier::r(float t)
{
    vec4 resoult = vec4(0, 0, 0, 0);
    for (size_t i = 0; i < controlPoints.size(); i++)
    {
        resoult.print();
        resoult = resoult + controlPoints[i] * B(i, t);
    }
    return resoult;
}
