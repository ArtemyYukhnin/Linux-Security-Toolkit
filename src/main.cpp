#include "../include/system_info.h"
#include "../include/process_info.h"
#include "../include/file_security.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    if (argc==1) {
        std::cout << "Use:\n\t" << argv[0] << "\tsystem\n\t" << argv[0]  << "\tprocesses\n\t" << argv[0] << "\tcheck-file\tfile";
        return 1;
    }
    if(std::strcmp(argv[1], "system")==0){
        print();
    }
    else if(std::strcmp(argv[1], "processes")==0)
    {
        get_pid_info();
    }
    else if(std::strcmp(argv[1], "check-file")==0)
    {
        if(argc==2){
            std::cout << "Use:\n\t" << argv[0] << "\tcheck-file\tfile";
            return 1;
        }
        check_file(argv[2]);
    }
    else {
        std::cout << "No such command: " << argv[1] << "\n";
        return 1;
    }
    return 0;
}
