// Integer types
// Author: Xining Chen

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    cout << "Minimum short = " << SHRT_MIN << endl;
    cout << "Maximum short = "<< SHRT_MAX << endl;
    cout << "Minimum int = " << SHRT_MIN;
    cout << "Maximum int = "<< SHRT_MAX << endl;
    cout << "Minimum long = " << SHRT_MIN << endl;
    cout << "Maximum long = " << SHRT_MAX << endl;

    cout << "Size of int = " << sizeof(int) << endl;
    cout << "Size of long = " << sizeof(long) << endl;
    cout << "Size of int64_t = " << sizeof(int64_t) << endl;
    cout << "Size of int32_t = " << sizeof(int32_t) << endl;
    cout << "Size of int16_t = " << sizeof(int64_t) << endl;
    cout << "Size of int8_t = " << sizeof(int64_t) << endl;
    return 0;
}
