// GrafikaLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "lagrange.h"
#include "bezier.h"

int main()
{
    Lagrange lagrange;
    lagrange.AddControlpoint(vec4(6, 1, 0, 0),0);
    lagrange.AddControlpoint(vec4(6, 6, 0, 0),1);
    lagrange.AddControlpoint(vec4(4, 8, 0, 0),2);
    float t = 1.5;
    vec4 tmp = lagrange.r(t);
    tmp.print();
    std::cout << "FASZ" << std::endl;
    Bezier bezier;
    bezier.AddControlpoint(vec4(6, 1, 0, 0));
    bezier.AddControlpoint(vec4(6, 6, 0, 0));
    bezier.AddControlpoint(vec4(4, 8, 0, 0));
    t = 0.5;
    vec4 tmp2 = bezier.r(t);
    tmp2.print();
}