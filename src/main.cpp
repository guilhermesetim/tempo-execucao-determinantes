#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>

#include "../include/Laplace.hpp"
#include "../include/Chio.hpp"
#include "../include/Gauss.hpp"

using namespace std::chrono;
using namespace std;

vector<vector<float>> transformarCSVtoMatriz(string _nomeArquivo, int ordem);


int main() {
    
    int tamMatriz = 4;
    const int maxMatriz = 8;

    while(tamMatriz <= maxMatriz ){


        vector<int> regLaplace,
                    regChio,
                    regGauss;

        int numTeste = 1,
            quantTestes = 1000;

    
        //  Testes  
        while (numTeste <= quantTestes) {            

            string arquivoTeste = "./csv/matriz" + to_string(tamMatriz) + ".csv";
            vector<vector<float>> arqCSV = transformarCSVtoMatriz(arquivoTeste, tamMatriz);

            
            vector<vector<float>> mLaplace, 
                                mChio, 
                                mGauss;


            /*
                Inserir elementos nas matrizes 
            */
            for(int i = 0; i < tamMatriz; i++) {
                vector<float> linha;
                for (int j = 0; j < tamMatriz; j++) {
                    linha.push_back(arqCSV[i][j]);
                }
                mLaplace.push_back(linha);
                mChio.push_back(linha);
                mGauss.push_back(linha);
            }


            /* 
                LaPlace
            */
            auto startLaplace = chrono::high_resolution_clock::now();
            Laplace laplace(mLaplace);
            auto stopLaplace = high_resolution_clock::now();
            std::chrono::nanoseconds duracaoLaplace = duration_cast<nanoseconds>(stopLaplace - startLaplace);
            regLaplace.push_back(duracaoLaplace.count());
            
            /*
                Chio
            */
            auto startChio = chrono::high_resolution_clock::now();
            Chio chio(mChio);
            auto stopChio = high_resolution_clock::now();
            std::chrono::nanoseconds duracaoChio = duration_cast<nanoseconds>(stopChio - startChio);
            regChio.push_back(duracaoChio.count());

            /*
                Eliminação de Gauss
            */
            auto startGauss = chrono::high_resolution_clock::now();
            Gauss gauss(mGauss);
            auto stopGauss = high_resolution_clock::now();
            std::chrono::nanoseconds duracaoGauss = duration_cast<nanoseconds>(stopGauss - startGauss);
            regGauss.push_back(duracaoGauss.count());

            numTeste++;
        }


        /* 
            Criação do arquivo .csv
        */
        ofstream arquivoCSV;
        arquivoCSV.open("./datasets/Resultado"+ to_string(tamMatriz) +".csv", ios::trunc);
        string tabela =  "teste, LaPlace, Chio, Eliminacao Gauss \n";

        // grava registros em arquivo .csv
        for (int t = 0; t < quantTestes; t++) {
            string registro = to_string(t+1) + ", "
                            + to_string(regLaplace[t]) + ", " 
                            + to_string(regChio[t]) + ", " 
                            + to_string(regGauss[t]) + '\n';
            tabela += registro;
        }

        // registra no arquivo
        arquivoCSV << tabela;
        arquivoCSV.close();

        ++tamMatriz;
    }
    



    return 0;
}


 vector<vector<float>> transformarCSVtoMatriz(string _nomeArquivo, int ordem)
{
    vector<vector<float>> tabela;

    std::ifstream leitura(_nomeArquivo.c_str());
   
    if(leitura) {
        
        for(int i = 0; i < ordem; i++) {

            vector<float> registros;
            string linha, valorTabela = "";
            int caracter = 0;

            getline(leitura, linha);
            
            while(caracter < int(linha.size())) {
                if(linha[caracter] != ',') {
                    valorTabela+= linha[caracter];
                }
                else {
                    registros.push_back( stoi(valorTabela) );
                    valorTabela = "";
                }

                ++caracter;
            }

            registros.push_back ( stoi(valorTabela) );
            tabela.push_back(registros);
        }
    }
    else
        cout << "Arquivo " << _nomeArquivo << " não existe!!";

    leitura.close(); 

    return tabela;
 
}

