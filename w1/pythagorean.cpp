// pass by reference using pointers and cmath
#include <iostream>
#include <cmath>

using namespace std;

// pass by value
double pyth(double a, double b)
{
    double c = sqrt(pow(a, 2) + pow(b,2));
    a = 0;
    b = 0;
    return c;
}

// pass by reference 
double pyth2(double & a, double & b)
{
    double c = sqrt(pow(a, 2) + pow(b,2));
    a = 0;
    b = 0;
    return c;
}


int main(int argc, char* argv[])
{
    double v1 = stod(argv[1]);     // convert string to double
    double v2 = stod(argv[2]);

    // pass by value
    double v3 = pyth(v1, v2);
    cout << "a = " << & v1 << " ; b = " << & v2 << " ; c = " << v3 << endl;

    // pass by reference
    double v4 = pyth2(v1, v2);
    cout << "a = " << v1 << " ; b = " << v2 << " ; c = " << v4 << endl;

    return 0;
}
