#include "O_spline.h"

vec4 O_spline::r(float t)
{
	vec4 resoult = vec4(0,0,0,0);
	vec4 s1, s2;
    for (size_t i = 0; i < controlPoints.size() - 1; i++)
    {
        if (knots[i] <= t && t <= knots[i + 1]) {
            if (i == 0)
                s1 = krausz_elliminator(
                    controlPoints[controlPoints.size() - 1].x, controlPoints[controlPoints.size() - 1].y,
                    controlPoints[i].x, controlPoints[i].y,
                    controlPoints[i + 1].x, controlPoints[i + 1].y,
                    t);
            else
                s1 = krausz_elliminator(
                    controlPoints[i - 1].x, controlPoints[i - 1].y,
                    controlPoints[i].x, controlPoints[i].y,
                    controlPoints[i + 1].x, controlPoints[i + 1].y,
                    t);
            if (i == controlPoints.size()-2)
                s2 = krausz_elliminator(
                    controlPoints[i].x, controlPoints[i].y,
                    controlPoints[i + 1].x, controlPoints[i + 1].y,
                    controlPoints[0].x, controlPoints[0].y,
                    t);
            else
                s2 = krausz_elliminator(
                    controlPoints[i].x, controlPoints[i].y,
                    controlPoints[i + 1].x, controlPoints[i + 1].y,
                    controlPoints[i + 2].x, controlPoints[i + 2].y,
                    t);
            return (s1*(knots[i+1]-t)+ s2*(t-knots[i]))* (1/(knots[i+1]-knots[i]));
        }
    }
	return vec4();
}


vec4 O_spline::krausz_elliminator(float x1, float y1, float x2, float y2, float x3, float y3, float t)
{
    float tmp[3][3];
    tmp[0][0] = x1 * x1;
    tmp[0][1] = x1;
    tmp[0][2] = 1;
    tmp[1][0] = x2 * x2;
    tmp[1][1] = x2;
    tmp[1][2] = 1;
    tmp[2][0] = x3 * x3;
    tmp[2][1] = x3;
    tmp[2][2] = 1;
    float jobb[3];
    jobb[0] = y1;
    jobb[1] = y2;
    jobb[2] = y3;

    for (int i = 0; i < 3; i++) {
        for (int n = i; n < 3; n++) {
            tmp[i][n] = tmp[i][n] / tmp[i][i];
        }
        if (i != 2) {
            for (int m = i+1; m < 3; m++) {
                while (tmp[m][0]!=0)
                {
                    tmp[m][0] -= tmp[i][0];
                    tmp[m][1] -= tmp[i][1];
                    tmp[m][2] -= tmp[i][2];
                    jobb[m] -= jobb[i];
                }
            }
        }
    }

    return vec4(t,powf(t,2)*jobb[0]+jobb[1]*t+jobb[2],0,0);
}


