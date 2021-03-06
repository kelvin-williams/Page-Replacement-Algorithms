#include <iostream>
#include <fstream>
#include "swapper.hpp"

std::vector <int> GetInfofromFile(const char * str, int * memsize){

    std::ifstream file;
    file.open(str, std::ios::in);

    std::vector <int> aux;

    int r;
    
    file >> *memsize;


    while(file.good()){

        file >> r;

        aux.push_back(r);

    }

    return aux;
}


int main(){

    int memsize;
    std::vector <int> requests;

    requests = GetInfofromFile("input.txt", &memsize);

    //for(int i = 0; i < requests.size(); i++)
      //  std::cout << "\n" << requests[i];

    swapper fifo, otm, lru;

    fifo.FIFO(requests, memsize);
    otm.OTM(requests, memsize);
    lru.LRU(requests, memsize);

    std::cout << "\nFIFO: "<<fifo.npagelacks;
    std::cout << "\nOTM: "<<otm.npagelacks;
    std::cout << "\nLRU: " << lru.npagelacks << "\n";


    return 0;

}