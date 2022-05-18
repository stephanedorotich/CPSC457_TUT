// Author: Stéphane Dorotich
// CPSC457 - Spring 2022
// Use freely

#include <iostream>
#include <unistd.h>
#include <cstring>

#define MAX_DIGITS 5

int main () {
    // Step 1: create a pipe

    // Step 2: fork

    // Step 3: In child process, use popen to run "../fib 13"

    // Step 4: Read the output of "../fib 13" from popen and
    //         pipe every 3rd number (starting with the 0th)
    //         to the parent process.

    // Step 5: From the parent process, print the contents of
    //         the pipe.

    // DON'T FORGET TO CLOSE ALL FOUR PIPES!! (2 in child, 2 in parent)
    
    int fd[2];
    if (pipe(fd) == -1) {
        std::cout << "Error creating pipe\n";
        return -1;
    }
    int pid = fork();
    if (pid == 0) {
        close(fd[0]);
        FILE * fp = popen("../fib 13", "r");
        char num[13][MAX_DIGITS];
        for (int i = 0; i < 13; i++) {
            fgets(num[i], MAX_DIGITS-1, fp);
            if (i%3 == 0) {
                write(fd[1], num[i], strlen(num[i]));
            }
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int num_bytes;
        char buffer[1000];
        num_bytes = read(fd[0], buffer, 1000);
        buffer[num_bytes] = '\0';
        std::cout << buffer << std::endl;
        close(fd[0]);
    }
}