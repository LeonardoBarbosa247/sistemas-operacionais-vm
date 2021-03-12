#ifndef Aux_hpp
#define Aux_hpp

#include "Word.hpp"
#include <vector>
#include <iostream>
#include <map>


class Aux
{
    private: 
        std::map<int, std::string> enumToString;
    public:
        Aux();
        std::string dump(Word* w);
        std::string dump(std::vector<Word*> m, int ini, int fim);
        std::string dump(std::vector<Word*> m);
        void carga(std::vector<Word*> p, std::vector<Word*> m);
};

#endif