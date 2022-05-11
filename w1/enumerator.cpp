// enumeration 
#include <iostream>

using namespace std;

enum Color 
{
    red,
    green, 
    blue=31, 
    purple, 
    indigo,
};

int main()
{
    Color val = indigo;

    switch (val)
    {
        case red  : 
            cout << "red\n";   
            break;
        case green: 
            cout << "green\n"; 
            break;
        case blue : 
            cout << "blue\n"; 
            break;
        case purple: 
            cout << "purple\n"; 
            break;
        case indigo:
            cout << "indigo\n"; 
            break;
        default:
            cout << "colorless\n";
    }
    
    int r = red;
    int g = green;
    int b = blue;
    int p = purple;
    int i = indigo;

    cout << "Red is:\t\t" << r << endl;
    cout << "Green is:\t" << g << endl;
    cout << "Blue is:\t" << b << endl;
    cout << "Purple is:\t" << p << endl;
    cout << "Indigo is:\t" << i << endl;
}