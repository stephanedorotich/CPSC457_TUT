// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>

struct Graph {
    std::unordered_map<std::string, std::vector<std::string>> adj_list;
    std::unordered_map<std::string, int> out_counts;
};

std::vector<std::string> detect_cycle(struct Graph & g) {
    std::vector<std::string> zero_outs; // Nodes that have no outgoing edges
    std::vector<std::string> cycle; // Nodes that are part of a cycle

    // Start by copying the counts of outgoing edges.
    // We will be modifying these counts, which is why we need to copy them
    // std::unordered_map<std::string, int> counts_cp = g.out_counts;


    // Iterate through counts_cp and add to zero_outs
    // all nodes whose outgoing count is 0.


    // While zero_outs is not empty, pop one element from the list
    // we will simulate "removing" this node from the graph by:
    //    - iterating through the adjacency list of this node and decrementing
    //      their outgoing count in counts_cp.
    //    - if counts_cp is 0, add the node to zero_nodes.


    // Finally, iterate through all values in counts_cp
    // if any node does not have an outgoing count of 0, add it to
    // the cycle. They are part of the deadlock.

    return cycle;
}

void populate_graph(struct Graph & g) {
    std::string s1, s2;
    bool done = false;

    std::cout << "Edge format: \"src dst\"\n";
    std::cout << "type \"done\" when complete\n";
    
    while(!done) {
        std::cout << "Edge: ";
        std::cin >> s1; // get src node
        if (s1.compare("done") == 0) break; // check if "done"
        std::cin >> s2; // get dst node

        // add src node to dst node's adjacency list
        g.adj_list[s2].push_back(s1);
        
        // if node is new, add it to out_counts
        if (g.out_counts.count(s1) == 0) g.out_counts[s1] = 0;
        if (g.out_counts.count(s2) == 0) g.out_counts[s2] = 0;

        // increment out_count of src node
        g.out_counts[s1]++;
    }
}

void print_graph(struct Graph & g) {
    std::cout << "================== GRAPH ==================\n";
    for (auto [key, vector] : g.adj_list) {
        std::cout << key << ": ";
        for (auto val : vector) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "================ OUT COUNTS ===============\n";
    for (auto [key, count] : g.out_counts) {
        std::cout << key << ": " << count << std::endl; 
    }
    std::cout << "===========================================\n";
}

int main() {
    struct Graph g;

    populate_graph(g);

    print_graph(g);

    std::vector<std::string> cycle = detect_cycle(g);
    if (cycle.size() != 0) {
        std::cout << "Cycle detected!\n";
        std::cout << "Nodes: ";
        for (auto i : cycle) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No cycle detected :)\n";
    }

    return 0;
}