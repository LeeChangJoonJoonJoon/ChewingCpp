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

    auto s_test_0 = new CustomString("s_test_0");
    cout << s_test_0->GetStrLenth("s_test_0") << endl; // 6

    auto s_test_1 = new CustomString("s");
    cout << s_test_1->GetString() << endl; // s

    s_test_1->SetString('s');
    cout << s_test_1->GetString() << endl;

    delete s_test_0;
    delete s_test_1;
}
