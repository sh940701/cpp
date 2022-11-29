#include <iostream>
#include <vector>

// const char* wrap(const char* str) {
//     return str ? str : "";
// }

// class String {
// private:
//     char* _str;

// public:
//     String() {}

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

//     // 이동 생성자
//     String(String&& other) noexcept
//     : _str(other._str) {
//         std::cout << "Move Constructor : " << _str << std::endl;
//         other._str = nullptr;
//     }

//     ~String() {
//         std::cout << "Destruct : " << wrap(_str) << std::endl;
//         delete[] _str;
//     }

//     String& operator=(const String& other) {
//         delete[] _str;
//         std::cout << "Copy operator : " << _str << " => " << other._str << std::endl;
//         _str = new char[strlen(other._str) + 1];
//         strcpy(_str, other._str);
//         return *this;
//     }

//     String& operator=(String&& other) noexcept
//     {
//         std::cout << "Move operator : " << wrap(_str) << " => " << other._str << std::endl;
//         delete[] _str;
//         _str = other._str;
//         other._str = nullptr;
//         return *this;
//     }

//     friend std::ostream& operator<<(std::ostream& os, String& str) {
//         return (os << str._str);
//     }
// };

// template<typename T>
// void swap(T& x, T& y) {
//     T temp = std::move(x);
//     x = std::move(y);
//     y = std::move(temp);
// }

// int main() {
//     // noexcept를 써주지 않으면 어떻게 될까?
//     std::vector<String> s{String("abc")};

//     std::cout << "reserve" << std::endl;

//     // reserve로 capacity를 늘려본다.
//     // 다른사이즈로 옮겨가면서 원소들이 새 동적배열에 재할당된다.
//     s.reserve(100);

//     // Construct : abc
//     // Copy Construct : abc
//     // Destruct : abc
//     // reserve
//     // Copy Construct : abc
//     // Destruct : abc
//     // Destruct : abc
//     // noexcept가 없으니 copy가 됐다.


//     // Construct : abc
//     // Copy Construct : abc
//     // Destruct : abc
//     // reserve
//     // Move Constructor : abc
//     // Destruct : 
//     // Destruct : abc
//     // noexcept가 적용된 후, move가 되었다.

//     // 이동 관련된 연산들은 noexcept를 해줘야한다.
//     // 복사는 뭔가를 새로 할당하기 때문에 exception이 날 수 있고 이를 감당해야 한다.
//     // 그러나 이동의 경우에는 그렇지 않고, 예외가 발생하면 안되기때문에 noexcept선언이 필요하다.
// }


// const char* wrap(const char* str) {
//     return str ? str : "";
// }

// class String {
// private:
//     char* _str;

// public:
//     String() {}

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

//     // 이동 생성자
//     String(String&& other) noexcept
//     : _str(other._str) {
//         std::cout << "Move Constructor : " << _str << std::endl;
//         other._str = nullptr;
//     }

//     ~String() {
//         std::cout << "Destruct : " << wrap(_str) << std::endl;
//         delete[] _str;
//     }

//     String& operator=(const String& other) {
//         delete[] _str;
//         std::cout << "Copy operator : " << _str << " => " << other._str << std::endl;
//         _str = new char[strlen(other._str) + 1];
//         strcpy(_str, other._str);
//         return *this;
//     }

//     String& operator=(String&& other) noexcept
//     {
//         std::cout << "Move operator : " << wrap(_str) << " => " << other._str << std::endl;
//         delete[] _str;
//         _str = other._str;
//         other._str = nullptr;
//         return *this;
//     }

//     friend std::ostream& operator<<(std::ostream& os, String& str) {
//         return (os << str._str);
//     }
// };

// template<typename T>
// void swap(T& x, T& y) {
//     T temp = std::move(x);
//     x = std::move(y);
//     y = std::move(temp);
// }

// // 뭔가를 만드는 함수(factory 함수) 생성
// String makeString(const char* str) {
//     return String(str);
// }

// // 어떤 객체가 호출한 쪽에 리턴되어야 하는지 모르는 상황을 보자
// // 이 때는 리턴 밸류 옵티마이제이션으로 어떤 것이 리턴되어야 하는지 바로 파악이 불가능하다.
// // 그러나 입력값을 받고 리턴하는 순간에 이 녀석이 알아서 최적화를 하여 move로 진행된다.
// // 따라서 함수의 return값에 대해서는 따로 std::move를 실행해 줄 필요가 없다.
// String makeString(const char* str) {
//     String s0("abc");
//     String s1("def");

