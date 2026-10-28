#include <filesystem>
#include <iostream>
#include <string>
#include "../include/process_info.h"
#include <fstream>
#include <cctype>

//=======pid info========
//get info from dir /proc
void get_pid_info(){
    const std::filesystem::path f{"/proc"};

    for(const std::filesystem::path &dir: std::filesystem::directory_iterator(f)){
        std::string name = dir.filename();
        bool number = true;
        for(char i: name) //func that find only pid dir
        {

            if(!std::isdigit(i))
            {
                number = false;
                break;
            }
        }


        if(number){
            std::ifstream path;
            path.open(dir / "status");

            if(!path){
                std::cout<< "File is opened with error\n";
                continue;
            }

            std::string namePid;
            std::string PPid;
            std::string state;

            std::string tmp;
            while(std::getline(path, tmp)){ //get pid name from pid/status

                size_t n = tmp.find("Name:");
                size_t p = tmp.find("PPid:");
                size_t s = tmp.find("State:");

                if(n == std::string::npos and p == std::string::npos and s == std::string::npos){
                    continue;
                }
                size_t skip = tmp.find(":")+2;

                if(n != std::string::npos){
                    namePid = tmp.substr(skip);
                }

                if(p != std::string::npos){
                    PPid = tmp.substr(skip);
                }

                if (s != std::string::npos) {
                    state = tmp.substr(skip);
                }
            }

            std::cout << "Pid: " << name << " | " << "Name: " << namePid << " | " <<
                "PPid: " << PPid << " | " << "State: " << state << "\n";
            std::cout <<  "\n";
            path.close();
        }

    }
}
