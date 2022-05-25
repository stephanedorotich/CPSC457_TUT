// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    // Unordered map
    std::unordered_map<std::string,std::vector<std::string>> duplicate_files;

    const char * h1 = "hash1";
    const char * h2 = "hash2";

    const char * f1 = "filename1";
    const char * f2 = "filename2";
    const char * f3 = "dup_file2";

    duplicate_files[h1].push_back(f1);
    duplicate_files[h2].push_back(f2);
    duplicate_files[h2].push_back(f3);

    int i = 0;
    for (auto [key, v]: duplicate_files) {
        std::cout << "Group " << ++i << std::endl;
        for (auto k : v) {
            std::cout << "\t" << k << std::endl;
        }
    }
    return 0;
}