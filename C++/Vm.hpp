#ifndef Vm_hpp
#define Vm_hpp

#include "Word.hpp"
#include "Cpu.hpp"
#include <vector>

class Vm 
{
    public:
        int tamMem;
        std::vector<Word*> m;
        Cpu* cpu;
        Vm();
};

#endif