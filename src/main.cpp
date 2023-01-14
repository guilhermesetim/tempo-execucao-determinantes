#include <iostream>
#include <chrono>

#include "../include/Sarrus.hpp"
#include "../include/Triangulo.hpp"
#include "../include/Jacob.hpp"
#include "../include/Laplace.hpp"

using namespace std::chrono;
using namespace std;

int main() {

    float matriz1[3][3] = { 
        {4,5,-3},
        {2,1,0},
        {3,-1,1} 
    };
    float matriz2[3][3] = { 
        {1,3,2},
        {-1,0,-2},
        {2,5,1} 
    };
    float matriz3[3][3] = { 
        {5,2,-2},
        {0,2,4},
        {4,3,-3} 
    };

    float matriz4[3][3] = { 
        {3,1,0},
        {-2,2,3},
        {0,1,2} 
    };

    Laplace laplace(matriz4);
    cout << "Laplace: " << laplace.cofator(0,0,matriz4) << endl;


    Jacob jacob1(matriz1);
    cout << matriz1[0][0] << " " << matriz1[0][1] << " " << matriz1[0][2] << endl;
    cout << matriz1[1][0] << " " << matriz1[1][1] << " " << matriz1[1][2] << endl;
    cout << matriz1[2][0] << " " << matriz1[2][1] << " " << matriz1[2][2] << endl;
    cout << endl;
    Jacob jacob2(matriz2);
    cout << matriz2[0][0] << " " << matriz2[0][1] << " " << matriz2[0][2] << endl;
    Jacob jacob3(matriz3);
    cout << matriz3[0][0] << " " << matriz3[0][1] << " " << matriz3[0][2]<< endl;

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