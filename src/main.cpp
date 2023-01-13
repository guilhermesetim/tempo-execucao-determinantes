#include <iostream>
#include "../include/Sarrus.hpp"
#include "../include/Triangulo.hpp"

using namespace std;

int main() {

    int matriz1[3][3] = { 
        {4,5,-3},
        {2,1,0},
        {3,-1,1} 
    };
    int matriz2[3][3] = { 
        {1,3,2},
        {-1,0,-2},
        {2,5,1} 
    };

    Sarrus sarrus1(matriz1);
    cout << "Determinante: " << sarrus1.getResultado() << endl;
    Sarrus sarrus2(matriz2);
    cout << "Determinante: " << sarrus2.getResultado() << endl;

    Triangulo triangulo1(matriz1);
    cout << "Determinante: triangulo: " << triangulo1.getResultado() << endl;
    Triangulo triangulo2(matriz2);
    cout << "Determinante: triangulo: " << triangulo2.getResultado() << endl;


    return 0;
}