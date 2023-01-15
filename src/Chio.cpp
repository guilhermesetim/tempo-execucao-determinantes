#include "../include/Chio.hpp"
#include <iostream>
#include <vector>
/*
Chio::Chio(float matriz[4][4]) {

    if(matriz[0][0] != 1)
        this->jacob(matriz);

    this->matriz3(matriz);
    float det = regra(0,0) * this->sarrus(matrizTemp3);
    this->resultado = det;
}
*/
Chio::Chio(std::vector<std::vector<float>> matrizN) {

    int ordemMatriz = matrizN[0].size();

    if(matrizN[0][0] != 1)
        this->jacob(matrizN, ordemMatriz);

    this->sinalCofator *= regra(0,0);

    this->matrizAtual = matrizN;

    while (ordemMatriz > 3)
    {
        for(int i = 0; i < ordemMatriz; i++) {
            for (int j = 0; j < ordemMatriz; j++) {
                std::cout << this->matrizAtual[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "------------------------------" << std::endl;

        if(this->matrizAtual[0][0] != 1)
            this->jacob(this->matrizAtual, ordemMatriz);
        
        this->sinalCofator *= regra(0,0);

       --ordemMatriz;
        std::vector<std::vector<float>> matrizSub;

        for (int i = 1; i <= ordemMatriz; ++i) {
            std::vector<float> linha;
            for(int j = 1; j <= ordemMatriz; ++j) {
                float pordCoord = this->matrizAtual[i][0] * this->matrizAtual[0][j];
                linha.push_back(this->matrizAtual[i][j] - pordCoord);
            }
            matrizSub.push_back(linha);
        }

        this->matrizAtual = matrizSub;
    }
    
    

    
    for(int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            std::cout << this->matrizAtual[i][j] << " ";
        }
        std::cout << std::endl;
    }

    this->resultado = sinalCofator * sarrus(this->matrizAtual);

    std::cout << "Determinante: " << this->resultado << std::endl;

    std::cout << "------------------------------" << std::endl;

}


void Chio::jacob(std::vector<std::vector<float>>& matriz, int ordemMatriz) {
   
    float x;
    int l;

    // verifica se não ocorrerá divisão com denominador zero
    bool zero = true;
    for (int i = 1; i < ordemMatriz || zero; ++i) {
        if(matriz[i][0] != 0) {
            l = i;
            zero = false;
        }
    }
    

    x = (float)((1 - matriz[0][0]) / (float)matriz[l][0]);

    for (int j = 0; j < ordemMatriz; ++j)
        matriz[0][j] += (matriz[l][j] * x);
   
    for(int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            std::cout << this->matrizAtual[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "^^^^^^^^^^^^^^^^^^" << std::endl;
    
}



float Chio::sarrus(std::vector<std::vector<float>> matriz) {

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
    i+= 1;
    j += 1;
    // sinal - propriedade de potencia
    ( (i+j) % 2 == 0 ) ? multiplicador = 1 : multiplicador = -1;
    
    return multiplicador;
}

float Chio::getResultado() const {
    return this->resultado;
}