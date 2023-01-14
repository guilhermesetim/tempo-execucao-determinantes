#ifndef LAPLACE
#define LAPLACE

class Laplace
{
private:
    float resultado;
    float matrizTemp3[3][3];

public:
    
    Laplace(float matriz[4][4]);

private:
    void matriz3(int l, int c, float _matriz[4][4]);
    float cofator(int l, int c, float matriz[4][4]);
    float sarrus(float matriz[3][3]);
    int coordRandomica();
};

#endif