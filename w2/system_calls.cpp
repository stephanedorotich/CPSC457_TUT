// Author: Stéphane Dorotich
// CPSC457 - Spring 2022
// Use freely

#include <stdlib.h>

int main() {
    system("wc -m story.txt");
    system("du -h --max-depth=1 ~/");
    system("seq 5");
    system("ls -l");
    system("g++ -Wall -o fib fibonacci.cpp");
    system("./fib 13");
}