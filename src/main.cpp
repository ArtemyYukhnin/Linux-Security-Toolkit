#include "../include/system_info.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    if (argc==1) {
        std::cout << "Use:\t" << argv[0] << " args\n";
        return -1;
    }
    if(std::strcmp(argv[1], "system")==0){
        get_system_info();
    }
    else {
        std::cout << "No such command: " << argv[1] << "\n";
    }
    return 0;
}
