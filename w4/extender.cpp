#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " src dest factor\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    // Validate args
    if (argc != 4) usage_error(argv[0]);
    long factor;
    try {
        factor = std::stoi(argv[3]);
    } catch (...) {
        usage_error(argv[0]);
    }

    // Check that file exists
    struct stat f_stat;
    if (stat(argv[1], &f_stat) != 0) usage_error(argv[0]);
    if (!S_ISREG(f_stat.st_mode)) usage_error(argv[0]);

    if (f_stat.st_size > 1024*1024*10) {
        sleep(1);
        std::cout << "Files less than 10mb please <3\n";
        sleep(2);
        std::cout << "Be nice to your processor (^-^)\n";
        sleep(2);
        exit(-1);
    }
    if (f_stat.st_size * factor > (long) 1024*1024*1024*2) {
        sleep(1);
        std::cout << "Under 2gb output please <3\n";
        sleep(2);
        std::cout << "Be nice to the servers (^-^)\n";
        sleep(2);
        exit(-1);
    }

    char ** buffer = (char **) malloc(f_stat.st_size * sizeof(char));

    int fp = open(argv[1], O_RDONLY);
    read(fp, buffer, f_stat.st_size);
    close(fp);

    fp = open(argv[2], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    for (int i = 0; i < factor; i++) {
        write(fp, buffer, f_stat.st_size);
    }
    close(fp);
    return 0;
}