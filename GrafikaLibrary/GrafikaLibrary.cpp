// GrafikaLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "lagrange.h"
#include "bezier.h"
#include "catmul_rom.h"

int main()
{
    std::cout << "Lagrange" << std::endl;
    Lagrange lagrange;
    lagrange.AddControlpoint(vec4(3, 4, 0, 0),0);
    lagrange.AddControlpoint(vec4(4, 8, 0, 0),1);
    lagrange.AddControlpoint(vec4(5, 4, 0, 0),2);
    float t = 1.5;
    vec4 tmp = lagrange.r(t);
    tmp.print();
    std::cout << "Bezier" << std::endl;
    Bezier bezier;
    bezier.AddControlpoint(vec4(6, 8, 0, 0));
    bezier.AddControlpoint(vec4(7, 9, 0, 0));
    bezier.AddControlpoint(vec4(3, 3, 0, 0));
    t = 1;
    vec4 tmp2 = bezier.r(t);
    tmp2.print();
    std::cout << "Catmul-Rom" << std::endl;
    Catmul_rom catmul_rom;
    catmul_rom.AddControlpoint(vec4(3, 3, 0, 0),1);
    catmul_rom.AddControlpoint(vec4(5, 1, 0, 0),2);
    catmul_rom.AddControlpoint(vec4(3, 9, 0, 0),3);
    catmul_rom.AddControlpoint(vec4(5, 6, 0, 0),4);
    t = 2.5;
    vec4 tmp3 = catmul_rom.r(t);
    tmp3.print();
}