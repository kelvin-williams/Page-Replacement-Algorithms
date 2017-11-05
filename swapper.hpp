#ifndef SWAPPER_HPP
#define SWAPPER_HPP

#include <vector>
#include <string.h>
#include <iostream>

class swapper{

    public:

        swapper(){};

        ~swapper(){};

        void FIFO(std::vector <int> requests, int memsize);

        void OTM(std::vector <int> requests, int memsize);

        void LRU(std::vector <int> requests, int memsize);

        int npagelacks = 0;

};


#endif /* SWAPPER_HPP */