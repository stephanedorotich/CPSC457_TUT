// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

// Modify this program so that it processes the 3 files in parallel.
//  -   Create 3 threads
//  -   Let each thread count up the number of occurences of the specified
//      character in their respective files.

// Time your results using ``time -p`` to ensure it is faster than serial_processor

// Challenge 1:
//      Use stat to verify the existence of 

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_SIZE 1024

struct buffer {
    char buffer[MAX_SIZE];
    int pos;
    int size;
};

// returns the next char from stdin, or -1 on EOF
// returns characters stored in buffer[] until it is empty
// when buffer[] gets empty, it is replenished by calling read()
int
fast_read_one_character_from_file(int fp, struct buffer & b)
{
  // check if buffer[] is empty
  if( b.pos >= b.size) {
    // buffer is empty, let's replenish it
    b.size = read( fp, b.buffer, sizeof(b.buffer));
    // detect EOF
    if(b.size <= 0) return -1;
    // reset position from where we'll return characters
    b.pos = 0;
  }
  // return the next character from the buffer and update position
  return b.buffer[b.pos++];
}

void print_results(const char * file, char c, int num_occ) {
    std::cout << "File: " << file << std::endl;
    std::cout << "\tCharacter <" << c << "> occured " << num_occ << " times.\n";
    return;
}

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " file1 file2 file3 char\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 5) usage_error(argv[0]);
    char c = tolower(argv[4][0]);

    int f1, f2, f3;

    f1 = open(argv[1], O_RDONLY);
    f2 = open(argv[2], O_RDONLY);
    f3 = open(argv[3], O_RDONLY);

    struct buffer b1;
    b1.pos = 1;
    b1.size = 0;

    int n_match_f1 = 0;
    int n_match_f2 = 0;
    int n_match_f3 = 0;

    char x;
    
    while ((x = fast_read_one_character_from_file(f1, b1)) != -1) {
        if (x == c) n_match_f1++;
    }
    while ((x = fast_read_one_character_from_file(f2, b1)) != -1) {
        if (x == c) n_match_f2++;
    }
    while ((x = fast_read_one_character_from_file(f3, b1)) != -1) {
        if (x == c) n_match_f3++;
    }

    close(f1);
    close(f2);
    close(f3);

    print_results(argv[1], c, n_match_f1);
    print_results(argv[2], c, n_match_f2);
    print_results(argv[3], c, n_match_f3);

    return 0;
}
