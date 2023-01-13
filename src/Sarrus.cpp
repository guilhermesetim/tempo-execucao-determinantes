#include "../include/Sarrus.hpp"
#include <iostream>

Sarrus::Sarrus(int matrizQ[3][3]) {
    this->setMatriz(matrizQ);
    this->complemento(matrizQ);
    this->resultado = sentidoPositivo() - sentidoNegativo();
}


void Sarrus::complemento(int matriz[3][3]) {
    for (int l = 0; l < 3; l++) {
        this->matriz[l][3] = matriz[l][0];
        this->matriz[l][4] = matriz[l][1];
    }
   
}

void Sarrus::setMatriz(int matrizQ[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->matriz[i][j] = matrizQ[i][j];
        }
    }
}


int Sarrus::sentidoPositivo() {

    int somatorio = 0;
    int coluna = 0;

    while(coluna < 3) {
        int multiplicacao = 1;
        for (int i = 0; i < 3; i++) {
            multiplicacao*= matriz[i][i+coluna];
        }

        somatorio+= multiplicacao;
        ++coluna;
    }
    std::cout << "Positivo: " << somatorio << std::endl;
    return somatorio;
 
}

int Sarrus::sentidoNegativo() {
    int somatorio = 0;
    int coluna = 2;

    while(coluna < 5) {
        int multiplicacao = 1;
        for (int i = 0; i < 3; i++) {
            multiplicacao*= matriz[i][coluna-i];
        }

        somatorio+= multiplicacao;
        ++coluna;
    }
    std::cout << "Negativo: " << somatorio << std::endl;
    return somatorio;
    
}

int Sarrus::getResultado() const {
    return resultado;
}