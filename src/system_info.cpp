#include <cctype>
#include <csignal>
#include <cstddef>
#include <string>
#include <fstream>
#include "../include/system_info.h"
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/utsname.h>


//======system info=======
//get struct where is os info

static void get_system_info(){
    struct utsname x;
    if(uname(&x) != 0){
        std::perror("uname");
        return;
    };
    std::cout << x.sysname << "\n" << x.nodename << "\n" << x.release << "\n"  << x.version << "\n"  << x.machine << "\n";
}


//==========host name=============
//gethostname return os name to char[]

static void print_host_name(){
    char name[30];
    name[29] = '\0';
    if(gethostname(name, 30) != 0){
        std::perror("host_name");
        return;
    }
    std::cout << name << "\n";
}

//========proc info=======
//get info from dir /proc

static void print_cpu_info(){
    std::ifstream f;
    f.open("/proc/cpuinfo");

    if(!f){
        std::cout << "File is opened with error\n";
        return ;
    }

    std::string tmp;
    while(std::getline(f, tmp)){
        size_t n = tmp.find("model name");
        if(n == std::string::npos){
           continue;
        }
        size_t skip = tmp.find(":");
        std::cout<<tmp.substr(skip+2) << '\n';
        break;
    }
    f.close();
}


//=========print=========
//use in main.cpp

void print(){
    get_system_info();
    std::cout << "host name : "; print_host_name();
    print_cpu_info();
}
