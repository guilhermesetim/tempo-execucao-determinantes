#include "../include/Triangulo.hpp"
#include <iostream>

Triangulo::Triangulo(int _matriz[3][3])
{
    this->setMatriz(_matriz);
    this->resultado = sentidoPositivo() - sentidoNegativo();
}

void Triangulo::setMatriz(int _matriz[3][3]) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->m[i][j] = _matriz[i][j];
        }
    }
}

int Triangulo::sentidoPositivo() {
    int somatorio = 0;

    somatorio+= m[0][0] * m[1][1] * m[2][2];
    somatorio+= m[0][1] * m[1][2] * m[2][0];
    somatorio+= m[0][2] * m[1][0] * m[2][1];

    std::cout << "Positivo: " << somatorio << std::endl;
    return somatorio;
}

int Triangulo::sentidoNegativo() {
     int somatorio = 0;

    somatorio+= m[0][2] * m[1][1] * m[2][0];
    somatorio+= m[1][2] * m[2][1] * m[0][0];
    somatorio+= m[2][2] * m[0][1] * m[1][0];

    std::cout << "Negativo: " << somatorio << std::endl;
    return somatorio;
}

int Triangulo::getResultado() const {
    return resultado;
}

