#pragma once
#include"CMyVektor.h"
#include "CMyMatrix.h"
#include <math.h>

CMyMatrix jacobi(CMyVektor x, CMyVektor (*funktion)(CMyVektor x))
{
    double h = 1e-4;
    double faktor = 1/h;
    double zwischen;
    CMyVektor fx = funktion(x);
    CMyVektor fsx;
    unsigned int n = x.get_dimension();
    unsigned int m = fx.get_dimension();
    CMyMatrix result(m,n);
    for(unsigned int i = 0;i < n;i++)
    {
        zwischen = x[i];
        x[i] = x[i]+h;
        fsx = funktion(x);
        for(unsigned int j = 0;j < m;j++)
        {
            result[j][i] = (fsx[j] - fx[j])*faktor;
        }
        x[i] = zwischen;
    }
    return result;
}

CMyVektor newtonverfahren(CMyVektor x, CMyVektor (*funktion)(CMyVektor x))
{
    CMyVektor fx0;
    if(x.get_dimension() != 2)
        throw "Unpassende Dimensionen für Newtonverfahren";
    for(int i = 0; i < 50 && x.laenge() >= 1e-5;i++)
    {
        fx0 = funktion(x);
        x = x + (-1*(jacobi(x,funktion).invers()*fx0));
    }
    return x;
}

CMyVektor f(CMyVektor x)
{
    if(x.get_dimension()!=4)
        throw "Unpassende Dimension fuer f";
    CMyVektor result(3);
    result[0] = x[0]*x[1]*exp(x[2]);
    result[1] = x[1]*x[2]*x[3];
    result[2] = x[3];
    return result;
}

CMyVektor c(CMyVektor x)
{
    if(x.get_dimension() != 2)
        throw "Unpassende Dimension fuer c";
    CMyVektor result(2);
    result[0] = x[0]*x[0]*x[0]*x[1]*x[1]*x[1]-2*x[1];
    result[1] = x[0]-2;
    return result;
}

double g(CMyVektor x)
{
    return -(2*x[0]*x[0]-2*x[0]*x[1]+x[1]*x[1]+x[2]*x[2]-2*x[0]-4*x[2]);
}