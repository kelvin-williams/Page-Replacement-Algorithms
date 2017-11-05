#include "swapper.hpp"

void swapper::FIFO(std::vector <int> requests, int memsize){

    int memory[memsize];

    memset(memory, 0, (sizeof(int)*memsize));

    int oldest = 0;

    for(int i = 0; i < requests.size(); i++){

        bool isinmem = false;
        int emptySpace = -1;
        

        for(int k = 0; k < memsize; k++){//Percorre a memória

            if(memory[k] == requests[i])//Se a página já está na memória
                isinmem = true;

        }


        if(isinmem == true){//Se a página já está na memória não faz mais nada
            
            continue;
        
        }else{
                memory[oldest] = requests[i];//Coloca a página na memória
                oldest = (oldest+1) % memsize;
                npagelacks++;

        }
    }

}