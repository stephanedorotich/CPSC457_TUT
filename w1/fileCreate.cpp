// Example 2: Create and then open a file using the open() system call wrapper. 
#include <iostream>
#include <unistd.h>         // read(), close()
// include following 3 for open, openat, creat
#include <sys/types.h>   
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using namespace std;

#define BUFFER_SIZE 1024

int main() {

    string input;
    cin >> input;

    const char* pathname = input.c_str();

    // open a file that may not exist. 
    // Include O_CREAT in flags for the option to create if file DNE
    // must include mode flag when O_CREAT is used
    // For more status and their description: https://man7.org/linux/man-pages/man2/write.2.html
    int fd = open(pathname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR );

    char buffer[BUFFER_SIZE];
    if (read(fd, buffer, BUFFER_SIZE) > 0)
    {
        // read stuff, print it screen  
        string s(buffer);
        cout << s << endl;
    }
    else{
        string content = "Writing to a file.\n";
        content.copy(buffer, content.size()+1); // put the string into the buffer
        buffer[content.size()] = '\0'; 

        // write function: write(int fd, const void *buf, size_t count);
        // void * buf  -- pass in reference to a buffer
        // count -- write up to the count bytes from the buffer
        write(fd, & buffer, content.size());

        // Exercise:
        // 1) replace content.size() with BUFFER_SIZE. What happens?
        // 2) In line 24, remove the mode flags. Create a new file. Type ls -l. What is the mode of the newly created file?
    }
    
    close(fd);      // Always close the file!!

    return 0;
}