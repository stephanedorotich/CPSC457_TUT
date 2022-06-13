// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <vector>
#include <unordered_map>

//  example:        FAT = {1, 2, -1, -1, 5, -1}
//      Block 0: points to Block 1
//      Block 1: points to Block 2
//      Block 2: points to NULL (i.e. last block of a file)
//      Block 3: points to NULL (i.e. last block of a file)
//      Block 4: points to Block 5
//      Block 5: points to NULL (i.e. last block of a file)
// In this example, there are 3 distinct files.
//      They have block-lengths of 3, 1 and 2 respectively.


// TASK
// Given the FAT vector, build an adjacency list for each of the nodes.
//          note: this can be done in a for loop with a single line
// Print out the number of unique files (i.e. the number of blocks that point to -1)

std::unordered_map<int, std::vector<int>> build_graph(std::vector<int> FAT) {
    std::unordered_map<int, std::vector<int>> adj_list;

    for (auto i : FAT) {
        std::cout << i << std::endl;
    }

    return adj_list;
}

