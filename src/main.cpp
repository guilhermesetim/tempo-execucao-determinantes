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

vector<vector<float>> transformarCSVtoMatriz(string _nomeArquivo, int ordem);
void gerarTestes(int qTestes, int ordem);
int numRandomico(int numero);

int main() {


    
        
    

    //gerarTestes(quantTestes, 5);
    
    int tamMatriz = 4;
    while(tamMatriz <= 7){



        unsigned long int tempLaplace = 0,
                        tempChio = 0,
                        tempGauss = 0;

        vector<int> regLaplace,
                    regChio,
                    regGauss;

        int numTeste = 1,
            quantTestes = 1;



    
        //  Testes  
        while (numTeste <= quantTestes) {            

            //string arquivoTeste = "./csv/input/teste" + to_string(numTeste) + ".csv";
            string arquivoTeste = "./csv/input/matriz" + to_string(tamMatriz) + ".csv";
            vector<vector<float>> arqCSV = transformarCSVtoMatriz(arquivoTeste, tamMatriz);

            
            vector<vector<float>> mLaplace, 
                                mChio, 
                                mGauss;


            //  Inserir elementos nas matrizes 
            vector<vector<float>> matrizN;
            for(int i = 0; i < tamMatriz; i++) {
                vector<float> linha;
                for (int j = 0; j < tamMatriz; j++) {
                    linha.push_back(arqCSV[i][j]);
                }
                mLaplace.push_back(linha);
                mChio.push_back(linha);
                mGauss.push_back(linha);
            }


            // LaPlace
            auto startLaplace = chrono::high_resolution_clock::now();
            Laplace laplace(mLaplace);
            auto stopLaplace = high_resolution_clock::now();
            cout << "Laplace: " << laplace.getResultado() << endl;
            std::chrono::nanoseconds duracaoLaplace = duration_cast<nanoseconds>(stopLaplace - startLaplace);
            regLaplace.push_back(duracaoLaplace.count());
            
            // Chio
            auto startChio = chrono::high_resolution_clock::now();
            Chio chio(mChio);
            auto stopChio = high_resolution_clock::now();
            cout << "Chio: " << chio.getResultado() << endl;
            std::chrono::nanoseconds duracaoChio = duration_cast<nanoseconds>(stopChio - startChio);
            regChio.push_back(duracaoChio.count());

            // Eliminação de Gauss
            auto startGauss = chrono::high_resolution_clock::now();
            Gauss gauss(mGauss);
            auto stopGauss = high_resolution_clock::now();
            cout << "Gauss: " << gauss.getResultado() << endl;
            std::chrono::nanoseconds duracaoGauss = duration_cast<nanoseconds>(stopGauss - startGauss);
            regGauss.push_back(duracaoGauss.count());

            numTeste++;
        }


        // criação do arquivo .csv com os registros de tempo 
        ofstream arquivoCSV;
        arquivoCSV.open("./csv/output/Resultado"+ to_string(tamMatriz) +".csv", ios::trunc);
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
        cout << "Duracao Chio: [" << tamMatriz << "] = " << tempChio << endl;
        cout << "Duracao Gauss: [" << tamMatriz << "] = " << tempGauss << endl; 

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
            
            while(caracter < linha.size()) {
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



void gerarTestes(int qTestes, int ordem) {
    /* criação do arquivo .csv com os registros de tempo */
    ofstream arquivoCSV;

    // grava registros em arquivo .csv
    for (int i = 1; i <= qTestes; i++) {
        string registro = "";
        string nomeTeste = "./csv/input/teste" + to_string(i) + ".csv";
        arquivoCSV.open(nomeTeste, ios::trunc);

        for (int l = 1; l <= ordem; ++l) {
            for (int c = 1; c <= ordem; ++c){
                if (c != ordem) {
                    registro += to_string(numRandomico(i*c*l)) + ",";
                }
                else {
                    registro += to_string(numRandomico(i*c*l)) + "\n";
                }   
            }  
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