#ifndef CHIO
#define CHIO

#include <vector>

class Chio 
{
private:
    float resultado;
    int ordemMatriz;

public:
    Chio(std::vector<std::vector<float>>& matriz);
    float getResultado() const;

private:
    float sarrus(std::vector<std::vector<float>> matriz);
    void jacob(std::vector<std::vector<float>>& matriz);
    void setOrdemMatriz(int tamMatriz);
};

#endif