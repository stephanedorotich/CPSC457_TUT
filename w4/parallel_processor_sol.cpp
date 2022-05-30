// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_SIZE 1024*1024

struct buffer {
    char buffer[MAX_SIZE];
    int pos = 1;
    int size = 0;
};

struct t_arg {
    struct buffer b;
    const char * filename;
    char to_match;
    int fp;
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

void * routine(void * ptr) {
    struct t_arg * f = (struct t_arg *) ptr;

    f->fp = open(f->filename, O_RDONLY);
    int n_match = 0;
    char x;
    while ((x = fast_read_one_character_from_file(f->fp, f->b)) != -1) {
        if (tolower(x) == f->to_match) n_match++;
    }

    close(f->fp);

    print_results(f->filename, f->to_match, n_match);

    return NULL;
}

int main(int argc, char ** argv) {
    if (argc != 5) usage_error(argv[0]);
    char c = argv[4][0];

    struct t_arg f[3];

    f[0].filename = argv[1];
    f[0].to_match = c;

    f[1].filename = argv[2];
    f[1].to_match = c;

    f[2].filename = argv[3];
    f[2].to_match = c;
    
    pthread_t th[3];
    // Thread create
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&th[i], NULL, &routine, &f[i]) != 0) return -1;
    }

    // Thread join
    for (int i = 0; i < 3; i++) {
        if (pthread_join(th[i], NULL) != 0) return -1;
    }

    return 0;
}