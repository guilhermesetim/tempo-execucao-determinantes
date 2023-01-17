#include <iostream>
#include <fstream>



int numRandomico(int numero) {
    srand(time(NULL));
    int numeroAleatorio =  ( 3 * (rand() * numero) ) % 10;

    return numeroAleatorio ;
}


int main() {

    int qTestes, ordem;

    std::cout << "Ordem das matrizes [n][n]: ";
    std::cin >> ordem;
    std::cout << "Quantidade de testes: ";
    std::cin >> qTestes;

    if(ordem < 4){ordem = 4;}
    else if(ordem > 8){ordem = 8;}

    /* criação do arquivo .csv com os registros de tempo */
    std::ofstream arquivoCSV;

    // grava registros em arquivo .csv
    for (int i = 1; i <= qTestes; i++) {
        std::string registro = "";
        std::string nomeTeste = "./csv/input/M"+ std::to_string(ordem) +"/teste" + std::to_string(i) + ".csv";
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

