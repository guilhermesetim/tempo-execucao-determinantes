#include "../include/Gauss.hpp"

Gauss::Gauss(std::vector<std::vector<float>> matriz) {

    setOrdemMatriz(matriz[0].size());

    // percorre as linhas da matriz
    for (int r = 0; r < ordemMatriz-1; ++r ) {

        // mudança de pivô em relação a linha de referencia
        for (int p = 1+r; p < ordemMatriz; ++p) {
            this->escalonamento(matriz, r, p);
        }

    }

    this->resultado = determinante(matriz);
}

void Gauss::escalonamento(std::vector<std::vector<float>>& matriz, int pivo, int mod) {
   
    float x;
    
    /* x representa
    * encontrar um multiplicador, 
    * que multiplique o elemento a ser convertido
    * e que somado a linha de referencia, 
    * torne esse elemento = zero
    */
    x = (float)((0 - matriz[mod][pivo]) / (float)matriz[pivo][pivo]);

    // modificar linhas
    for(int j = pivo; j < ordemMatriz; ++j)
        matriz[mod][j] += (matriz[pivo][j] * x);

}

float Gauss::determinante(std::vector<std::vector<float>> matriz) {

    float det = 1;
    for (int d = 0; d < ordemMatriz; d++) {
        det*= matriz[d][d];
    }
    return det;
}

float Gauss::getResultado() const {
    return this->resultado;
}

void Gauss::setOrdemMatriz(int tamMatriz) {
    this->ordemMatriz = tamMatriz;
}