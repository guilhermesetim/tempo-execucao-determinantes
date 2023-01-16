#ifndef LAPLACE
#define LAPLACE

#include <vector>

class Laplace
{
private:
    float resultado;
    std::vector<std::vector<float>> matriz3x3;
    std::vector<std::vector<float>> matrizAtual;

public:
    Laplace(std::vector<std::vector<float>> matriz);
    float getResultado() const;

private:
    void matriz3(int l, int c, std::vector<std::vector<float>> matriz);
    float cofator(int l, int c);
    float sarrus(std::vector<std::vector<float>> matriz);
    int coordRandomica();
};

#endif