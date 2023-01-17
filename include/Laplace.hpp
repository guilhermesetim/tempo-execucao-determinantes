#ifndef LAPLACE
#define LAPLACE

#include <vector>

class Laplace
{
private:
    float resultado;

public:
    Laplace(std::vector<std::vector<float>> matriz);
    float getResultado() const;

private:
    float laplace(std::vector<std::vector<float>> matriz);
    float sarrus(std::vector<std::vector<float>> matriz);
};

#endif