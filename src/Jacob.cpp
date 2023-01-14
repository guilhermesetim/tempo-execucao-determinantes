#include "../include/Jacob.hpp"
#include <iostream>

Jacob::Jacob(float m[3][3]) {
    float x;
    int l;

    if(m[1][0] != 0) {
        l = 1;
    }
    else {
        l = 2;
    }

    x = (float)((1 - m[0][0]) / (float)m[l][0]);

    std::cout << "x: " << x << std::endl;

    m[0][0] += (m[l][0] * x);
    m[0][1] += (m[l][1] * x);
    m[0][2] += (m[l][2] * x);
    
}


