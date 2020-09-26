#include "Dnum.h"

template<class T>
Dnum<T> Sin(Dnum<T> g)
{
    return Dnum<T>(sinf(g.f), cosf(g.f)*g.d);
}

template<class T>
Dnum<T> Cos(Dnum<T> g)
{
    return Dnum<T>(cosf(g.f), sinf(g.f) * g.d);
}

template<class T>
Dnum<T> Tan(Dnum<T> g)
{
    return Sin(g)/Cos(g);
}

template<class T>
Dnum<T> Log(Dnum<T> g)
{
    return Dnum<T>(logf(g.f), 1/g.f * g.d);
}

template<class T>
Dnum<T> Exp(Dnum<T> g)
{
    return Dnum<T>(expf(g.f), expf(g.f) * g.d);
}

template<class T>
Dnum<T> Pow(Dnum<T> g, float n)
{
    return Dnum<T>(powf(g.f, n), n*powf(g.f, n-1) * g.d);
}
