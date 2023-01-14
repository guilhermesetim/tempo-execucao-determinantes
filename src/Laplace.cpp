#include "../include/Laplace.hpp"
#include <iostream>

Laplace::Laplace(float matriz[3][3]) {
    
}


float Laplace::cofator(int l, int c, float matriz[3][3]) {

    int _C, _D;
    // sinal - propriedade de potencia
    ( (l+c) % 2 == 0 ) ? _C = 1 : _C = -1;

    // positivo
    float somatorioPositivo = 0;
    for(int j = 0; j < 3; ++j) {

        if(j != c) // coluna do cofator
        {
            float multiplicador = 1;
            bool linhaCofator = true;
            for(int i = 0; i < 3; i++ ) {
                int coluna = i+j;
                if (coluna > 2){coluna-= 3;}
                if (i != l)  // linha do cofator
                {
                    linhaCofator = false;

                    std::cout << "Positivo: " << matriz[i][coluna] << std::endl;
                    multiplicador *= matriz[i][coluna];
                }
                
            }
            if(!linhaCofator)
                somatorioPositivo+= multiplicador;
        }
        
    }

    // negativo
    float somatorioNegativo = 0;
    for(int j = 0; j < 3; ++j) {
        if(j != c) // coluna do cofator
        {
            float multiplicador = 1;
            int auxCol = 0;
            bool linhaCofator = true;

            for(int i = 2; i >= 0; i-- ) {
                if (i != l)  // linha do cofator
                {
                    linhaCofator = false;
                    int coluna = j + auxCol ;
                    if (coluna >= 3){coluna-= 3;}
                    std::cout << "Negativo: " << matriz[i][coluna] << std::endl;
                    multiplicador *= matriz[i][coluna];
                    ++auxCol;
                }
            }
            if(!linhaCofator)
                somatorioNegativo+= multiplicador;
        }
    }




    return (somatorioPositivo - somatorioNegativo);
}