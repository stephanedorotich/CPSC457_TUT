#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_DIGITS 5

int main () {
    system("g++ -Wall -o fib fibonacci.cpp");
    FILE * fp = popen("./fib 13", "r");
    char num[13][MAX_DIGITS];

    // Get all lines of output of ./fib and save to num array
    for (int i = 0; i < 13; i++) {
        fgets(num[i], MAX_DIGITS-1, fp);
    }
    // num[12][strlen(num[12])] = '\n';

    // Print the array backwards
    for (int i = 13; i > 0; i--) {
        std::cout << num[i];
    }
    return 0;
}