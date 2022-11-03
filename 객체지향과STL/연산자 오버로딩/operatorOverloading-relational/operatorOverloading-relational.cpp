#include <iostream>
#include <cstring>
#include <compare>

using namespace std;

// 내부적으로 작동하는 String 클래스를 만들어서 사용해보자
// class String {
// private:
//     // 몇 글자가 올지 모르기때문에 동적 할당으로 포인터로 만들어줌
//     char* _chars;

// public:
//     // 생성자 파라미터로 문자열의 포인터를 받는다. 파라미터 값 변경이 없으므로 포인터로 받는다.
//     String(const char* chars)
//         // 컴파일타임에 길이가 정해져있지 않기때문에 비어있는 동적 배열을 _chars에 넣어준다.
//         // 이 때 동적배열의 길이는 null 값을 포함하여 파라미터 chars보다 1 더 길다.
//         : _chars(new char[strlen(chars) + 1]) {
//             // 비어있는 _chars 배열에 chars 값을 복사해준다.
//             strcpy(_chars, chars);
//         }

//     // == 연산자 overloading    
//     bool operator==(const String& s) const {
//         // 두 char 배열이 같으면 0을 리턴하는 strcmp함수 결과값 출력
//         return strcmp(_chars, s._chars) == 0;
//     }

//     // != 연산자 overloading
//     bool operator!=(const String& s) const {
//         // strcmp함수는 좌측이 크면 0보다 큰 값, 작으면 0보다 작은 값을 return한다.
//         return strcmp(_chars, s._chars) != 0;
//         // return !(*this == s); // 좌측과 같이 상단 == operator를 사용할수도 있음
//     }

//     // < 연산자 overloading
//     bool operator<(const String& s) const {
//         return strcmp(_chars, s._chars) < 0;
//     }

//     // > 연산자 overloading
//     bool operator>(const String& s) const {
//         return strcmp(_chars, s._chars) > 0;
//     }

//     // <= 연산자 overloading
//     bool operator<=(const String& s) const {
//         return !(*this > s);
//     }

//     // strong_ordering은 0과 비교하여 같거나, 크거나, 작은 여부만 나타내는 값이다.
//     // weak, partial ordering등이 있다고 하는데 나중에 알아보자
//     strong_ordering operator<=>(const String& s) const {
//         int result = strcmp(_chars, s._chars);
//         if (result < 0) {
//             return strong_ordering::less;
//         }
//         if (result > 0) {
//             return strong_ordering::greater;
//         }
//         return strong_ordering::equal;
//     }

//     void print() {
//         cout << _chars << endl;
//     }
// };

// int main() {
//     // ==, !=, <, >, <=, >=, <=>
//     String s0("abc");
//     String s1("abc");
//     if ((s0 <=> s1) == 0) {
//         cout << "equal" << endl;
//     }
// }

class String {
private:
    char* _chars;

public:
    // 암시적 형변환을 막기 위해 explicit 선언
    explicit String(const char* chars)
        : _chars(new char[strlen(chars) + 1]) {
        strcpy(_chars, chars);
    }
    
    bool operator==(const String& s) const {
    // 두 char 배열이 같으면 0을 리턴하는 strcmp함수 결과값 출력
    return strcmp(_chars, s._chars) == 0;
    }

    // String 객체와 char 배열의 비교
    bool operator==(const char* c) const {
        return strcmp(_chars, c) == 0;
    }

    void print() {
        cout << _chars << endl;
    }

    // private 멤버와의 연산을 위해 함수 프로토타입 friend 선언
    friend bool operator==(const char* c, const String& s );
};

// char == String 순서의 비교연산자 활성화를 위해 전역변수로 선언
bool operator==(const char* c, const String& s ) {
    return strcmp(c, s._chars) == 0;
}


int main() {
	String s0("x");
    // C스타일 문자열과 String 타입의 객체를 비교해보자
    // 근데 이상하게 아래가 정상적으로 실행된다. 왜일까?
    // 비교연산자를 실행하는 과정에서 뒤에 "x"가 암시적으로 String("x")로 변환되어서 그렇다.
    // 이런 일을 막기 위해서는 생성자 옆에 explicit를 넣어주면 된다.
    if (s0 == "x") {
        cout << "!!" << endl;
    }

    // 순서를 바꿔서도 가능하게 하려면, 전역에 선언 후 friend 선언을 해줘야 한다.
    if ("x" == s0) {
        cout << "!!!!" << endl;
    }
}