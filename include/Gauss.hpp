#ifndef GAUSS
#define GAUSS

class Gauss
{
private:
    float resultado;

public:
    Gauss(float matriz[4][4]);
    void escalonamento(float matriz[4][4], int linhaR, int linhaT);
    float determinante(float matriz[4][4]);
};

#endif