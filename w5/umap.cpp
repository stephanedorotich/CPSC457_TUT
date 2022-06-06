#include <iostream>
#include <unordered_map>

int main() {
    // std::unordered_map< ___key___, ___value___ >;
    // composed of <key,value> pairs.
    std::unordered_map<int, std::string> umap;

    // Adding new values
    umap[13] = "A word";
    umap[77] = "Some string";
    umap[399] = "three hundred and ninety nine";

    // Iterating through map v1
    std::cout << "Print umap version 1:\n";
    for (auto a : umap) {
        std::cout << "<" << a.first << ", " << a.second << ">" << std::endl;
    }

    // Iterating through map v2
    std::cout << "\nPrint umap version 2:\n";
    for (auto [key, val] : umap) {
        std::cout << "<" << key << ", " << val << ">" << std::endl;
    }

    // Checking key
    std::cout << "\nUmap contains key 77: " << umap.count(77) << std::endl;
    std::cout << "Umap contains key 100: " << umap.count(100) << std::endl;

    // Getting value stored at key
    std::cout << "\nValue stored with key 399: " << umap[399] << std::endl;
    // NOTE: If key does not exist, then this call CREATES key in map
    std::cout << "\nSize:\t\t\t" << umap.size() << std::endl;
    umap[100];
    std::cout << "Size after `umap[100]`:\t" << umap.size() << std::endl;
    return 0;
}