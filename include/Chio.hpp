#ifndef CHIO
#define CHIO

#include <vector>

class Chio 
{
private:
    float resultado;
    float matrizTemp3[3][3];
    std::vector<std::vector<float>> matrizAtual;
    int sinalCofator = 1;

public:
    //Chio(float matriz[4][4]);
    Chio(std::vector<std::vector<float>> matrizN);
    float getResultado() const;

private:
    float sarrus(std::vector<std::vector<float>> matriz);
    void matriz3(float _matriz[4][4]);
    void jacob(std::vector<std::vector<float>>& matriz, int ordemMatriz);
    int regra(int i, int j);
};

#endif