// Author: Stéphane Dorotich
// CPSC457 - Spring 2022

#include <iostream>
#include <algorithm>

using namespace std;

// print function
void print(string s) {
    cout << s << endl;
}

namespace xyz {
    // xyz print function
    void print(string s) {
        string temp = s;
        std::reverse(temp.begin(), temp.end());
        cout << temp << endl;
    }
}

int main () {
    string s = "This is a standard string.";
    print(s);
    xyz::print(s);
}