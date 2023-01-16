#include "../include/Gauss.hpp"
#include <iostream>

Gauss::Gauss(std::vector<std::vector<float>> matrizN) {

    int ordemMatriz = matrizN[0].size();

    for (int r = 0; r < ordemMatriz-1; ++r ) {
        for (int t = 1+r; t < ordemMatriz; ++t) {
            this->escalonamento(matrizN, r, t, ordemMatriz);
        }
    }

    this->resultado = determinante(matrizN, ordemMatriz);
}

void Gauss::escalonamento(std::vector<std::vector<float>>& matriz, int linhaR, int linhaT, int ordemMatriz) {
   
    float x;

    x = (float)((0 - matriz[linhaT][linhaR]) / (float)matriz[linhaR][linhaR]);

    for(int j = linhaR; j < ordemMatriz; ++j)
        matriz[linhaT][j] += (matriz[linhaR][j] * x);

}

float Gauss::determinante(std::vector<std::vector<float>> matriz, int ordemMatriz) {

    float det = 1;
    for (int d = 0; d < ordemMatriz; d++) {
        det*= matriz[d][d];
    }

    return det;

}

float Gauss::getResultado() const {
    return this->resultado;
}