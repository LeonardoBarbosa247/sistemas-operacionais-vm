#ifndef Sistema_hpp
#define Sistema_hpp

#include <vector>
#include <iostream>
// #include <filesystem>
#include <fstream>

#include "Vm.hpp"
#include "Aux.hpp"
#include "Word.hpp"

class Sistema
{
    private:
        Vm* vm;
        std::vector<std::string> split(std::string line, char c);
        std::map<std::string, Opcode> sOpcode;
    public:
        Sistema();
        void run(std::string input, std::string output = " ");
        // void test1();
        // void test2();
};

#endif