#include "../include/file_security.h"
#include <cstdio>
#include <sys/stat.h>
#include <iostream>

void check_file(const char* path){
    struct stat sb;
    if(lstat(path, &sb) == -1){
        std::perror("check file");
        return;
    }

    std::cout << "File: " << path << "\n";
    std::cout << "Type: ";

    if(S_ISREG(sb.st_mode)){
        std::cout << "regular file"  << "\n";
    }
    else if(S_ISDIR(sb.st_mode)){
        std::cout << "directory" << "\n";
    }
    else if(S_ISLNK(sb.st_mode))
    {
        std::cout << "symbolic link" << "\n";
    }
    else if(S_ISCHR(sb.st_mode))
    {
        std::cout << "character device" << "\n";
    }
    else {
        std::cout << "unknown type" << "\n";
    }
    std::cout << "Permissions: " << std::oct << (sb.st_mode & 0777) << std::dec << "\n";

    std::cout << "Owner UID: " << sb.st_uid << "\n";
    std::cout << "Group GID: " << sb.st_gid << "\n";
}
