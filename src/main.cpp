#include <iostream>
#include "../include/Sarrus.hpp"

using namespace std;

int main() {

    int matriz[3][3] = { 
        {4,5,-3},
        {2,1,0},
        {3,-1,1} 
    };

    Sarrus sarrus(matriz);
    cout << "Determinante: " << sarrus.getResultado() << endl;


    return 0;
}