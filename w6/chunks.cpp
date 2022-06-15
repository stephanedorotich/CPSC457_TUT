#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
#include <unistd.h>

struct Node {
    int pid;
    bool free;
    int size;
};

// ====================== BST Data Structure ====================== //



// ================== End of BST Data Structure =================== //

int main() {
    srand(time(NULL));

    std::list<struct Node> chunks;
    // Make a set to store free chunks
    // Make an unordered_map to keep track of chunks owned by processes
    
    int size, pid;
    for (int i = 0; i < 10; i++) {
        size = rand() % 1024;
        pid = rand() % 3;
        if (pid == 0) {
            // Make free chunk
        } else {
            // Make occupied chunk
        }
    }

    // Free all chunks belonging to process 1
    //  if prev chunk is free, merge
    //  if next chunk is free, merge
    //  add chunk to free_chunks


    return 0;
}
