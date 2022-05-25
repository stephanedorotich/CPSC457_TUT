#include <iostream>
#include <dirent.h>
#include <cstdio>

int main (int argc, char ** argv) {
    if (argc != 2) return -1;

    struct dirent * dent;
    DIR * dp;

    dp = opendir(argv[1]);
    if (dp == NULL) {
        std::cout << "Can't open directory " << argv[1] << std::endl;
        return -1;
    }

    FILE * fp;
    std::string command;
    char buff[300];
    while ((dent = readdir(dp)) != NULL) {
        command.clear();
        command.append("file ");
        command.append(dent->d_name); 
        fp = popen(command.c_str(), "r");
        fgets(buff, 300, fp);
        std::cout << buff;
    }

    closedir(dp);
    return 0;
}