//     int i;
//     std::cin >> i;

//     if (i < 0) {
//         return s0;
//     } else {
//         return s1;
//     }
// }

// int main() {
//     // 함수 내에서 리턴할 때 뭔가 복사가 될 것 같다. 그럼 std::move를 선언해줘야하나
//     // 그렇지 않다. 내부적으로 리턴 밸류 옵티마제이션(?)에 의해 이녀석들이 알아서 최적화(move)를 해 준다.
//     makeString("abc");
// }


const char* wrap(const char* str) {
    return str ? str : "";
}

class String {
private:
    char* _str;

public:
    String() {}

    explicit String(const char* str)
    : _str(new char[strlen(str) + 1]) {
        strcpy(_str, str);
        std::cout << "Construct : " << _str << std::endl;
    }

    String(const String& other)
    : _str(new char[strlen(other._str) + 1]) {
        strcpy(_str, other._str);
        std::cout << "Copy Construct : " << _str << std::endl;
    }

    String(String&& other) noexcept
    : _str(other._str) {
        std::cout << "Move Constructor : " << _str << std::endl;
        other._str = nullptr;
    }

    ~String() {
        std::cout << "Destruct : " << wrap(_str) << std::endl;
        delete[] _str;
    }

    String& operator=(const String& other) {
        delete[] _str;
        std::cout << "Copy operator : " << _str << " => " << other._str << std::endl;
        _str = new char[strlen(other._str) + 1];
        strcpy(_str, other._str);
        return *this;
    }

    String& operator=(String&& other) noexcept
    {
        std::cout << "Move operator : " << wrap(_str) << " => " << other._str << std::endl;
        delete[] _str;
        _str = other._str;
        other._str = nullptr;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, String& str) {
        return (os << str._str);
    }
};

// int main() {
//     int num0 = 10;
//     // & 하나짜리 -> LValue reference -> 임시값이 아닌 녀석만을 가리킴
//     int& num1 = num0;
//     // & 두개짜기 -> RValue reference -> 임시값만을 가리킴
//     int&& num2 = 10; // int&& num2 = num0; -> error

//     // RValue ref는 임시객체를 묶었다.
//     // 원래는 사라졌어야 할 임시객체인 String("abc")가 RValue ref에 묶여 수명이 연장된 것이다.
//     // RValue ref는 RValue를 묶을 수 있고, String("abc")는 임시객체로, RValue중 p(pure)RValue이다.
//     String&& s = String("abc");
//     String&& s0 = s; // error -> RValue ref의 값인 s;는 LValue이다. 따라서 RValue ref에 묶일 수 없다.


//     // LValue = 임시객체와 달리 
// }


// int main() {
//     int num0 = 10;
//     int& num1 = num0;
//     int&& num2 = num0 + num1; // 임시값이기 때문에 받을 수 있다.

//     int& num3 = 3; // error -> 임시값을 받을 수 없다
//     int&& num4 = num0; // error -> 임시값이 아니어서 받을 수 없다.
    
//     int& num6 = num2; // num2는 LValue가 되었기 때문에 LValue ref로 받을 수 있다.
//     int&& num7 = num2; // error -> num2는 LValue이기 때문에 RValue ref로 받을 수 없다.

//     int&& num8 = std::move(num0); // std::move(LValue)는 RValue ref로 받을 수 있게 된다.
// }


void foo(int&) {
    std::cout << "int&" << std::endl;
}

void foo(int&&) {
    std::cout << "int&&" << std::endl;
}

int main() {
    foo(1); // int&&

    int num = 10;
    foo(num + 10); // int&&

    foo(num); // int&
    // std::move는 LValue를 강제로 move가 가능하도록 만들어주는 녀석
    foo(std::move(num)); // int&&
    // static_cast로 RValue타입으로 변경해서 넘겨주면, RValue로 속는다.
    foo(static_cast<int&&>(num)); // int&&

    // 어라 근데 이녀석은 안 속는다. 왜그럴까?
    // 아아 int&& num0은 RValue를 묶은 결과로, LValue다. 그래서 int&가 출력된것이다.
    // 사실상, 이름을 가지게 되는 순간! LValue인 것이다.
    int&& num0 = static_cast<int&&>(num); // xvalue
    foo(num0); // int&

    // std::move()는 내부적으로 static_cast를 사용하여 RValue Ref 타입으로 묶어서 리턴하는 녀석이다.
    // move는 이동시킨다기보다. 이동할 수 있도록 casting을 해주는 녀석
}