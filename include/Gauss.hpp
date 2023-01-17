#ifndef GAUSS
#define GAUSS

#include <vector>

class Gauss
{
private:
    float resultado;
    int ordemMatriz;

public:
    Gauss(std::vector<std::vector<float>> matriz);
    float getResultado() const;

private:
    void escalonamento(std::vector<std::vector<float>>& matriz, int pivo, int mod);
    float determinante(std::vector<std::vector<float>> matriz);
    void setOrdemMatriz(int tamMatriz);
};

#endif