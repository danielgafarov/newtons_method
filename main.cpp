#include <iostream>
#include "CMyVektor.h"
#include "CMyMatrix.h"
#include "Functions.h"

int main() {
    /*CMyVektor stelle(4);          //Testberechnung
    stelle[0] = 1;
    stelle[1] = 2;
    stelle[2] = 0;
    stelle[3] = 3;
    CMyMatrix result = jacobi(stelle,&f);
    std::cout << result[0][0] << " "  << result[0][1] << " " << result[0][2] << " " << result[0][3] << " " << std::endl
     << result[1][0] << " " << result[1][1] << " " << result[1][2] << " " << result[1][3] << " " << std::endl
     << result[2][0] << " " << result[2][1] << " " << result[2][2] << " " << result[2][3] << " " << std::endl;*/
    try
    {
        CMyVektor stelle(2);
        stelle[0] = 1;
        stelle[1] = 1;
        CMyVektor result = newtonverfahren(stelle,&c);
        std::cout << "Nullstelle: " << result[0] << " " << result[1] << std::endl;
        stelle[0] = result[0];
        stelle[1] = result[1];
        result = c(stelle);
        std::cout << "eingesetzt in Funktion: " << result[0] << " " << result[1] << std::endl;
    }
    catch(const char* error)
    {
        std::cout << error << std::endl;
    }
    return 0;
}