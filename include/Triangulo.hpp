class Triangulo
{
private:
    int resultado;
    int m[3][3];

public:
    Triangulo(int _matriz[3][3]);
    int getResultado() const;

private:
    int sentidoPositivo();
    int sentidoNegativo();
    void setMatriz(int _matriz[3][3]);
};
