#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Process ID:\t\t" << getpid() << std::endl;
    std::cout << "Parent Process ID:\t" << getppid() << std::endl;
    std::string input;
    std::cin >> input;
    std::cout << input << std::endl;
    return 0;
}