#include <iostream>

using namespace std;

// int main() {
//     char ch = 'a';
//     cout << ch << endl;
// }

int main() {
    char ch0 = 'a';
    char ch1 = 97;

    cout << "ch0: " << ch0 << endl;
    cout << "ch1: " << ch1 << endl;

    cout << "ch0: " << (int)ch0 << endl; // c 스타일 형변환
    cout << '\141';
    cout << "ch1: " << int(ch1) << endl; // c++ 스타일 형변환

    cout << sizeof(ch0) << endl; // char의 size는 1byte
}