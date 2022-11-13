// #include <iostream>

// using std::cout;
// using std::endl;


// RAII가 필요한 이유
// 파괴자가 호출될 때 문자열을 출력하는 Test class
// class Test {
// public:
//     ~Test() {
//         cout << "~Test" << endl;
//     }
// };

// void func() {
//     throw "exception";
// }

// int main() {
//     try
//     {
//         // Test type 객체를 동적할당해보자. 이 때, func에서 throw를 하게되면서
//         // 동적할당 된 객체가 해제되지 않고, 소멸자가 호출되지 않는다.
//         // 이 때 중요한 것은 t라는 변수는 자동할당변수로서, 스코프를 벗어나는 순간 해제되지만
//         // t가 가리키고 있는 동적 공간에 할당된 Test 객체는 소멸되지 않는다는 것이다.
//         Test* t = new Test;
//         func();
//     }
//     catch(const char* e)
//     {
//         cout << e << endl;
//     }
// }


// 결국 여기서 중요한 것은 동적할당 변수에 대해서 delete를 수행해주는 것이다.

// void func() {
//     throw "exception";
// }

// int main() {
//     // 전역변수로 i 를 선언한 후, throw로 인해 catch로 들어왔을 때 해제해줄 수도 있다.
//     // 전역변수 int* i 선언
//     int* i = nullptr;
//     try
//     {
//         // i에, 동적 할당 데이터를 담아줌
//         i = new int;
//         func();
//     }
//     catch(const char* e)
//     {
//         // throw로 인해 들어온 catch에서 해제해줌
//         delete i;
//         cout << e << endl;
//     }
// }

// 클래스가 생성됨과 동시에 동적 할당 포인터를 만드는 클래스
// class RAII {
// public:
//     int* i;
//     RAII() {
//         i = new int;
//     }
//     ~RAII() {
//         cout << "~RAII" << endl;
//         // 소멸자가 호출되면 내부적으로 동적 할당 포인터에 대해서 delete를 진행한다.
//         delete i;
//     }
// };

// void func() {
//     throw "exception";
// }

// int main() {
//     try{
//         // RAII 블록을 생성한다. 이 때 throw에 의해서 스코프를 탈출하게 되면
//         // 객체는 자동으로 소멸자가 호출되는데, 이 때 소멸자에서 내부적으로
//         // 동적 할당된 data에 대한 delete를 진행해주기 때문에 결과적으로
//         // 동적 할당 data에 대한 자동해제가 이루어지는 것이다.
//         RAII raii;
//         func();
//     } catch (const char* e) {
//         cout << e << endl;
//     }
// }

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Test {
public:
    ~Test() {
        cout << "~Test" << endl;
    }
};

void func() {
    throw "exception";
}

int main() {
    try{
        // <type> variable(value); 형태로 이루어진다.
        // 아래의 경우, new Test가 Test* 인 t에 들어가게 된 것이다.
        // Test 타입의 포인터가 내부적으로 동적 할당이 되고, try scope를 벗어날때
        // unique_ptr의 소멸자가 호출이 되면서 동적할당 된 녀석을 해제한다.
        std::unique_ptr<Test> t(new Test());
        // 전형적인 RAII 디자인을 사용한 기법이라고 할 수 있다.
        func();
    } catch (const char* e) {
        cout << e << endl;
    }
}