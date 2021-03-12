#include "Aux.hpp"
using namespace std;

Aux::Aux(){ 
    this->enumToString = {
        {0, "DATA"},
        {1, "___"},
        {2, "JMP"}, // já implementada - Diego
        {3, "JMPI"}, // já implementada - Diego
        {4, "JMPIG"}, // já implementada - Léo
        {5, "JMPIL"}, // já implementada - Diego
        {6, "JMPIE"}, // já implementada - Diego
        {7, "JMPIM"},
        {8, "JMPIGM"},
        {9, "JMPILM"},
        {10, "JMPIEM"},
        {11, "STOP"}, // já implementada - Léo
        {12, "ADDI"}, // já implementada - Léo
        {13, "SUBI"}, // já implementada - Diego
        {14, "ADD"}, // já implementada - Léo
        {15, "SUB"}, // já implementada - Léo
        {16, "MULT"}, // já implementada - Diego
        {17, "LDI"}, // já implementada - Léo
        {18, "LDD"}, // já implementada - Diego
        {19, "STD"}, // já implementada - Léo
        {20, "LDX"},
        {21, "STX"}, // já implementada - Léo
        {22, "SWAP"} // já implementada - Diego
    };
}

std::string Aux::dump(Word* w){
    stringstream ss;
    ss << "[ " << this->enumToString[w->opc] << ", ";
    ss << w->r1 << ", ";
    ss << w->r2 << ", ";
    ss << w->p << "  ]" << endl;
    return ss.str();
}

std::string Aux::dump(std::vector<Word*> m, int ini, int fim){
    stringstream ss;
    for(int i = ini; i < fim; i++){
        ss << i << ": "; 
        ss << this->dump(m[i]);
    }

    return ss.str();
}

std::string Aux::dump(std::vector<Word*> m)
{
    stringstream ss;
    stringstream _ss;
    int count = 0 ;
    for(auto i : m){        
        _ss << count++ << ": " << this->dump(i);
        if(i->opc != ___)
        {
            ss << _ss.str();
            _ss.str("");
        }
    }
    return ss.str();
}

void Aux::carga(vector<Word*> p, vector<Word*> m){
    
    for(int i = 0 ; i < p.size(); i++){
        m[i]->opc = p[i]->opc;
        m[i]->r1= p[i]->r1;
        m[i]->r2 = p[i]->r2;
        m[i]->p = p[i]->p;
    }
}

