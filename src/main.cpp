#include <iostream>
#include <chrono>

#include "../include/Sarrus.hpp"
#include "../include/Triangulo.hpp"

using namespace std::chrono;
using namespace std;

int main() {

    int matriz1[3][3] = { 
        {4,5,-3},
        {2,1,0},
        {3,-1,1} 
    };
    int matriz2[3][3] = { 
        {1,3,2},
        {-1,0,-2},
        {2,5,1} 
    };

    auto start = chrono::high_resolution_clock::now();

    Sarrus sarrus1(matriz1);
    //cout << "Determinante: " << sarrus1.getResultado() << endl;
    Sarrus sarrus2(matriz2);
    //cout << "Determinante: " << sarrus2.getResultado() << endl;

    auto stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracao = duration_cast<nanoseconds>(stop - start);

    cout << "Duracao Sarrus: " << duracao.count() << endl;

    start = chrono::high_resolution_clock::now();
    Triangulo triangulo1(matriz1);
    //cout << "Determinante: triangulo: " << triangulo1.getResultado() << endl;
    Triangulo triangulo2(matriz2);
    //cout << "Determinante: triangulo: " << triangulo2.getResultado() << endl;
    stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracaoT = duration_cast<nanoseconds>(stop - start);

    cout << "Duracao Triangulo: " << duracaoT.count() << endl;


    return 0;
}