// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>

int x = 0;
int main() {
    for (int i = 1; i <= 10000000; i++) {
        if (i%2 == 0) x++;
        if (i%3 == 0) x--;
    }

    std::cout << "Value of x: " << x << std::endl;
    return 0;
}