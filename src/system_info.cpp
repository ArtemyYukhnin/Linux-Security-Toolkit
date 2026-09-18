#include "../include/system_info.h"
#include <iostream>
#include <sys/utsname.h>

void print(utsname &x){
  std::cout << x.sysname << "\n" << x.nodename << "\n" << x.release << "\n"  << x.version << "\n"  << x.machine << "\n";
}

void get_info(){
  utsname x;
  if(uname(&x) == -1){
    std::cout<<"Error!\n";
    return;
  };
  print(x);
}
