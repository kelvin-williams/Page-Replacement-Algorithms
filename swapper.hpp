#ifndef SWAPPER_HPP
#define SWAPPER_HPP

#include <vector>
#include <cstring>
#include <iostream>
#include <limits.h>

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