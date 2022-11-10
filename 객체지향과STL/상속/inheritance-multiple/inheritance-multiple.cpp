#include <iostream>

using namespace std;

// 안정적인 상황
// class BaseA {
// public:
//     int m = 10;
//     void foo() {
//         cout << "BaseA" << endl;
//     }
// };

// class BaseB {
// public:
//     int m2 = 20;
//     void foo2() {
//         cout << "BaseB" << endl;
//     }
// };

// // BaseA 와 BaseB 를 둘 다 상속받는 Derived class
// class Derived : public BaseA, public BaseB {

// };

// int main() {
//     Derived d;
//     d.foo(); // BaseA
//     cout << d.m << endl; // 10
//     d.foo2(); // BaseB
//     cout << d.m2 << endl; // 20
// }

// 문제상황 : 양쪽 부모의 멤버변수와 함수 이름이 겹칠 때
// class BaseA {
// public:
//     int m = 10;
//     void foo() {
//         cout << "BaseA" << endl;
//     }
// };

// class BaseB {
// public:
//     int m = 20;
//     void foo() {
//         cout << "BaseB" << endl;
//     }
// };

// // BaseA 와 BaseB 를 둘 다 상속받는 Derived class
// class Derived : public BaseA, public BaseB {
// public:
//     // 모호함 에러 해결법 1: 자식 클래스에서 같은 이름의 멤버 변수, 함수로 가려줌
//     int m = 30;
//     void foo() {
//         cout << "Derived" << endl;
//     }

//     // 해결법 2: 범위를 지정해 줌
//     using BaseA::m; // BaseA의 m을 사용하겠다.
//     using BaseB::foo; // BaseB의 foo를 사용하겠다.
// };

// int main() {
//     Derived d;
//     // 해결법 3: 객체에서 범위를 지정해줌
//     cout << d.BaseA::m << endl;
//     d.BaseB::foo();

//     // 해결법 4: 원하는 부모 타입의 포인터/레퍼런스로 객체를 담아서 실행한다.
//     BaseA& ba = d;
//     ba.foo();

//     BaseB* bb = &d;
//     bb->foo();

//     // 위 네가지와 같은 방법으로 어떤 부모의 것을 사용할 것인지 정해주지 않으면
//     // "모호함" 에러로 인해 컴파일이 되지 않는다.
// }

// 다이아몬드 상속
//      A
//   B0   B1  -> B0, B1이 A를 같이 상속받고, C는 B0과 B1을 상속받는 상황.
//      C

// 다이아몬드 상속을 받은 상황
// class Base {
// public:
//     int m;
//     Base(int m) : m(m) {
//         cout << "Base(" << m << ")" << endl;
//     }
// };

// class BaseA : public Base {
// public:
//     BaseA() : Base(10) {
//         cout << "BaseA" << endl;
//     }
// };

// class BaseB : public Base {
// public:
//     BaseB() : Base(20) {
//         cout << "BaseB" << endl;
//     }
// };


// class Derived : public BaseA, public BaseB {
// public:
//     // 자식 클래스에서 부모생성자를 선택해주지 않으면, 자동으로 부모 클래스 중
//     // 인자값을 받지 않는 default 생성자를 호출한다.(BaseA(), BaseB())
//     Derived() {
//         cout << "Derived" << endl;
//     }
// };

// int main() {
//     Derived d;
//  /* Base(10)
//     BaseA
//     Base(20)
//     BaseB
//     Derived */
//     // 위와 같은 순서로 호출됨
//     // 최상위 클래스 Base 생성자가 두 번 호출된 것을 알 수 있다.
//     // 문제는, 이 상황에서 d.m을 호출이 안된다는 것이다.

//     d.m; // 모호함 -> BaseA를 통한 m은 10이고, BaseB를 통한 m은 20이기 때문에
//     // 이렇게 선언하게 되면 두 개 중 어떤 값을 가져와야 할지 모르게 된다.
    
//     // 이 또한 결국에는 BaseA를 통한 m과 BaseB를 통한 m 두 개의 m이 하나의 Derived
//     // 객체에 담겨있음으로 인해 생기는 문제이므로, 위와 같은 네 가지 방법으로 해결해줄 수 있다.
// }



class Base {
public:
    int m;
    Base(int m) : m(m) {
        cout << "Base(" << m << ")" << endl;
    }
};

// 최상위 부모를 상속받는 자식들의 상속시에 virtual을 붙여준다.
class BaseA : virtual public Base {
public:
    BaseA() : Base(10) {
        cout << "BaseA" << endl;
    }
};

class BaseB : virtual public Base {
public:
    BaseB() : Base(20) {
        cout << "BaseB" << endl;
    }
};

// 위와같이 virtual로 상속을 선언해주면, 가장 밑에있는 Derived가 최상단 부모의
// 생성자를 선택해줘야한다. 아래와 같은 경우를 살펴보면, 따로 Base의 생성자를 지정해주지 않는다.
// 생성자를 지정해주지 않으면 파라미터가 없는 default생성자를 호출하게 되는데
// 현재 Base의 경우 int m 을 파라미터로 받는 생성자가 명시되어있으므로, default생성자가 없다.
// 그러므로 아래 코드는 컴파일되지 않는다.
/* class Derived : public BaseA, public BaseB {
public:
    Derived() {
        cout << "Derived" << endl;
    }
}; */

// 모양이 정해져 있는 Base 생성자에 인자값을 넣어서 호출하라고 명시
class Derived : public BaseA, public BaseB {
public:
    Derived() : Base(30){}
};

int main() {
    Derived d;
    cout << d.BaseA::m << endl; // 30
    cout << d.BaseB::m << endl; // 30
    cout << d.m << endl; // 30
 /* Base(30)
    BaseA
    BaseB
    Derived
    30
    30
    30 */
    // 위와 같이 Base는 단 한 번 호출되었고, BaseA와 BaseB의 m, d의 m 모두 30이 나왔다.

    // 중간 상속에서 virtual을 선언해주면, Derived에서 객체를 생성할 때 최상단 Base의 생성자를
    // 선택해줘야 한다. 그리고 이에 대해서 나온 결과인 Base 객체를 BaseA, BaseB가 동시에
    // 가리키게 되므로, 결국 Derived는 BaseA쪽이든, BaseB 쪽이든 상관없이 같은 값을 갖게 된다.
    // 따라서 BaseB의 m, BaseA의 m, Derived의 m은 모두 같은 값을 가리키고 있게 된다.

    // 또한 virtual 선언을 하지 않았을 때는, Base타입 포인터나 레퍼런스로 Derived 객체를 가리키지 못한다.
    BaseA* ba = &d;
    Base* b0 = ba;

    BaseB& bb = d;
    Base& b1 = bb; // 이와같이 중간에 어떤 녀석을 부모로 할 것인지에 대한 명시가 필요하다.

    // virtual 선언을 해주면 Base 타입 포인터나 레퍼런스로 Derived 객체를 직접 가리킬 수 있게 된다.
    Base* b2 = &d;
    Base& b3 = d;
}