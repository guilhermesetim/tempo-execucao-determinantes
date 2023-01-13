class Triangulo
{
private:
    float resultado;
    float m[3][3];

public:
    Triangulo(float _matriz[3][3]);
    float getResultado() const;

private:
    float sentidoPositivo();
    float sentidoNegativo();
    void setMatriz(float _matriz[3][3]);
};
