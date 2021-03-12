#ifndef Word_hpp
#define Word_hpp

#include "Opcode.h"
#include <iostream>
#include <sstream>

class Word
{
    private:
    public:
        Opcode opc;
        int r1;
        int r2;
        int p;

        Word(Opcode opc, int r1, int r2, int p);
        ~Word();

        // std::string toString();

};

#endif