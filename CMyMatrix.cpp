    #include "CMyMatrix.h"
    #include <iostream>
    #include "CMyVektor.h"

    CMyMatrix::CMyMatrix(unsigned int m,unsigned int n)
    {
            vektoren.resize(m);
            for(unsigned int i = 0;i<m;i++)
            {
                vektoren[i] = CMyVektor(n);
            }
    }

    CMyVektor& CMyMatrix::operator[](unsigned int index)
    {
        return vektoren[index];
    }

    CMyMatrix CMyMatrix::invers()
    {
        if(m!=2 || m!=2)
        {
            throw "Keine 2 x 2 Matrix";
        }
        else
        {
            CMyMatrix result(2,2);
            double bruch = 1/((*this)[0][0]*(*this)[1][1]-(*this)[0][1]*(*this)[1][0]);
            result[0][0] = bruch * (*this)[1][1];
            result[1][1] = bruch * (*this)[0][0];
            result[0][1] = -bruch * (*this)[0][1];
            result[1][0] = -bruch * (*this)[1][0];
            return result;
        }
    }

    CMyVektor CMyMatrix::operator*(CMyVektor x)
    {
        if(n != x.get_dimension())
        {
            throw "Unpassende Dimension fuer CMyMatrix::operator*()";
        }
        else
        {
            CMyVektor result(m);
            for(unsigned int i = 0;i<m;i++)
            {
                for(unsigned int j = 0; j < n;j++)
                {
                    result[i] += (*this)[i][j] * x[j];
                }
            }
            return result;
        }

    }