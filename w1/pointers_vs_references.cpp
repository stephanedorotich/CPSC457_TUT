// Author: Stéphane Dorotich
// CPSC457 - Spring 2022

#include <iostream>

using namespace std;

int main() {
    // Declaring and initializing local variables
    int n;
    n = 5;
    string s = "This is an array of characters.";

    cout << "n is:\t\t\t" << n << endl;
    cout << "s is:\t\t\t" << s << endl;

    cout << "the address of n is:\t" << &n << endl;
    cout << "the address of s is:\t" << &s << endl;

    // Creating a reference to an initialized variable
    int & r = n; // r now refers to n.
    cout << "r is:\t\t\t" << r << endl;

    // Note a reference MUST be refer to a VARIABLE when it is created
    // It cannot be only declared. The following lines both cause errors
    // int & r1 = 7;
    // int & r2;

    n = 17; // change n, since r refers to n it notices the change
    cout << "r is:\t\t\t" << r << endl;

    r = 1337; // change r, since it refers to n, n is what changes
    cout << "n is:\t\t\t" << n << endl;

    // References CANNOT be changed after they are initialized
    // int newNumber = 0;
    // r = &newNumber;

    // Declaring and initializing a pointer
    int * p;
    p = &n;
    // Pointers can only point to members of their type. The following line causes an error
    // p = &s

    cout << endl << "p is:\t\t\t" << p << endl;
    cout << "p points to:\t\t" << *p << endl;

    // A pointer can be used to modify change what it references
    *p = 100;
    cout << "n is:\t\t\t" << n << endl;

    // std::string can be treated as an array.
    cout << "s is:\t\t\t" << s << endl;
    cout << "the 0th char of s is:\t" << s[0] << endl;
    cout << "the 1st char of s is:\t" << s[1] << endl;
    cout << "the 2nd char of s is:\t" << s[2] << endl;
    cout << "the 3rd char of s is:\t" << s[2] << endl;

    // You can point to characters inside of a string!
    char * c = &s[2];
    *c = '@';
    cout << "s is:\t\t\t" << s << endl;
}