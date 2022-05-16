// Author: Stéphane Dorotich
// CPSC457 - Spring 2022
// Use freely
#include <iostream>
#include <fcntl.h>      // for sys open
#include <unistd.h>     // for sys open
#include <stdio.h>      // for c open
#include <fstream>      // for c++ open
#include <bitset>

#define BUFF_SIZE 1000

void usage_error() {
    std::cout << "Usage:\n\t./IO version_number\t\t(where 0 < version_number < 3)\n";
    exit(-1);
}

void sys_open() {
    // man open
    char buffer[BUFF_SIZE];
    int fd = open("story.txt", O_RDONLY);
    int num_bytes = read(fd, buffer, BUFF_SIZE);
    close(fd);
    fd = open("copy.txt", O_WRONLY | O_CREAT);
    write(fd, buffer, num_bytes);
    close(fd);
}

void clib_open() {
    // man fopen
    char buffer[BUFF_SIZE];
    FILE * fd = fopen("story.txt","r");
    int num_bytes = fread(buffer, 1, BUFF_SIZE, fd);
    fclose(fd);
    fd = fopen("copy.txt", "w");
    fwrite(buffer, 1, num_bytes, fd);
    fclose(fd);
}

void stream_open() {
    char buffer[BUFF_SIZE];
    std::ifstream f;
    f.open("story.txt");
    f.read(buffer, BUFF_SIZE);
    f.close();

    std::ofstream o;
    o.open("copy.txt");
    o << buffer;
    o.close();
}

void sys_flags() {
    // For a full list of open flags, refer to "man 2 open"
    std::bitset<8> read_only(O_RDONLY);
    std::bitset<8> write_only(O_WRONLY);
    std::bitset<8> read_write(O_RDWR);
    std::bitset<8> create(O_CREAT);
    std::cout << "Read only:\t" << read_only << std::endl;
    std::cout << "Write only:\t" << write_only << std::endl;
    std::cout << "Read & Write:\t" << read_write << std::endl;
    std::cout << "Create File:\t" << create << std::endl;
}

int main(int argc, char**argv) {
    if (argc != 2) usage_error();
    int version;
    try {
        version = std::stoi(argv[1]);
        if (version < 0 || version > 3) usage_error();
        switch(version) {
            case 1:
                sys_open();
                break;
            case 2:
                clib_open();
                break;
            case 3:
                stream_open();
                break;
            case 4:
                sys_flags();
        }
    } catch (...) {
        usage_error();
    }
    return 0;
}
