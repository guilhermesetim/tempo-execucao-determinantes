#ifndef CHIO
#define CHIO

#include <vector>

class Chio 
{
private:
    float resultado;
    std::vector<std::vector<float>> matrizAtual;
    int sinalCofator = 1;
    int ordemMatriz;

public:
    Chio(std::vector<std::vector<float>> matrizN, int tamMatriz);
    float getResultado() const;

private:
    float sarrus(std::vector<std::vector<float>> matriz);
    void jacob(std::vector<std::vector<float>>& matriz, int ordemMatriz);
    int regra(int i, int j);
    void setOrdemMatriz(int tamMatriz);
};

#endif