#include "../include/Chio.hpp"
#include <iostream>

Chio::Chio(float matriz[4][4]) {

    if(matriz[0][0] != 1)
        this->jacob(matriz);

    this->matriz3(matriz);
    float det = regra(0,0) * this->sarrus(matrizTemp3);
    this->resultado = det;
}

void Chio::jacob(float matriz[4][4]) {
   
    float x;
    int l;

    if(matriz[1][0] != 0) {
        l = 1;
    }
    else if(matriz[2][0] != 0){
        l = 2;
    }
    else if(matriz[3][0] != 0){
        l = 3;
    }

    x = (float)((1 - matriz[0][0]) / (float)matriz[l][0]);

    matriz[0][0] += (matriz[l][0] * x);
    matriz[0][1] += (matriz[l][1] * x);
    matriz[0][2] += (matriz[l][2] * x);
    matriz[0][3] += (matriz[l][3] * x);
    
}


void Chio::matriz3(float _matriz[4][4]) {

    for (int i = 1; i < 4; ++i) {
        for(int j = 1; j < 4; ++j) {
            float pordCoord = _matriz[i][0] * _matriz[0][j];
            this->matrizTemp3[i-1][j-1] = _matriz[i][j] - pordCoord;
        }
    }
}


float Chio::sarrus(float matriz[3][3]) {

    // positivo
    float somatorioPositivo = 0;
    for(int j = 0; j < 3; ++j) {

        float multiplicador = 1;
        for(int i = 0; i < 3; i++ ) {
            int coluna = i+j;
            if (coluna > 2){coluna-= 3;}
                multiplicador *= matriz[i][coluna];   
        }
        somatorioPositivo+= multiplicador;
    }

    // negativo
    float somatorioNegativo = 0;
    for(int j = 0; j < 3; ++j) {

        float multiplicador = 1;
        int auxCol = 0;

        for(int i = 2; i >= 0; i-- ) {

                int coluna = j + auxCol ;
                if (coluna >= 3){coluna-= 3;}

                multiplicador *= matriz[i][coluna];
                ++auxCol;
            
        }
            somatorioNegativo+= multiplicador;
    }

    return (somatorioPositivo - somatorioNegativo);
}

int Chio::regra(int i, int j) {
    int multiplicador;
    // sinal - propriedade de potencia
    ( (i+j) % 2 == 0 ) ? multiplicador = 1 : multiplicador = -1;
    
    return multiplicador;
}

float Chio::getResultado() const {
    return this->resultado;
}