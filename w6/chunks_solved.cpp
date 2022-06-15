#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
#include <unistd.h>


struct Node {
    int id;
    int pid; // -1 free
    bool free;
    int size;
};

using LI = std::list<struct Node>::iterator;

// ====================== BST Data Structure ====================== //

bool cmp(const LI & a, const LI & b) {
    if (a->size == b->size) return a->id < b->id;
    return a->size > b->size;
}
using SN = std::set<LI, decltype(&cmp)>;

// ================== End of BST Data Structure =================== //

void print_set(SN & set) {
    std::cout << "\nFree chunks\n";
    for (auto n : set) {
        std::cout << "Index " << n->id << " " << n->size << std::endl;
    }
}

int main() {
    srand(time(NULL));
    std::list<struct Node> chunks;
    // Make an unordered_map to keep track of chunks owned by processes
    std::unordered_map<int, std::vector<LI>> pro_chunks;
    // Make a set to store free chunks
    SN free_chunks(&cmp);
    
    int size, pid;
    for (int i = 0; i < 10; i++) {
        size = rand() % 1024;
        pid = rand() % 3;
        if (pid == 0) {
            // Make free chunk
            chunks.push_back(Node{i, -1, true, size});
            free_chunks.insert(std::prev(chunks.end()));
        } else {
            // Make occupied chunk
            chunks.push_back(Node{i, pid, false, size});
            pro_chunks[pid].push_back(std::prev(chunks.end()));
        }
    }
    
    std::cout << "Chunks\n";
    for (auto n : chunks) {
        std::cout << "Index " << n.id << " pid(" << n.pid << ") " << n.size << std::endl;
    }
    
    std::cout << "\nProcess 1:\n";
    for (auto n : pro_chunks[1]) {
        std::cout << "Index " << n->id << " " << n->size << std::endl;
    }
    
    print_set(free_chunks);
    // Free all chunks belonging to process 1
    //  if prev chunk is free, merge
    //  if next chunk is free, merge
    //  add chunk to free_chunks

    // iterate through all chunks belong to process
    for (auto n : pro_chunks[1]) {
        n->pid = -1;
        n->free = true;

        // check if prev is free
        if (n != chunks.begin() && std::prev(n)->free) {
            // merge
            n->size+=std::prev(n)->size;
            n->id = std::prev(n)->id;
            free_chunks.erase(std::prev(n));
            chunks.erase(std::prev(n));
        }

        // check if next is free
        if (n != std::prev(chunks.end()) && std::next(n)->free) {
            // merge
            n->size+=std::next(n)->size;
            free_chunks.erase(std::next(n));
            chunks.erase(std::next(n));
        }

        free_chunks.insert(n);
    }
    pro_chunks[1].clear();



    std::cout << "\nPost free process 1:";
    print_set(free_chunks);

    return 0;
}
