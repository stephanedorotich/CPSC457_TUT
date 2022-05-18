#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv) {
    std::cout << "Process Starting...\nID:\t\t" << getpid() << std::endl;

    system("g++ -Wall -o fib fibonacci.cpp");
    const char *arg1 = "13";
    execlp("./fib", "./fib", arg1, NULL);

    std::cout << "Process Finishing...\nID:\t\t" << getpid() << std::endl;

    return 0;
}