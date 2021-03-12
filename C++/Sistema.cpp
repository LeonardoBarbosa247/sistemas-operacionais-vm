#include "Sistema.hpp"


Sistema::Sistema(){
    this->vm = new Vm();
    this->sOpcode = {
        {"DATA", DATA}, {"___", ___},
        {"JMP", JMP}, {"JMPI", JMPI}, {"JMPIG", JMPIG}, {"JMPIL", JMPIL}, {"JMPIE", JMPIE},
        {"JMPIM",JMPIM}, {"JMPIGM", JMPIGM}, {"JMPILM", JMPILM}, {"JMPIEM", JMPIEM}, {"JMPIEM", JMPIEM}, {"STOP", STOP},
        {"ADDI", ADDI}, {"SUBI", SUBI}, {"ADD", ADD}, {"SUB", SUB}, {"MULT", MULT},
        {"LDI", LDI}, {"LDD", LDD}, {"STD", STD}, {"LDX", LDX}, {"STX", STX}, {"SWAP", SWAP}
    };
}

std::vector<std::string> Sistema::split(std::string line, char c)
{
    using namespace std;

    vector<string> s;
    string ss;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != c and line[i] != ' ')  ss += line[i];
        else
        {
            if (ss != "" and ss != " ") s.push_back(ss);
            ss.clear();
        }
    }
    s.push_back(ss);
    return s;
}

void Sistema::run(std::string input, std::string output){
    using namespace std;
    namespace fs = std::filesystem;
    
    if(output == " "){
        output = "./programs/out-";
        output += fs::path(input).filename();
    }

    Aux* aux = new Aux();
    vector<Word*> p;

    fstream file;
    file.open(input, ios::in);
    if(file.is_open()){
        string line;
        cout << "aqui" << endl;
        while(getline(file, line)){
            vector<string> res = split(line, ',');
            p.push_back(new Word(sOpcode[res[0]], stoi(res[1]), stoi(res[2]), stoi(res[3])));
        }
    }

    aux->carga(p, vm->m);
    vm->cpu->setContext(0);
    cout << "---------------------------------- programa carregado" << endl; 
    cout << aux->dump(vm->m, 0, 15);
    cout << "---------------------------------- após execucao " << endl;
    vm->cpu->run();
    cout << aux->dump(vm->m, 0, 15);
}

// void Sistema::test1(){
//     using namespace std;

//     Aux* aux = new Aux();
    
//     vector<Word*> p;

//     p.push_back(new Word(LDI, 0, -1, 999));
//     p.push_back(new Word(STD, 0, -1, 10));
//     p.push_back(new Word(STD, 0, -1, 11));
//     p.push_back(new Word(STD, 0, -1, 12));
//     p.push_back(new Word(STD, 0, -1, 13));
//     p.push_back(new Word(STD, 0, -1, 14));
//     p.push_back(new Word(STOP, -1, -1, -1));

//     aux->carga(p, vm->m);
//     vm->cpu->setContext(0);
//     cout << "---------------------------------- programa carregado" << endl; 
//     aux->dump(vm->m, 0, 15);
//     cout << "---------------------------------- após execucao " << endl;
//     vm->cpu->run();
//     aux->dump(vm->m, 0, 15);
// }