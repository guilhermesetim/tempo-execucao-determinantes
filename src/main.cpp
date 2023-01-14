#include <iostream>
#include <chrono>

#include "../include/Sarrus.hpp"
#include "../include/Triangulo.hpp"
#include "../include/Jacob.hpp"
#include "../include/Laplace.hpp"
#include "../include/Chio.hpp"
#include "../include/Gauss.hpp"

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

    float matrizLaplace[4][4] = { 
        {3,1,0,1},
        {0,-1,3,4},
        {1,1,0,2},
        {0,1,1,-1} 
    };

    float matrizChio[4][4] = { 
        {1,-4,0,0},
        {0,1,3,0},
        {3,2,1,-1},
        {0,2,1,1} 
    };

    float matrizGauss[4][4] = { 
        {1,3,5,8},
        {2,2,2,6},
        {3,1,1,5},
        {2,2,1,1} 
    };

    Laplace laplace1(matrizLaplace);
    Laplace laplace2(matrizChio);
    Laplace laplace3(matrizGauss);

    Chio chio1(matrizLaplace);
    Chio chio2(matrizChio);
    Chio chio3(matrizGauss);

    Gauss gauss1(matrizLaplace);
    Gauss gauss2(matrizChio);
    Gauss gauss3(matrizGauss);
    
    
    
    

    

   


    auto start = chrono::high_resolution_clock::now();

    Sarrus sarrus1(matriz1);
    //cout << "Determinante: " << sarrus1.getResultado() << endl;
    Sarrus sarrus2(matriz2);
    //cout << "Determinante: " << sarrus2.getResultado() << endl;


    auto stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracao = duration_cast<nanoseconds>(stop - start);

    //cout << "Duracao Sarrus: " << duracao.count() << endl;

    start = chrono::high_resolution_clock::now();
    Triangulo triangulo1(matriz1);
    //cout << "Determinante: triangulo: " << triangulo1.getResultado() << endl;
    Triangulo triangulo2(matriz2);
    //cout << "Determinante: triangulo: " << triangulo2.getResultado() << endl;
    stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracaoT = duration_cast<nanoseconds>(stop - start);

    //cout << "Duracao Triangulo: " << duracaoT.count() << endl;


    


    return 0;
}