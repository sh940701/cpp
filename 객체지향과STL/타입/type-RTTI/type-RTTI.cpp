#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

// class Parent {
// public:
//     virtual ~Parent() {}
// };

// class Child : public Parent {

// };

// int main() {
//     Parent* p = new Child;
//     cout << typeid(*p).name() << endl;
//     Child* cp = dynamic_cast<Child*>(p);
// }


// RTTI를 사용하게 하는 정보들이 어디에 저장되어있을까? -> 가상함수 테이블의 0번
// 가상함수 테이블이 없다는 것은, 아래 Parent에서 virtual함수가 하나도 없다는 것이다.

class Parent {
public:
    // virtual ~Parent() {}
};

class Child : public Parent {

};

int main() {
    Parent* p = new Child;
    // 가상함수 테이블이 없으면, 다형성이 없음 에러가 발생하며 실행이 안된다.
    Child* cp = dynamic_cast<Child*>(p); // error
    // 가상함수 테이블이 없으면, Parent 타입이라고 나온다.
    cout << typeid(*p).name() << endl;
}