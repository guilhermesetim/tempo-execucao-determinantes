

class Sarrus 
{
private:
    float matriz[3][5];
    float resultado;

public:
    Sarrus(float matrizQ[3][3]);
    float getResultado() const;

private:
    void setMatriz(float matrizQ[3][3]);
    void complemento(float matriz[3][3]);
    float sentidoPositivo();
    float sentidoNegativo();
};