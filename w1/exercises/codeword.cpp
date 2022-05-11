#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    const string codeword = "cpsc457";
    
    // Mini exercise: add error handling to ensure exactly 1 input. 

    string input = argv[1];

    if (input.compare(codeword) == 0) {
        cout << "You've found the codeword!\n";
    } else {
        cout << "Wrong keyword...\n";
    }
    return 0;
}