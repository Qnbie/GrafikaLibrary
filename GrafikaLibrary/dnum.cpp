#include "Dnum.h"


Dnum Sin(Dnum g)
{
    return Dnum(sinf(g.f), cosf(g.f)*g.d);
}


Dnum Cos(Dnum g)
{
    return Dnum(cosf(g.f), sinf(g.f) * g.d);
}


Dnum Tan(Dnum g)
{
    return Sin(g)/Cos(g);
}


Dnum Log(Dnum g)
{
    return Dnum(logf(g.f), 1/g.f * g.d);
}


Dnum Exp(Dnum g)
{
    return Dnum(expf(g.f), expf(g.f) * g.d);
}


Dnum Pow(Dnum g, float n)
{
    return Dnum(powf(g.f, n), n*powf(g.f, n-1) * g.d);
}
