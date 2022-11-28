#include <iostream>
#include <cstring>



// class String {
// private:
//     char* _str;

// public:
//     // 생성자
//     // 암시적 변환을 막기 위해 explicit 선언
//     explicit String(const char* str)
//     : _str(new char[strlen(str) + 1]) {
//         strcpy(_str, str);
//         std::cout << "Construct : " << _str << std::endl;
//     }

//     // 복사 생성자
//     String(const String& other)
//     : _str(new char[strlen(other._str) + 1]) {
//         strcpy(_str, other._str);
//         std::cout << "Copy Construct : " << _str << std::endl;
//     }

//     // 동적 할당된 녀석을 지워주기 위한 소멸자
//     ~String() {
//         std::cout << "Destruct : " << _str << std::endl;
//         delete[] _str;
//     }

//     // 복사 대입 연산자
//     String& operator=(const String& other) {
//         delete[] _str;
//         std::cout << "Copy operator : " << _str << " => " << other._str << std::endl;
//         _str = new char[strlen(other._str) + 1];
//         strcpy(_str, other._str);
//         return *this;
//     }

//     friend std::ostream& operator<<(std::ostream& os, String& str) {
//         return (os << str._str);
//     }
// };

// template<typename T>
// void swap(T& t0, T& t1) {
//     // 복사 생성자
//     T temp = t0;
//     // 복사 대입 연산자
//     t0 = t1;
//     // 복사 대입 연산자
//     t1 = temp;
// }

// int main() {
// // 문제 1
//     // 그냥 실행하면
//     // Construct : abc
//     // Construct : def
//     // Copy operator : abc => def
//     // Destruct : def
//     // Destruct : def -> 이런 결과가 나온다.
//     // String("def")의 임시객체를 만들었다가 다시 넘겨주고 또 지워주는 과정이 반복되는 것이다.
//     // new 연산자의 할당이 3번이나 일어난다. 똑같은 것을 위해서 말이다.
//     // 쓸데없이 새로 만들고 지우고 다시 할당하는 프로세스가 들어있다.
//     // String s0("abc");
//     // 아래와 같이 하면 복사 대입 연산자가 불러진다. -> 할당 단계
//     // s0 = String("def");

//     // 아래와 같이 하면 복사 생성자가 불러진다. -> 초기화 단계
//     // String s1 = s0;


// // 문제 2
//     // 실행 결과는 아래와 같다.
//     // Construct : abcd
//     // Construct : efgh
//     // Copy Construct : abcd
//     // Copy operator : abcd => efgh
//     // Copy operator : efgh => abcd
//     // Destruct : abcd
//     // efgh
//     // abcd
//     // Destruct : abcd
//     // Destruct : efgh
//     // 위를 보면, 단순히 잠시 쓰고 마는 임시객체를 생성하기 위해 동적 할당 등
//     // 여러 연산을 수행하게 되는 것을 알 수 있다.
//     // 이러한 비효율성을 줄이기 위해, copy가 아닌 move를 사용할 수 있다.
//     String s2("abcd");
//     String s3("efgh");
//     swap(s2, s3);

//     std::cout << s2 << std::endl;
//     std::cout << s3 << std::endl;
// }

// str이 nullptr인지 확인하고 결과값을 반환하는 함수 생성
const char* wrap(const char* str) {
    return str ? str : "";
}

class String {
private:
    char* _str;

public:
    // 생성자
    // 암시적 변환을 막기 위해 explicit 선언
    explicit String(const char* str)
    : _str(new char[strlen(str) + 1]) {
        strcpy(_str, str);
        std::cout << "Construct : " << _str << std::endl;
    }

    // 복사 생성자
    String(const String& other)
    : _str(new char[strlen(other._str) + 1]) {
        strcpy(_str, other._str);
        std::cout << "Copy Construct : " << _str << std::endl;
    }

    // 이동 생성자
    String(String&& other) noexcept
    : _str(other._str) {
        std::cout << "Move Constructor : " << _str << std::endl;
        other._str = nullptr;
    }

    // 동적 할당된 녀석을 지워주기 위한 소멸자
    ~String() {
        // 마지막에, 임시객체가 가리키는 녀석이 nullptr인데 읽으려고 함으로 에러 발생
        std::cout << "Destruct : " << wrap(_str) << std::endl;
        delete[] _str;
    }

    // 복사 대입 연산자
    // 아래를 보면, other라는 녀석이 (temp 같은)"임시객체"인지를 판별할 수 있다면
    // 새로운 동적 배열을 만들어서 그 안에다가 other._str을 넣어주는 것이 아니라
    // 그냥 _str이 가리키는 녀석을 없애고, other._str을 가리키게 만들면 된다.
    String& operator=(const String& other) {
        delete[] _str;
        std::cout << "Copy operator : " << _str << " => " << other._str << std::endl;
        _str = new char[strlen(other._str) + 1];
        strcpy(_str, other._str);
        return *this;
    }

    // move(이동) 대입 연산자 -> &가 아니라 &&를 붙여준다. -> 우측값 참조 라고 한다.
    // noexcept를 선언해주지 않으면 이동이 아니라 복사가 실행되는 경우가 있다.
    String& operator=(String&& other) noexcept
    {
        std::cout << "Move operator : " << wrap(_str) << " => " << other._str << std::endl;

        // 먼저 내가 지금 가리키고 있는 포인터를 해제한다.
        delete[] _str;
        // other._str의 주소값을 _str에 넘겨준다.
        _str = other._str;
        // other._str은 더이상 아무것도 가리키지 않는다.
        other._str = nullptr;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, String& str) {
        return (os << str._str);
    }
};

template<typename T>
void swap(T& x, T& y) {
    // 위에 이동 생성자를 만들어줬는데도, 복사 생성자가 호출된다. 그 이유는
    // 실제로 x._str은 더이상 사용되지 않지만, 컴퓨터는 더 사용된다고 생각하기 때문이다.
    // 이 때 이동 생성자로 강제하기 위해서는 std::move를 사용하면 된다.
    // 복사가 아니라 이동할 녀석이라고 알려주는 것
    T temp = std::move(x); // -> 이 때 x._str는 무효한 값이 됨
    // 여기서 x 또한 새로 동적할당을 할 필요 없이 y의 주소를 넘겨받아도 된다.
    x = std::move(y); // -> 이 때 y._str는 무효한 값, x._str는 유효한 값이 됨
    y = std::move(temp); // -> 이 때 temp._str는 무효한 값, y._str는 유효한 값이 됨
}


int main() {
    String s0("abc");
    String s1("def");

    swap(s0, s1); // 복사 대입 연산자를 이동으로 오버로딩 한 것 처럼 복사 생성자도 해보자
}


// int main() {
//     String s0("abc");
//     s0 = String("def"); // String("def")는 더이상 사용 안되고 날아갈 녀석
//     // 실행결과
//     // Construct : abc
//     // Construct : def
//     // Move operator : abc => def
//     // Destruct : 
//     // Destruct : def
//     // 비슷해보이나, copy가 아니라 move가 실행되었다. copy operator단계에서 실행되었던
//     // 동적 할당이 일어나지 않아, 자원을 절약하게 된 것이다.

//     String s1("def");
//     s0 = s1;
//     // 위와 같은 경우에는 copy operator가 실행된다.
//     // 우측 값이 임시객체가 아니라는 것을 판단하고 move가 아닌 copy로 들어간 것이다.
// }