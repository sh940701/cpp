#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// int main() {
//     // volatile에 대하여
//     // 아래와 같은 연산에서 volatile이 없을 떼 assembly를 보면, 컴퓨터가 코드를 분석하고 자동으로 최적화해서
//     // 세 번의 증가 연산을 진행하는 것이 아니라 i에 곧장 3을 넣어주는 것을 알 수 있다.

//     // 그런데 volatile을 선언한 후 살펴보면, i++라는 각 연산에 대해 계산하고, 결과값을 i에 넣어주는 과정을
//     // 반복해서 진행하게 된다. -> i의 메모리에서 값을 읽고, 연산 후 저장하는 과정을 반복한다.
//     // 이와 같이 volatile은 컴퓨터 단계에서의 어떤 최적화를 하지 않겠다는 선언이라고 생각할 수 있다.

//     // volatile의 이러한 성질은 멀티쓰레드 환경 등에서 쓰레드끼리 전역변수를 공유할 때
//     // 최적화 없이 로직을 진행해야 할 경우 사용할 수 있고, 프로그램 외부의 환경에 의해
//     // 변수가 바뀌게 될 수 있는 상황에서 사용하게 된다. -> 이러한 변화는 컴파일 타임에서 알 수 없다.
//     volatile int i = 0;
//     i++;
//     i++;
//     i++;
//     return i;
// }


// const_cast 사용해보기

// 인자를 const int&로 받았기 때문에 i에 대한 변경이 불가능하다.
// 별로 좋지 않은 상황이지만, 함수 내부에서 i의 값을 바꿔야 하는 상황이 생겼을 때
// const cast를 사용하여 해당 작업을 수행해줄 수 있다.
// void func(const int& i) {
//     int& j = const_cast<int&>(i);
//     j = 10;
// }

// int main() {
//     int i = 0;
//     // 함수를 실행할 때, i의 ref값이 const화 되어 넘어가게 된다.
//     func(i);

//     cout << i << endl; // 10 -> 함수 내부에서 const_cast로 값을 바꾸어 i가 바뀌었다.

//     // 이 때, 만약 int i가 const int i로 선언되었다면, 이를 바꾸는 const_cast작업은 실행결과를 보장할 수 없게 된다.
// }


// 그나마 const_cast를 사용해도 괜찮을 만 한 예시

// class String {
// private:
//     char* _chars;

// public:
//     // 이렇게 만들어도 되는데??..
//     // String(const char* chars)
//     //     : _chars(chars){}
//     String(const char* chars)
//         : _chars(new char[strlen(chars) + 1]) {
//             strcpy(_chars, chars);
//     }

//     // 연산자 오버로딩을 통한 인덱스 접근의 상황을 살펴보자
//     // 자 아래와 같이 오버로딩을 하면 s0[0]은 가능하나, const로 선언된 s1[0]은 불가능하다.
//     // 아래 함수는 String* this를 받게 되는데, const String* this는 String* this로 변경이 불가하기 때문이다.
//     // 이러한 상황을 극복하기 위해 다른 방식으로 오버로딩을 또 해주자
//     char& operator[](int index) {
//         return _chars[index];
//     } 

//     // 이제 const로 선언된 String객체에 대한 연산은 아래로 들어오게 된다.
//     // 그런데 const this로 받아서 this->_chars[index]를 반환해주면 반환값도 밖에서 바꾸면 안되겠지?
//     // 그래서 앞에도 const를 붙여준다.
//     // 이로서 두 가지 상황에 대한 예외처리를 완료한 것 같이 보인다.
//     // 그런데 그럼, 앞으로 연산자 오버로딩을 할 때, 중복코드를 계속 작성해야 할 것인가?
//     // 이러한 상황을 타개하기 위해서 나온게 const_cast이다.
//     const char& operator[](int index) const {
//         return _chars[index];
//     } 
// };

// int main() {
//     String s0("abcd");
//     cout << s0[0] << endl; // a

//     const String& s1 = s0;
//     cout << s1[0] << endl;
    
// }

class String {
private:
    char* _chars;

public:
    String(const char* chars)
        : _chars(new char[strlen(chars) + 1]) {
            strcpy(_chars, chars);
    }

    char& operator[](int index) {
        // const String& 타입의 변수 s를 만들어, *this로 초기화해준다.
        // 아래에 다른 operator[]의 인자값으로 들어갈 것이기 때문에 const String이어야 한다.
        // 여기서 this가 상수성을 갖게 된게 아니라, this와 같은 값을 가리키는 레퍼런스 변수가 상수성을 가진 것이다.
        const String& s = *this;

        // 아래 const overloading을 사용하여 리턴받은 결과값을 담는다.
        // 이 때 c는 const char& 타입이다.
        const char& c = s[index];

        // 이 오버로딩에서 하고싶은 것은 const가 아닌 String 객체에 대해
        // 변경 가능한 결과값을 리턴하는 것이기 때문에 const를 없애준 값을 리턴해준다.
        return const_cast<char&>(c);
    } 

    const char& operator[] (int index) const {
        return _chars[index];
    }
};

// 위와 같은 오버로딩을 통해 const String 객체의 값 출력 및 수정 불가를 충족하고
// 또한 String 객체의 값 출력 및 수정 가능도 충족하게 된다.
// 중복코드로 작성해야 하는 코드가 길어지면 길어질수록 위와 같은 방식의 const_cast를 사용하는 것이
// 유지 보수 및 코드 작성에 있어서도 훨씬 유용하다고 할 수 있다.

int main() {
    String s0("abcd");
    s0[0] = 'q'; // 정상
    cout << s0[0] << endl;

    const String& s1 = s0;
    s1[0] = 'r'; // error
    cout << s1[0] << endl;
}