#include "../include/Laplace.hpp"
#include <iostream>
#include <vector>

Laplace::Laplace(std::vector<std::vector<float>> matrizN) {

    int ordemMatriz = 5;
    int colEscolhida = coordRandomica();

    

    float determinante = 0;

    for(int lMaster = 0; lMaster < ordemMatriz; lMaster++) {

        //--ordemMatriz;
        std::vector<std::vector<float>> matrizSub;

        for (int i = 0; i < ordemMatriz; ++i) {
            if (i != lMaster) {
                std::vector<float> linha;
                for(int j = 1; j < ordemMatriz; ++j) {
                    
                    linha.push_back(matrizN[i][j]);
                    //std::cout << "[" << i << "][" << j << "] = " << matrizN[i][j] << std::endl;
                }
                matrizSub.push_back(linha);
            }
        }        

        this->matrizAtual = matrizSub;

        float det = 0;
        for(int i = 0; i < 4; i++) {
            
            float cofator = this->cofator(i, 0);
            this->matriz3(i,0,this->matrizAtual);
            float D = this->sarrus(this->matriz3x3);
            det += matrizAtual[i][0] * (cofator * D);
        }
        determinante += matrizN[lMaster][0] * (cofator(lMaster, 0) * det);

    }
    this->resultado = determinante;    
}

float Laplace::cofator(int l, int c) {

    int _C;
    // sinal - propriedade de potencia
    ( ( (l+1) + (c+1) ) % 2 == 0 ) ? _C = 1 : _C = -1;

    return _C ;
}

void Laplace::matriz3(int l, int c, std::vector<std::vector<float>> matriz) {

    std::vector<std::vector<float>> _matrizTemp;

    for(int i = 0; i < 4; ++i) {
        std::vector<float> linha;
        if (i != l) // linha cofator
        {            
            for(int j = 1; j < 4; ++j) {
                linha.push_back(matriz[i][j]);
            }
            _matrizTemp.push_back(linha);
        }
    }

    this->matriz3x3 = _matrizTemp;
}


float Laplace::sarrus(std::vector<std::vector<float>> matriz) {

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

int Laplace::coordRandomica() {
    srand(time(NULL));
    int numeroAleatorio = rand() % 4;

    return numeroAleatorio;
}

float Laplace::getResultado() const {
    return this->resultado;
}