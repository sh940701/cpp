#include <iostream>

using namespace std;

int main() {
    // bool b0 = 0 == 0;
    // bool b1 = 0 < 1;
    // bool b2 = 0 > 1;

    // // true와 false로 표현해주기 위한 설정
    // cout.setf(ios_base::boolalpha);

    // cout << "b0: " << b0 << endl;
    // cout << "b1: " << b1 << endl;
    // cout << "b2: " << b2 << endl;

    // if (b0) 
    //     cout << "b0" << endl;
    // if (b1)
    //     cout << "b1" << endl;
    // if (b2)
    //     cout << "b2" << endl;

    int itrue = true;
    int ifalse = false;

    cout << itrue << endl; // 1
    cout << ifalse << endl; // 0

    // boolean으로 형변환이 이루어져서 출력 시 1(true) or 0(false)가 출력된다.
    bool btrue = 100;
    bool bfalse = 0;

    cout << btrue << endl; // 1
    cout << bfalse << endl; // 0
}