#ifndef Cpu_hpp
#define Cpu_hpp

#include "Word.hpp"
#include <vector>
#include <iostream>

class Cpu
{
    private:
        int pc;
        Word* ir;
        int reg[8];
        std::vector<Word*> m;
        
    public:
        Cpu(std::vector<Word*> m);
        ~Cpu();

        void setContext(int pc);
        void run();
};

#endif