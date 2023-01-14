#include "../include/Laplace.hpp"
#include <iostream>

Laplace::Laplace(float matriz[4][4]) {

    int colEscolhida = coordRandomica();

    float determinante = 0;
    for(int i = 0; i < 4; i++) {
        float cofator = this->cofator(i, colEscolhida, matriz);
        determinante += matriz[i][colEscolhida] * cofator;
    }

    std::cout << "Determinante: " << determinante << std::endl;
    
}

void Laplace::matriz3(int l, int c, float _matriz[4][4]) {
    int linMat3 = 0;
    for(int i = 0; i < 4; ++i) {
        
        if (i != l) // linha cofator
        {
            int colMat3 = 0;
            for(int j = 0; j < 4; ++j) {
                if (j != c) // coluna do cofator
                {
                    matrizTemp3[i-linMat3][j-colMat3] = _matriz[i][j];
                }
                else {
                    colMat3 = 1;
                }
            }
        }
        else {
            linMat3 = 1;
        }
        
    }
}


float Laplace::sarrus(float matriz[3][3]) {

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



float Laplace::cofator(int l, int c, float matriz[4][4]) {

    int _C;
    float _D;
    // sinal - propriedade de potencia
    ( (l+c) % 2 == 0 ) ? _C = 1 : _C = -1;

    this->matriz3(l,c,matriz);

    _D = this->sarrus(matrizTemp3);



    return (_C * _D);
    
}

int Laplace::coordRandomica() {
    srand(time(NULL));
    int numeroAleatorio = rand() % 4;

    return numeroAleatorio;
}