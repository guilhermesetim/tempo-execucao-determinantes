#include "../include/Chio.hpp"
#include <vector>
#include <cmath>


Chio::Chio(std::vector<std::vector<float>>& matriz) {

    setOrdemMatriz(matriz[0].size());
    int sinalCofator = 1;

    while (ordemMatriz > 3)
    {
        // verifica se o primeiro elemento não é 1
        if(matriz[0][0] != 1)
            // se não for, transforma para a11 = 1
            this->jacob(matriz);

        // (-1)i+j
        sinalCofator *= pow(-1, 0);

        // transforma a matriz para Matriz(n-1)
       --ordemMatriz;
        std::vector<std::vector<float>> matrizSub;

        for (int i = 1; i <= ordemMatriz; ++i) {
            std::vector<float> linha;
            for(int j = 1; j <= ordemMatriz; ++j) {
                // formula: aij - (ai1 * a1j) 
                float pordCoord = matriz[i][0] * matriz[0][j];
                linha.push_back(matriz[i][j] - pordCoord);
            }
            matrizSub.push_back(linha);
        }
        // matriz transformada
        matriz = matrizSub;
        
    }
    // matriz 3x3
    this->resultado = sinalCofator * sarrus(matriz);
}


void Chio::jacob(std::vector<std::vector<float>>& matriz) {
   
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

    /* x representa
    * encontrar um multiplicador, 
    * que multiplique o elemento a ser convertido
    * e que somado a linha de referencia, 
    * torne esse elemento = 1
    */
    x = (float)((1 - matriz[0][0]) / (float)matriz[l][0]);

    // modificar linhas
    for (int j = 0; j < ordemMatriz; ++j)
        matriz[0][j] += (matriz[l][j] * x);   
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


float Chio::getResultado() const {
    return this->resultado;
}

void Chio::setOrdemMatriz(int tamMatriz) {
    this->ordemMatriz = tamMatriz;
}