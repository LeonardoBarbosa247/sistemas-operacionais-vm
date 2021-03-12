#include "Vm.hpp"

Vm::Vm(){
    this->tamMem = 1024;
    
    (this->m) = std::vector<Word*>();

    for(int i = 0 ; i < tamMem; i++){
        (this->m).push_back(new Word(___, -1, -1, -1));
    }

    cpu = new Cpu(this->m);
}