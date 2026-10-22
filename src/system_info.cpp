#include <cstddef>
#include <string>
#include <fstream>
#include "../include/system_info.h"
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/utsname.h>

//======uname and host_name========
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
}


//=======print======

static void print(struct utsname &x){
  std::cout << x.sysname << "\n" << x.nodename << "\n" << x.release << "\n"  << x.version << "\n"  << x.machine << "\n";
  std::cout << "host name : "; print_host_name();
  print_cpu_info();
}

void get_system_info(){
  struct utsname x;
  if(uname(&x) != 0){
      std::perror("uname");
      return;
  };
  print(x);
}
