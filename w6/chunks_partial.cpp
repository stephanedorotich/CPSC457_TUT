#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
#include <unistd.h>

struct Node {
    int pid; // -1 free
    bool free;
    int size;
};


// ====================== BST Data Structure ====================== //
using LI = std::list<struct Node>::iterator;

bool cmp(const LI & a, const LI & b) {
    if (a->size == b->size) return a->pid <= b->pid;
    return a->size > b->size;
}

#define SN std::set<std::list<struct Node>::iterator, decltype(&cmp)>

void print_set(SN & set) {
    std::cout << "Free Chunks:\n";
    for (auto n : set) {
        std::cout << "Node " << n->pid << ": " << n->size << std::endl;
    }
}
// ================== End of BST Data Structure =================== //


int main() {
    srand(time(NULL));

    std::list<struct Node> chunks;
    // Make an unordered_map to keep track of chunks owned by processes
    std::unordered_map<int, std::vector<std::list<struct Node>::iterator>> pro_chunks;
    // Make a set to store free chunks
    SN free_chunks(&cmp);
    
    int size, pid;
    for (int i = 0; i < 10; i++) {
        size = rand() % 1024;
        pid = rand() % 3;
        if (pid == 0) {
            // Make free chunk
            chunks.push_back(Node{-1, true, size});
            free_chunks.insert(std::prev(chunks.end()));
        } else {
            // Make occupied chunk
            chunks.push_back(Node{pid, false, size});
            pro_chunks[pid].push_back(std::prev(chunks.end()));
        }
    }

    std::cout << "Process 1 chunks\n";
    for (auto n : pro_chunks[1]) {
        std::cout << "Node " << n->pid << ": " << n->size << std::endl;
    }

    std::cout << "Process 2 chunks\n";
    for (auto n : pro_chunks[2]) {
        std::cout << "Node " << n->pid << ": " << n->size << std::endl;
    }

    print_set(free_chunks);

    // Free all chunks belonging to process 1
    //  if prev chunk is free, merge
    //  if next chunk is free, merge
    //  add chunk to free_chunks

    return 0;
}
