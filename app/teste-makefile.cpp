#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cmath>


int numRandomico(int numero) {
    srand(time(NULL));
    int numeroAleatorio =  ( 3 * (rand() * numero) ) % 10;

    return numeroAleatorio ;
}



int main(int qTestes, int ordem) {
    /* criação do arquivo .csv com os registros de tempo */
    std::ofstream arquivoCSV;

    // grava registros em arquivo .csv
    for (int i = 1; i <= qTestes; i++) {
        std::string registro = "";
        std::string nomeTeste = "./csv/input/teste" + std::to_string(i) + ".csv";
        arquivoCSV.open(nomeTeste, std::ios::trunc);

        for (int l = 1; l <= ordem; ++l) {
            for (int c = 1; c <= ordem; ++c){
                if (c != ordem) {
                    registro += std::to_string(numRandomico(i*c*l)) + ",";
                }
                else {
                    registro += std::to_string(numRandomico(i*c*l)) + "\n";
                }   
            }  
        }  
        
        // registra no arquivo
        arquivoCSV << registro;
        arquivoCSV.close();
    }
    
}

