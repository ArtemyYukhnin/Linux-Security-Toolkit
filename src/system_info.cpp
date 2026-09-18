#include "../include/system_info.h"
#include <iostream>

void print(struct utsname &x){
  std::cout << x.sysname << "\n" << x.nodename << "\n" << x.release << "\n"  << x.version << "\n"  << x.machine << "\n";
}

void get_system_info(){
  struct utsname x;
  if(uname(&x) == -1){
    std::cout<<"Error!\n";
    return;
  };
  print(x);
}
