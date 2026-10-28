#include "../include/system_info.h"
#include "../include/process_info.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    if (argc==1) {
        std::cout << "Use:\t" << argv[0] << "\n\tsystem\n\tprocesses";
        return 1;
    }
    if(std::strcmp(argv[1], "system")==0){
        print();
    }
    else if(std::strcmp(argv[1], "processes")==0)
    {
        get_pid_info();
    }
    else {
        std::cout << "No such command: " << argv[1] << "\n";
    }
    return 0;
}
