#include "swapper.hpp"

void swapper::FIFO(std::vector <int> requests, int memsize){

    int memory[memsize] = {0};


    int oldest = 0;

    for(int i = 0; i < requests.size(); i++){

        bool isinmem = false;
        

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


void swapper::OTM(std::vector <int> requests, int memsize){

    int memory[memsize] = {0};
    int distance[memsize];

    for(int u = 0; u < memsize; u++)
        distance[u] = INT_MAX;


    for(int i = 0; i < requests.size(); i++){
        
        int isinmem = -1;
        

        for(int k = 0; k < memsize; k++){//Percorre a memória

            if(memory[k] == requests[i])//Se a página já está na memória
                isinmem = k;

        }


        if(isinmem != -1){//Se a página já está na memória não faz mais nada
            
            for(int u = 0; u < memsize; u++)
                distance[u]--;

            //Atualiza a distância
            int dist = 1;
            for(int k = i+1; k < requests.size(); k++){//Descobre a distância até o próximo acesso da página em questão

                if(requests[k] == requests[i] || k == (requests.size() -1)){
                    
                    distance[isinmem] = dist;
                    break;
                }
                dist++;
            }


            continue;
        
        }else{
            
            int biggestDistance = 0;
            int biggestDistanceindex;

            for(int k = 0; k < memsize; k++){//Encontra o elemento que não vai ser acessado pelo maior período de tempo,
                                             //dos que estão na memória.
                if(biggestDistance < distance[k]){
                    biggestDistance = distance[k];
                    biggestDistanceindex = k;
                }
            }

            memory[biggestDistanceindex] = requests[i];

            //Atualizando a distância
            int dist = 1;
            for(int k = i+1; k < requests.size(); k++){//Descobre a distância até o próximo acesso da página em questão

                if(requests[k] == requests[i] || k == (requests.size() -1)){
                    
                    distance[biggestDistanceindex] = dist;
                    break;
                }
                dist++;
            }
            npagelacks++;

            for(int u = 0; u < memsize; u++)
                distance[u]--;

        }
    }

}

void swapper::LRU(std::vector <int> requests, int memsize){

    int memory[memsize] = {0};
    int age[memsize];

    for(int u = 0; u < memsize; u++){
        age[u] = INT_MAX - memsize;
    }


    for(int i = 0; i < requests.size(); i++){

        int isinmem = -1;
        

        for(int k = 0; k < memsize; k++){//Percorre a memória

            if(memory[k] == requests[i])//Se a página já está na memória
                isinmem = k;

        }


        if(isinmem != -1){//Se a página já está na memória só atualiza sua idade
            
            for(int u = 0; u < memsize; u++)
                age[u]++;

            age[isinmem] = 0;
            continue;
        
        }else{
            int oldest = 0;
            int oldestIndex;

            for(int k = 0; k < memsize; k++){//Encontra o elemento que foi acessado há mais tempo
                if(oldest < age[k]){
                    oldest = age[k];
                    oldestIndex = k;
                }
            }

            memory[oldestIndex] = requests[i];

            //Atualiza a idade do elemento adicionado
            age[oldestIndex] = 0;

            npagelacks++;

            for(int u = 0; u < memsize; u++)
                age[u]++;

            std::cout << "\nmemory: ";

            for(int w = 0; w < memsize; w++)
                std::cout << "\n" << memory[w];

        }
    }

}