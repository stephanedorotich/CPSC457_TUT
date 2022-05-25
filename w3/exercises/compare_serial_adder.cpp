// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <unistd.h>
#include <vector>

int main(int argc, char ** argv) {
    if (argc != 2) return -1;
    int x;
    try {
        x = std::stoi(argv[1]);
    } catch (...) {
        return -1;
    }

    std::vector<int> v;
    for (int i = 1; i <= x; i++) {
        v.push_back(i);
    }

    uint64_t sum = 0;

    for (auto j : v) {
        sum+=j;
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}