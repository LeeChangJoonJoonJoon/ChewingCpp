#define CHAR_TEST 0

//#include <iostream>
//using namespace std;
#include "CustomString.h"

int main()
{
#if CHAR_TEST
    const char* a = "fuck";
    cout << a << endl; // fuck
    cout << *a << endl; // f
    cout << a[0] << endl; // f
    cout << a[4] << endl; //  
    cout << a[5] << endl; // C

    const char b = 'f';
    cout << b << endl; // f
#endif

    CustomString a("asdf");
    CustomString b("asdf");

//    const char* b = "asdfg";
//    cout << (a.Contains(b) ? "true" : "false") << endl;

    // 둘 다 성립.

    /*
     * CustomString(const char*)
     * true
     * ~CustomString()
     */
    cout << ("asd" == a ? "true" : "false") << endl;
    /*
     * CustomString(const char*)
     * true
     * ~CustomString()
     */
    cout << (a == "asd" ? "true" : "false") << endl;

    cout << (a == b ? "true" : "false") << endl; // warning: ISO C++20 considers use of overloaded operator '==' (with operand types 'CustomString' and 'CustomString') to be ambiguous despite there being a unique best viable function


}
