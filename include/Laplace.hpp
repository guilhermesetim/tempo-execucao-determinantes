#ifndef LAPLACE
#define LAPLACE

class Laplace
{
private:
    float resultado;

public:
    Laplace(float matriz[3][3]);
    float cofator(int l, int c, float matriz[3][3]);

private:
   
};

#endif