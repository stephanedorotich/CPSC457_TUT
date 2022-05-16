#include <iostream>
#include <sys/stat.h>
#include <bitset>

int main(int argc, char ** argv) {
    struct stat s;
    if (argc != 2) return -1;
    if (*argv[1] == 'd') {
        stat("./", &s);
        std::cout << "PROJECT DIRECTORY\n";
    } else if (*argv[1] == 'e') {
        stat("exercises/../", &s);
        std::cout << "PROJECT DIRECTORY\n";
    } else if (*argv[1] == 'f') {
        stat("./system_calls.cpp", &s);
        std::cout << "FILE: system_calls.cpp\n";
    } else return -1;

    // std::bitset<16> d_ftype(dir.st_mode);
    // std::cout << d_ftype << std::endl;
    // std::bitset<16> f_ftype(file.st_mode);
    // std::cout << f_ftype << std::endl;

    // Finding out if the pathname is a directory or regular file
    std::cout << "\nIs it a Directory or a file?\n";
    std::cout << "Is dir:\t" << S_ISDIR(s.st_mode) << std::endl;
    std::cout << "Is reg:\t" << S_ISREG(s.st_mode) << std::endl;

    // What is the file's Inode number?
    std::cout << "\nWhat is the file's Inode number?\n";
    std::cout << "Inode:\t" << s.st_ino << std::endl;

    // On what device does this file reside?
    std::cout << "\nOn what device does this file exist?\n";
    std::cout << "Device:\t" << s.st_dev << std::endl;

    // How many hardlinks to the file?
    std::cout << "\nHow many hard links point to the file?\n";
    std::cout << "Links:\t" << s.st_nlink << std::endl;
}