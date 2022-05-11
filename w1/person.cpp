// Structures in C++
#include <iostream>
#include <string> 

// for streamsize
#include <ios>

// for numeric_limits
#include <limits>

using namespace std;

struct Person
{
    string name;
    int age;
    string occupation;

    void print_info() {
        cout << "\nPersonal Info: "<< endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Occupation: " << occupation << endl;
    }
};

int main()
{
    Person p1;

    cout << "Enter person's full name: ";
    getline(cin, p1.name);

    cout << "Enter age: ";
    string age;
    getline(cin, age);
    try {
        p1.age = stoi(age);
    } catch (...) {
        return -1;
    }
    
    cout << "Enter occupation: ";
    getline(cin, p1.occupation);

    p1.print_info();

    return 0;
}