// Example of a basic template function 
// Source: www.cplusplus.com/doc/oldtutorial/templates/
#include <iostream>

using namespace std;

// Template function 
// What is T?
// What is the return type of getMax?
// What is the input type of getMax?
template <class T> T getMax (T a, T b) {
    if (a > b) {
        return a;
    } else return b;
}

int main() {
    int i = 5, j = 6, k;
    long l = 10, m = 5, n;

    // What is <int> vs <long> ?
    k = getMax<int>(i,j);
    n = getMax<long>(l,m);

    cout << k << endl;
    cout << n << endl;
    
    return 0;
}
