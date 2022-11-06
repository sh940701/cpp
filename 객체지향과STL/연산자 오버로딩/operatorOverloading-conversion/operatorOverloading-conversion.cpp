#include <iostream>
#include <cstring>

using namespace std;

// class String {
// public:
//     explicit String(const char* chars) {

//     }
// };

// int main() {
//     // 위 생성자에서 explicit가 없으면 String s = "abc";로 초기화가 가능하다.
//     // explicit가 있으면 String s("abc"); 의 방법으로만 초기화가 가능하다.

//     // explicit가 없으면 선언시에 암시적으로 String s = String("abc");를 호출해 주게 된다.
//     // explicit가 있으면 암시적 형변환이 이루어지지 않아 명시적으로 호출해주어야만 작동한다.
// }

// class String {
// public:
//     String(const char* chars){} // 형변환 생성자

//     String(const char* s0, const char* s1) { // 파라미터를 두 개 받는 형변환 생성자
//         cout << s0 << endl;
//         cout << s1 << endl;
//     }

//     // initializer_list를 사용해 같은 타입의 많은 parameter를 받을 수 있다.
//     String(initializer_list<const char*> strs) {
//         for (const char* str : strs) {
//             cout << str << endl;
//         }
//     }
// };

// int main() {
//     String s = "abc";

//     String s1 = {"abc", "def"};

//     String s2 = {"a", "b", "c", "d", "e", "f"};
// }

class String {
private:
    // 아래 문자열이 빈 문자열이면 false, 한개라도 있으면 true로 만들자.
    char* _chars;

public:
    // explicit가 없으니, 이 또한 형변환 생성자이다.
    String(const char* chars)
        : _chars(new char[strlen(chars) + 1]) {
            strcpy(_chars, chars);
        }

    // 이전 논리연산자 오버로딩에서, 연산자 오버로딩은 위험하다고 했는데
    // 이보다 bool 변환 연산자를 사용하는 것이 더 안전하다.
    // 변환 연산자 -> 변환하고 싶은 타입을 적어주면 된다.
    operator bool() const {
        return strlen(_chars) > 0;
    }
};

int main() {
    // 형변환 생성자를 통해 s0 객체 생성
    String s0 = "abc";

    // 만약 위 변환 연산자 오버로딩에 explicit가 있으면 아래와 같이 초기화 시 작동하지 않는다. -> if(s0)은 된다.
    // explicit가 있다면, bool result = (bool)s0; 으로 명시적으로 초기화 해줘야 한다.
    bool result = s0;

    cout << result << endl; // 1

    if (s0) {
        cout << "!!" << endl; // !!
    }
}