#include <iostream>
#include <chrono>
#include <fstream>

#include "../include/Sarrus.hpp"
#include "../include/Triangulo.hpp"
#include "../include/Laplace.hpp"
#include "../include/Chio.hpp"
#include "../include/Gauss.hpp"

using namespace std::chrono;
using namespace std;

void retornaConteudoArquivo(string _nomeArquivo, float m[4][4]);

int main() {
/*
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
*/
    
    float m[4][4], mL[4][4], mC[4][4], mG[4][4];
    retornaConteudoArquivo("./arquivosCSV/arquivo.csv", m);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << m[i][j] << " ";
            mL[i][j] = m[i][j];
            mC[i][j] = m[i][j];
            mG[i][j] = m[i][j];
        }
        cout << endl;
    }


    auto start = chrono::high_resolution_clock::now();
    Laplace laplace1(mL);
    auto stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracaoLaplace = duration_cast<nanoseconds>(stop - start);
    cout << "Duracao Laplace: " << duracaoLaplace.count() << endl;
    

    start = chrono::high_resolution_clock::now();
    Chio chio1(mC);
    stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracaoChio = duration_cast<nanoseconds>(stop - start);
    cout << "Duracao Chio: " << duracaoChio.count() << endl;


    start = chrono::high_resolution_clock::now();
    Gauss gauss1(mG);
    stop = high_resolution_clock::now();
    std::chrono::nanoseconds duracaoGauss = duration_cast<nanoseconds>(stop - start);
    cout << "Duracao Gauss: " << duracaoGauss.count() << endl;
    
       


    return 0;
}


void retornaConteudoArquivo(string _nomeArquivo, float m[4][4])
{
    std::ifstream leitura(_nomeArquivo.c_str()); //abre o arquivo
   

    if(leitura)
    {
      
        for(int i = 0; i < 4; i++) {

            string linha, valorTabela = "";
            int caracter = 0, colM = 0;
            getline(leitura, linha);
            
            while(caracter < linha.size()) {
                if(linha[caracter] != ',') {
                    valorTabela+= linha[caracter];
                }
                else {
                    
                    m[i][colM] = stoi(valorTabela);
                    ++colM;
                    valorTabela = "";

                }

                ++caracter;
            }

            m[i][colM] = stoi(valorTabela);
            colM = 0;
        }
    }
    else
        cout << "Arquivo não existe!!";


    leitura.close(); //fecha o arquivo
 
}