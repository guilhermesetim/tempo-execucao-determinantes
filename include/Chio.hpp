#ifndef CHIO
#define CHIO

class Chio 
{
private:
    float resultado;
    float matrizTemp3[3][3];

public:
    Chio(float matriz[4][4]);
    float getResultado() const;

private:
    float sarrus(float matriz[3][3]);
    void matriz3(float _matriz[4][4]);
    void jacob(float matriz[4][4]);
    int regra(int i, int j);
};

#endif