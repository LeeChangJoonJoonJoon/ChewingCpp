#define CHAR_TEST 0

//#include <iostream>
//using namespace std;
#include "CustomString.h"
#include "bits/stdc++.h"
#include <iostream>
using namespace std;

CustomString TestFunc(const char* _sParam)
{
    CustomString a;
    a.SetString(_sParam);
    return a;
}

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

    CustomString b;
    // copy assignment operator is implicitly deleted because 'CustomString' has a user-declared move constructor
//    b = TestFunc("asdf");
}

