// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>

// Write a program that:
//      - Creates two different threads
//      - One thread increments x for every even number from 1 to 100 (inclusive)
//      - One thread decrements x for every multiple of 3 from 1 to 100 (inclusive)

// Expected result:
//  from 1-100:     Value of x: 17
//  from 1-10k:     Value of x: 1667
//  from 1-10M:     Value of x: 1666667

// Question 1:
//      - Time your code with an upper bound of 10M.
//      - Time the compare program.
// Why is there such a big difference?

// Challenge 1:
//      Use a command line argument as the upper bound instead of
//      a static number.

int x = 0;

int main() {
    std::cout << "Value of x: " << x << std::endl;
    return 0;
}