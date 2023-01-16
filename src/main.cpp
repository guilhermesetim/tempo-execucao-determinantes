#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cmath>

#include "../include/Laplace.hpp"
#include "../include/Chio.hpp"
#include "../include/Gauss.hpp"

using namespace std::chrono;
using namespace std;

void transformarCSVtoMatriz(string _nomeArquivo, float m[4][4]);
void gerarTestes(int qTestes);
int numRandomico(int numero);

int main() {

    float usuario[5][5] = {
        {1,-1,0,3,2},
        {1,3,2,0,-2},
        {-1,2,-1,-5,4},
        {2,3,2,-2,0},
        {4,4,-2,-1,3}
    };

    vector<vector<float>> matrizN;
    for(int i = 0; i < 5; i++) {
        vector<float> linha;
        for (int j = 0; j < 5; j++) {
            
            linha.push_back(usuario[i][j]);
        }
        matrizN.push_back(linha);
    }

    //Chio chio(matrizN);

    Gauss gauss(matrizN);
    cout << "Gauss det = " << gauss.getResultado() << endl;

/*    
    int quantTestes = 10,
        numTeste = 1;


    float mLaplace[4][4], 
          mChio[4][4], 
          mGauss[4][4];

    double tempLaplace = 0,
            tempChio = 0,
            tempGauss = 0;

    vector<int> regLaplace,
                regChio,
                regGauss;

    gerarTestes(quantTestes);
    

    //  Testes  
    while (numTeste <= quantTestes) {

        float m[4][4];
        string arquivoTeste = "./csv/input/teste" + to_string(numTeste) + ".csv";
        transformarCSVtoMatriz(arquivoTeste, m);

        //  Inserir elementos nas matrizes 
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mLaplace[i][j] = m[i][j];
                mChio[i][j] = m[i][j];
                mGauss[i][j] = m[i][j];
            }
        }

        // LaPlace
        auto startLaplace = chrono::high_resolution_clock::now();
        Laplace laplace(mLaplace);
        auto stopLaplace = high_resolution_clock::now();
        std::chrono::nanoseconds duracaoLaplace = duration_cast<nanoseconds>(stopLaplace - startLaplace);
        regLaplace.push_back(duracaoLaplace.count());
        
        // Chio
        auto startChio = chrono::high_resolution_clock::now();
        Chio chio(mChio);
        auto stopChio = high_resolution_clock::now();
        std::chrono::nanoseconds duracaoChio = duration_cast<nanoseconds>(stopChio - startChio);
        regChio.push_back(duracaoChio.count());

        // Eliminação de Gauss
        auto startGauss = chrono::high_resolution_clock::now();
        Gauss gauss(mGauss);
        auto stopGauss = high_resolution_clock::now();
        std::chrono::nanoseconds duracaoGauss = duration_cast<nanoseconds>(stopGauss - startGauss);
        regGauss.push_back(duracaoGauss.count());

        numTeste++;
    }


    // criação do arquivo .csv com os registros de tempo 
    ofstream arquivoCSV;
    arquivoCSV.open("Tempo-Determinantes.csv", ios::trunc);
    string tabela =  "Tempo execução determinante \nteste, LaPlace, Chio, Eliminacao Gauss \n";

    // grava registros em arquivo .csv
    for (int t = 0; t < quantTestes; t++) {
        string registro = to_string(t+1) + ", "
                        + to_string(regLaplace[t]) + ", " 
                        + to_string(regChio[t]) + ", " 
                        + to_string(regGauss[t]) + '\n';
        
        tabela += registro;
        tempLaplace += regLaplace[t]; 
        tempChio += regChio[t]; 
        tempGauss += regGauss[t];
    }
    // registra no arquivo
    arquivoCSV << tabela;
    arquivoCSV.close();
    
    // resultados
    cout << "Duracao Laplace: " << tempLaplace << endl;
    cout << "Duracao Chio: " << tempChio << endl;
    cout << "Duracao Gauss: " << tempGauss << endl; 
*/

    return 0;
}


void transformarCSVtoMatriz(string _nomeArquivo, float m[4][4])
{
    std::ifstream leitura(_nomeArquivo.c_str());
   
    if(leitura) {

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
        cout << "Arquivo " << _nomeArquivo << " não existe!!";

    leitura.close(); 
 
}



void gerarTestes(int qTestes) {
    /* criação do arquivo .csv com os registros de tempo */
    ofstream arquivoCSV;

    // grava registros em arquivo .csv
    for (int i = 1; i <= qTestes; i++) {
        string registro = "";
        string nomeTeste = "./csv/input/teste" + to_string(i) + ".csv";
        arquivoCSV.open(nomeTeste, ios::trunc);

        for (int l = 1; l <= 4; ++l) {
            registro += to_string(numRandomico(i*l+3)) + ","
                    + to_string(numRandomico(i*l+7)) + ","
                    + to_string(numRandomico(i*l+5)) + ","
                    + to_string(numRandomico(i*l+13)) + "\n";
        }  
        // registra no arquivo
        arquivoCSV << registro;
        arquivoCSV.close();
    }
    
}

int numRandomico(int numero) {
    srand(time(NULL));
    int numeroAleatorio =  ( 3 * (rand() * numero) ) % 10;

    return numeroAleatorio ;
}