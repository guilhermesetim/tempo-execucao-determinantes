#include "../include/Laplace.hpp"
#include <vector>
#include <cmath>

Laplace::Laplace(std::vector<std::vector<float>> matriz) {
    this->resultado = laplace(matriz);
}

float Laplace::laplace(std::vector<std::vector<float>> matriz) {

    float determinante = 0;

    if (matriz[0].size() == 3) {
        //calcula o determinante de matriz 3x3 por regra de Sarrus
        determinante = sarrus(matriz);

    } else {

        // Percorre a matriz
        for (int j = 0; j < int(matriz[0].size()); j++) {
            // diferente do elemento escolhido cofator
            if (matriz[0][j] != 0) {
                std::vector<std::vector<float>> auxMatriz; // nova Matriz (n-1)
                
                // sempre escolhida a primeira linha 
                for (int linha = 1; linha < int(matriz[0].size()); linha++) {
                    std::vector<float> auxLinha;
                    for (int coluna = 0; coluna < int(matriz[0].size()); coluna++) {

                        // elimina a coluna pivô
                        if (coluna != j) {
                            auxLinha.push_back(matriz[linha][coluna]);
                        }
                        
                    }
                    auxMatriz.push_back(auxLinha);
                }

                // Calculo da regra de somatório das matrizes
                determinante += pow(-1, j) * matriz[0][j] * laplace(auxMatriz);
            }

        }
    }
    return determinante;
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


float Laplace::getResultado() const {
    return this->resultado;
}
