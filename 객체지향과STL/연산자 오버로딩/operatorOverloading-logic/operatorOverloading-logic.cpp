#include <iostream>
#include <cstring>

using namespace std;

// !, &&, ||

// class String {
// private:
//     char* _chars;

// public:
//     String(const char* chars)
//         : _chars(new char[strlen(chars) + 1]) {
//             strcpy(_chars, chars);
//         }
//     // ! 연산자 overloading
//     bool operator!() const {
//         return strlen(_chars) == 0;
//     }
// };

// int main() {
//     // ! 연산자 -> 문자열에 아무것도 없으면 not으로 인식하도록 overloading
//     // 현재로선 if (!s)에 대한 연산은 가능한데, 반대로 if (s)에 대한 연산은 불가하다.
//     String s("");
//     if (!s) {
//         cout << "empty" << endl;
//     }
// }

class String {
private:
    char* _chars;

public:
    String(const char* chars) : _chars(new char[strlen(chars) + 1]) {
            strcpy(_chars, chars);
    }
    // || 연산자
    // 파라미터로는 다른 타입도 올 수 있으나, 안좋은 상황 예시를 위해 boolean type을 넣음
    bool operator||(bool b) const {
        // String instance의 길이가 0보다 크거나, b가 true인 경우
        return strlen(_chars) > 0 || b;
    }

};

bool func() {
    cout << "func" << endl;
    return true;
}

int main() {
    String s0("");
    if (true || func()) {
        cout << "!!" << endl;
    }
}