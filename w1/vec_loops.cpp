// 3 different ways of looping through a vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> my_vec = {"first", "second", "last"};

    //  1)  Loop by making a copy of each element in vector.
    //      Copy made is by value. Changes to the copy do not change the original element. 
    for (string s: my_vec)
    {
        s = s + "_copy";
        cout << s << endl;
    }

    //  2)  Loop by making s read-only using keyword const.
    //      s is still a copy of the elements in my_vec.
    for (const string s: my_vec)
    {
        s = s + "_copy";
        cout << s << endl;
    }

    // 3) pass by reference. keyword 'auto' allows compiler to deduce the type of s to be of type string. If you change the vector type from string (line 9) to, say int, then this loop will still work whereas the previous two should result in an error. 
    for (const auto &s: my_vec)
    {
        cout << s << endl;
    }
}