#include "Word.hpp"

using namespace std;

Word::Word(Opcode opc, int r1, int r2, int p){
    this->opc = opc;
    this->r1 = r1;
    this->r2 = r2;
    this->p = p;
}

Word::~Word(){}

// string Word::toString(){
//     stringstream ss;
//     ss << "opc: " << this->opc << endl;
//     ss << "r1: " <<  this->r1 << endl;
//     ss << "r2: " << this->r2 << endl;
//     ss << "p: " << this->p << endl ; 
//     ss << "--------------------------" << endl;

//     return ss.str();

// }