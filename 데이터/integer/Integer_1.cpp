// https://www.notion.so/9f599941b3fc40d9a520d7a99644df0b
#include <iostream>

using namespace std;

// 정수형
// int main() {
//     int x = 1, y = 2, z(3);
//     // x = 1;
//     // y = 2;
//     // z = 3;

//     cout << x << endl;
//     cout << y << endl;
//     cout << z << endl;
// }

// int main() {
//     int num0 = 11;
//     // 앞에 0이붙으면 8진수
//     int num1 = 011;
//     // 앞에 0b가 붙으면 2진수
//     int num2 = 0b11;
//     // 앞에 0x가 붙으면 16진수
//     int num3 = 0x11;

//     cout << "num0 " << num0 << endl; // 11
//     cout << "num1 " << num1 << endl; // 8 + 1 = 9
//     cout << "num2 " << num2 << endl; // 2 + 1 = 3
//     cout << "num3 " << num3 << endl; // 16 + 1 = 17
// }

// 환경별로 각각의 크기를 알아보자
// int main() {
//     int intNum = 0;
//     long longNum = 0;
//     int* intPointer = &intNum;

//     cout << sizeof(intNum) << endl;
//     cout << sizeof(longNum) << endl;
//     cout << sizeof(intPointer) << endl;
// }

// 환경별로 달라지는 크기를 고정해보자
int main() {
    int8_t num0 = 0;
    int16_t num1 = 0;
    int32_t num2 = 0;

    cout << sizeof(num0) << endl;
    cout << sizeof(num1) << endl;
    cout << sizeof(num2) << endl;
}