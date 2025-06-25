#pragma once
#include <vector>
#include "CMyVektor.h"
class CMyMatrix
{
    private:
    unsigned int m = 2,n = 2;
    std::vector<CMyVektor> vektoren;
    public:
    CMyMatrix(unsigned int m,unsigned int n);
    CMyVektor& operator[](unsigned int index);
    CMyMatrix invers();
    CMyVektor operator*(CMyVektor x);
};