#include "Cpu.hpp"

using namespace std;

Cpu::Cpu(vector<Word*> m){
    this->m = m;
}

Cpu::~Cpu(){ }

void Cpu::setContext(int pc){
    this->pc = pc;
}

void Cpu::run(){

    while(true){
        this->ir = this->m[pc];
        switch (this->ir->opc)
        {
            case LDI:
                this->reg[this->ir->r1] = this->ir->p;
                (this->pc)++;
                break;
            case STD:
                this->m[this->ir->p]->opc = DATA;
                this->m[this->ir->p]->p = this->reg[this->ir->r1];
                (this->pc)++;
                break;
            case ADD: 
                this->reg[this->ir->r1] = this->reg[this->ir->r1] + this->reg[this->ir->r2];
                (this->pc)++;
                break;
            case ADDI:
                this->reg[this->ir->r1] = this->reg[this->ir->r1] + this->ir->p;
                (this->pc)++;
                break;
            case STX:
                this->m[this->reg[this->ir->r1]]->opc = DATA;
                this->m[this->reg[this->ir->r1]]->p = this->reg[this->ir->r2];
                (this->pc)++;
                break;
            case SUB:
                this->reg[this->ir->r1] = this->reg[this->ir->r1] - this->reg[this->ir->r2];
                (this->pc)++;
                break;
            case JMPIG:
                if(this->reg[this->ir->r2] > 0){
                    this->pc = this->reg[this->ir->r1];
                }else (this->pc)++;
                break;
            case JMP:
                this->pc = this->ir->p;
                break;
            case JMPI:
                this->pc = this->reg[this->ir->r1];
                break;
            case JMPIL:
                if(this->reg[this->ir->r2] < 0){
                    this->pc = this->reg[this->ir->r1];
                }else (this->pc)++;
                break;
            case JMPIE:
                if(this->reg[this->ir->r2] == 0){
                    this->pc = this->reg[this->ir->r1];
                }else (this->pc)++;
                break;
            case SWAP:
                int swap;
                swap = this->reg[this->ir->r1];
                this->reg[this->ir->r1] = this->reg[this->ir->r2];
                this->reg[this->ir->r2] = swap;
                (this->pc)++;
                break;
            case SUBI:
                this->reg[this->ir->r1] = this->reg[this->ir->r1] - this->ir->p;
                (this->pc)++;
                break;
            case MULT:
                this->reg[this->ir->r1] = this->reg[this->ir->r1] * this->reg[this->ir->r2];
                (this->pc)++;
                break;
            case LDD:
                this->reg[this->ir->r1] = this->m[this->ir->p]->p;
                (this->pc)++;
                break;
            // <-- Antes do STOP

            case STOP:
                break;
            default:
                break;
        }

        if(this->ir->opc == STOP) break;
    }
}