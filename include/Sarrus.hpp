

class Sarrus 
{
private:
    int matriz[3][5];
    int resultado;

public:
    Sarrus(int matrizQ[3][3]);
    int getResultado() const;

private:
    void setMatriz(int matrizQ[3][3]);
    void complemento(int matriz[3][3]);
    int sentidoPositivo();
    int sentidoNegativo();
};