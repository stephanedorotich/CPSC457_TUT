// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int x = 2;

int main () {
    fork();
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Process id: " << getpid() << std::endl;
    return 0;
}