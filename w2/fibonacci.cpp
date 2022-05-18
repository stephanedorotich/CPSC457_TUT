#include <iostream>
#include <vector>

int main(int argc, char ** argv) {
    // Check that there are 2 arguments
    if (argc != 2) return -1;

    // Convert argv[1] to an integer n (using a Try-Catch block)
    int n;
    try {
        n = std::stoi(argv[1]);
    } catch (...) {
        return -1;
    }

    // Check that n is greater than 2
    if (n < 2) return -1;

    // Create a vector containing the first n numbers of the fibonacci sequence
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);

    for (int i = 2; i < n; i++) {
        v.push_back(v[i-2] + v[i-1]);
    }

    // Print all values from the vector
    for (auto j : v) std::cout << j << std::endl;

    return 0;
}
