#ifndef GAUSS
#define GAUSS

#include <vector>

class Gauss
{
private:
    float resultado;
    int ordemMatriz;

public:
    Gauss(std::vector<std::vector<float>> matrizN, int ordemMatriz);
    float getResultado() const;

private:
    void escalonamento(std::vector<std::vector<float>>& matriz, int linhaR, int linhaT, int ordemMatriz);
    float determinante(std::vector<std::vector<float>> matriz, int ordemMatriz);
    void setOrdemMatriz(int tamMatriz);
};

#endif