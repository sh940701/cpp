#include <iostream>

using namespace std;


// class Base {
// // protected라는 접근 지정자를 선언하여, 자식 클래스에서는 접근 가능하나 외부로는
// // 노출되지 않는 멤버 요소를 추가할 수 있다.
// protected:
//     int num2;

// private:
//     int num;
// public:
//     void func() {
//         cout << num << endl;
//     }
//     // private 멤버에 자식 클래스 접근 + 은닉성 강화를 위해 부모 클래스에 함수 생성
//     void set (int value) {
//         num = value;
//     }
//     void add (int value) {
//         num += value;
//     }
// };

// class Derived : public Base {
// public:
//     void foo() {
//         add(20);
//         func();
//         // protected로 지정된 멤버는 자식클래스에서 접근할 수 있다.
//         num2 = 100; // 정상
//     }
// };

// int main() {
//     Derived d;
//     d.set(10);
//     d.foo(); // 30

//     // protected로 지정된 멤버는 외부에서 접근할 수 없다.
//     d.num2 = 100; // error
// }

// class Base {
// private:
//     int num;
// public:
//     // 부모 클래스의 파라미터가 없는 기본 생성자
//     Base() : num(0) {
//         cout << "Base" << endl;
//     }
//     // 부모 클래스의 파라미터가 있는 생성자.
//     Base (int num) : num(num) {
//         cout << "Base(" << num << ")" << endl;
//     }

//     void print() {
//         cout << num << endl;
//     }
// };

// class Derived : public Base {
// public:
//     Derived(){
//         cout << "Derived" << endl;
//     }
//     // 만약 특정 생성자를 지정해주고싶다면, member initializer list에 값을 넣어준다.
//     Derived(int num) : Base(num) {
//         cout << "Derived" << endl;
//     }
// };

// int main() {
//     // 기본적으로 자식 클래스에서 부모의 어떤 생성자로 생성을 할지 지정을 안해주면
//     // 부모클래스에서 파라미터가 아무것도 없는 기본 생성자가 호출된다.
//     Derived d;
//     // Base
//     // Derived
//     // 자식클래스는 부모클래스를 모두 가지고있어야 하기 때문에
//     // 자식 객체가 생성되려면, 부모객체가 먼저 생성되고 이후 자식객체가 생성된다.

//     Derived d2(20);
//     // Base(20)
//     // Derived
// }

// class Base {
// private:
//     int num;
// public:
//     Base() : num(0){
//         cout << "Base" << endl;
//     };
//     Base (int num) : num(num) {
//         cout << "Base(" << num << ")" << endl;
//     }
// };

// class Derived : public Base {
//     // 자식이 부모를 상속받을 때, 모든 것이 상속된다고 했다. 그럼 위에 있는
//     // 생성자도 상속받게 되는 것인가? -> 생성자 상속을 위해선 using이라는 것을 사용할 수 있다.
//     // 위에서 디폴트 생성자와 파라미터가 있는 생성자 두 개를 모두 받은 것이다.
//     using Base::Base;

//     // 만약 위 생성자 중 파라미터를 받는 생성자를 없애고 싶으면 delete를 해주면 된다.
//     Derived(int) = delete;
// };

// int main() {
//     Derived d0(20); // Base(20) -> delete 되면 error
//     Derived d1; // Base -> 파라미터가 있는 생성자, 없는 기본 생성자 모두 상속받아졌다.
// }

// 파괴자 로직을 살펴보자
class Base {
public:
    virtual ~Base(){
        cout << "~Base" << endl;
    }
    void func() {
        cout << "func" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "~Derived" << endl;
    }
};

void func(Base& b) {
    // 함수 입장에서는 b.func() 가 있는 Base 타입인지 아닌지가 중요하다.
    // 그런데 Derived는 사실상 Base를 상속받아 내부적으로 Base를 들고있기 때문에 가능한 것이다.
    b.func();
}

int main() {
    // 포인터가 아니라 레퍼런스로도 자식 객체를 가리킬 수 있다.
    // 그렇다면 왜 레퍼런스를 사용하는 것일까?
    // 위와 같이 Base& 타입을 받는 함수가 있었을 때, 지금까지는 Base type 변수를 생성하여
    // 그 변수를 함수에 대입해야만 했다.
    Base b;
    func(b);

    // 그러나 부모가 자식을 레퍼런스로 가리킬 수 있는 것을 이해하면, 아래와 같이
    // Base& 타입 변수를 받는 함수에 Derived 변수를 인자로 넣어 실행할 수도 있다.
    // 이는 앞서 말했듯, 자식이 부모를 상속받게 되면 부모의 모든 요소를 가지게 되기 때문에
    // 부모 타입의 레퍼런스로 자식을 가리켜도 내부적으로 모든 것이 있으므로 조건이 충족되는 것이다.
    Derived d;
    func(d);
}