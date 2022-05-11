// Author: Stéphane Dorotich
// CPSC457 - Spring 2022

#include <iostream>

using namespace std;

// Global variable
int val = 400;

int main () {
    // val is a Global variable
    cout << "Global val:\t" << val << endl;
    
    // r now refers to the global variable
    int & r = val;

    // Local variable
    int val = 794;

    // val is now a Local variable
    cout << "Local val:\t" << val << endl;

    // r still refers to the global variable
    cout << "r val is:\t" << r << endl;
}