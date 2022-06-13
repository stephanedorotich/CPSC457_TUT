#include <iostream>
#include <vector>
#include <algorithm>

void print_v(std::vector<int> & v) {
    std::cout << "Vector: ";
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> someVector = {1, 5, 3, 6, 9, 10, 334, 93, 2, 18};

    print_v(someVector);

    std::sort(someVector.begin(), someVector.end()); // standard sort in "non-descending" order.

    print_v(someVector);

    return 0;
}