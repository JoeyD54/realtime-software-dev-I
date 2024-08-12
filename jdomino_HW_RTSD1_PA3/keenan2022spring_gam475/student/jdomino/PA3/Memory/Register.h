#ifndef REGISTER_H
#define REGISTER_H


#include <map>
#include "Mem.h"
#include "Heap.h"


namespace Azul
{

    // Heap class
    class Register
    {
    public:
        // Constants 



    public:
        void Registration(Heap* p, Heap);

        std::map<Heap*, Heap> map;

    };
}


#endif