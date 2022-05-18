#include <cstdio>
#include <iostream>

int main () {
    FILE * fp = popen("ls -l", "r");

    char buffer[300];

    std::cout << "Writing stuff here\n";
    while (fgets(buffer, 300, fp) != NULL) {
        std::cout << buffer;
    }

    pclose(fp);
}