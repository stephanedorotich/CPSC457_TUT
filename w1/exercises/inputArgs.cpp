// Print out the number of command line arguments
// Print out each command line argument
// Author: Xining Chen
#include <iostream>


int main(int argc, char* argv[])
{
    cout << "Number of arguments: " << endl;
    cout << "argv contains: " << endl;

    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "] = " << 0 << endl;
    }

    return 0;
}