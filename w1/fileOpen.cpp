// Example 1: Opening a file using the open() system call wrapper. 
#include <iostream>
#include <unistd.h>         // read(), close()
// include following 3 for open, openat, creat
#include <sys/types.h>   
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

// define macros  NOTE: there's no semi colon
#define BUFFER_SIZE 1024

int main() {

    string input;
    cin >> input;

    // Const keyword in C++:
    // This means that the pointer is pointing to a const variable
    // Convert a string to a char* - use method c_str() to get C string version
    const char* pathname = input.c_str();

    // open an existing file
    int fd = open(pathname, O_RDONLY);

    char buffer[BUFFER_SIZE];
    if (read(fd, buffer, BUFFER_SIZE) > 0)
    {
        // read stuff, print it screen 
        string s(buffer);
        cout << s << endl;
    }
    else
        cout << "Couldn't read anything" << endl;
    
    close(fd);      // Always close the file!!

    return 0;
}