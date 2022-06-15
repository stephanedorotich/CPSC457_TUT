#include <iostream>
#include <set>
#include <unistd.h>

int main() {
    srand(time(NULL));

    std::set<int> mySet;
    for (int i = 0; i < 10; i++) {
        mySet.insert(rand() % 1024);
    }

    for (auto i :mySet) {
        std::cout << i << std::endl;
    }

    return 0;
}