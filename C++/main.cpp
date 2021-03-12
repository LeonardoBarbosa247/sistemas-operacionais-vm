#include "Sistema.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv){
    Sistema* s = new Sistema();
    
    if(argc == 1){
        cout << "input file undefined" << endl;
        return 1;
    } 

    s->run(argv[1], argc > 2 ? argv[2] : " ");
    return 0;
}


