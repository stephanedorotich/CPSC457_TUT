// Author: Stéphane Dorotich
// CPSC457 - Spring 2022
// Use freely

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <algorithm>
#include <cstring> 

void example_1() {
    int pid = fork();

    if (pid == -1) {
        std::cout << "Error creating fork!\n";
    } else if (pid == 0) {
        std::cout << "Child Process\n";
    } else {
        std::cout << "Parent Process\n";
    }
}

void example_2() {
    std::cout << "A\n";
    fork();
    std::cout << "B\n";
    fork();
    std::cout << "C\n";
}

void example_3() {
    for (int i = 0; i < 4; i++) {
        fork();
    }
    std::cout << "X\n";
}

void example_4() {
    int pid;
    for (int i = 0; i < 4; i++) {
        pid = fork();
    }

    if (pid == -1) std::cout << "Error creating fork!\n";
    if (pid == 0) {
        std::cout << "C\n";
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
        std::cout << "P\n";
    }
}

void example_5() {
    int fd[2];
    // fd[0] - read
    // fd[1] - write
    if (pipe(fd) == -1) {
        std::cout << "An error occured opening the pipe\n";
        exit(-1);
    }

    int pid = fork();
    if (pid == -1) return;
    if (pid == 0) {
        close(fd[0]);
        // Get name
        std::cout << "Please enter your name:\t";
        std::string name;
        std::cin >> name;
        name.push_back('\0');   // Adding null char to string

        // write(file, buffer, num_bytes)
        write(fd[1], name.c_str(), name.size());    // Writing c_str to pipe
        close(fd[1]);
    } else {
        close(fd[1]);
        char name[100];
        read(fd[0], name, 100);
        close(fd[0]);
        // Reverse name
        std::reverse(name, name + strlen(name));
        std::cout << "Your name backwards is:\t" << name << std::endl << std::endl;
    }
}

void example_6 () {
    int ppid = getpid();

    int pid = fork();

    if (pid == -1) {
        return;
    } else if (pid == 0) {
        waitpid(ppid, NULL, 0);
        std::cout << "Child\n";
    } else {
        std::cout << "Parent\n";
    }
}

int main(int argc, char ** argv) {
    if (argc !=2) return -1;
    int ex;
    try {
        ex = std::stoi(argv[1]);
    } catch (...) {
        std::cout << "Usage:\n\t./fork example_number\n";
        return -1;
    }

    switch(ex) {
        case 1:
            example_1();
            break;
        case 2:
            example_2();
            break;
        case 3:
            example_3();
            break;
        case 4:
            example_4();
            break;
        case 5:
            example_5();
            break;
        case 6:
            example_6();
            break;
        default:
            std::cout << "Usage:\n\t./fork example_number (1 to 5)\n";
    }

    return 0;
}