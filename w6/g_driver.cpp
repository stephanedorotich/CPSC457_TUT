// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include "graph.cpp"

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " filename" << std::endl;
    exit(-1);
}

int main (int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    std::ifstream fs; // declare file stream object
    fs.open(argv[1]); // open file
    std::string str; // declare string to store lines
    std::vector<int> FAT;

    if (!fs.is_open()) usage_error(argv[0]); // check if file successfully opened
    
    // read file contents and add integers to FAT vector
    while (std::getline(fs, str)) {
        try {
            FAT.push_back(std::stoi(str));
        } catch (...) {
            std::cout << "Input file must have an integer at the beginning of every line\n";
            usage_error(argv[0]);
        }
    }
    fs.close();

    std::cout << std::endl;
    std::unordered_map<int, std::vector<int>> adj_list = build_graph(FAT);
    
    // Print out adjency list
    std::cout << std::endl;
    for (auto [key, adj] : adj_list) {
        std::cout << "Node " << key << ": ";
        for (auto i : adj) std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}

