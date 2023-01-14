#include "../include/Gauss.hpp"
#include <iostream>

Gauss::Gauss(float matriz[4][4]) {

    for (int r = 0; r < 3; ++r ) {
        for (int t = 1+r; t < 4; ++t) {
            this->escalonamento(matriz, r, t);
        }
    }

    this->resultado = determinante(matriz);

    std::cout << "Gauss: " << resultado << std::endl;

}

void Gauss::escalonamento(float matriz[4][4], int linhaR, int linhaT) {
   
    float x;

    x = (float)((0 - matriz[linhaT][linhaR]) / (float)matriz[linhaR][linhaR]);

    for(int j = linhaR; j < 4; ++j)
        matriz[linhaT][j] += (matriz[linhaR][j] * x);

}

float Gauss::determinante(float matriz[4][4]) {

    float det = 1;
    for (int d = 0; d < 4; d++) {
        det*= matriz[d][d];
    }

    return det;

}