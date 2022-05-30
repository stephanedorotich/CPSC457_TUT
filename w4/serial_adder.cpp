// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <unistd.h>
#include <vector>

// Design a multithreaded approach to summing a vector of numbers.
// Create at least 4 threads.
// For example if you have 4 threads:
//      t1 sums: v[0], v[4], v[8], ...
//      t2 sums: v[1], v[5], v[9], ...
//      t3 sums: v[2], v[6], v[10], ...
//      t4 sums: v[3], v[7], v[11], ...

// Question:
// - Use "time -p" to time your code with 4 threads and 100000000 numbers.
// - How does it compare to compare_seq_adder.cpp?

// Challenge 1:
// - Use any number of threads (based on program arguments)


// Data structure to pass values into your threads
struct th_data { 
    std::vector<int> * v;
    int offset;
    int incr;
    uint64_t sum;
};

// MODIFY THIS FUNCTION
uint64_t add(std::vector<int> & v) {
    uint64_t sum = 0;
    for (auto j : v) {
        sum+=j;
    }
    return sum;
}


int main(int argc, char ** argv) {
    // Ensure 1 arg is given
    if (argc != 2) {
        std::cout << "Usage:\n\t./seq x\n";
        return -1;
    }

    // Try initializing x
    uint64_t x;
    try {
        x = (uint64_t) std::stoi(argv[1]);
    } catch (...) {
        std::cout << "Usage:\n\t./seq num_threads x\n";
        return -1;
    }

    // Populate vector with x numbers
    std::vector<int> v;
    for (uint64_t i = 1; i <= x; i++) {
        v.push_back(i);
    }

    uint64_t sum = add(v);

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}