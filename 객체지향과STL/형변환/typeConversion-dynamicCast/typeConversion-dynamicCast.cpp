#include <iostream>

using std::cout;
using std::endl;

// class Parent {
// public:
//     // 변수가 부모 타입의 ref, pointer 형태일 때, 가리키는 것이 자식 클래스 객체라면 부모 클래스 type의 pointer가
//     // 삭제되는 경우, 소멸자를 virtual로 선언해주지 않으면, 자식 클래스의 소멸자는 호출되지 않는다.
//     // virtual이 없으면, 함수가 호출될 때 static binding이 되어서 pointer가 실제로 가리키는 객체 타입이 아니라
//     // 그저 나타나있는 pointer 변수의 타입에 대해서만 소멸자를 실행하기 때문이다.
//     // virtual을 써야, 실제 가리키고 있는 타입의 함수를 호출한다.
//     virtual ~Parent(){}
// };

// int main() {
    
// }


// class Parent {
// public:
//     virtual ~Parent(){}
    
// };

// class Child : public Parent {
// public:
//     void func() {
//         cout << "func" << endl;
//     }
// };

// // 함수 내에서 p를 통해 Child의 func를 사용하고싶다. 실제로 현재 p는 Child를 가리키고 있지만, 
// // 함수에서는 컴파일타임에 인식하지 못하여 Child::func()에 접근하지 못한다.
// // 만약 virtual로 override된 함수라고 하면 virtual function table에서 실제 가리키고 있는
// // Child의 func에 접근이 가능하겠지만, 현재는 그렇지 않은 상황이다.
// // 그런 상황을 타개하기 위해 아래에서는 내부적으로 dynamic_cast를 사용하여 Parent* p를
// // Child* 타입으로 변경하여 함수에 접근하게 된다.
// void foo(Parent* p) {
//     Child* child = dynamic_cast<Child*>(p);
//     // 만약 실제 p가 가리키고 있는 타입이 Child가 아니고 Parent라면, 그러니까 dynamic_cast<Type>(Var)에서
//     // Type과 Var의 실제가리키고 있는 타입이 다르다면 ===> dynamic_cast의 결과값인
//     // child는 null이 나오게 된다. 따라서 아래와 같이 예외처리를 해줄 수 있다.
//     if (child != nullptr) {
//         child->func();
//     }
// }

// int main() {
//     Parent* p = new Child;
//     // 만약 p가 new Child가 아니라 new Parent, 그러니까 실제로 Parent type이라면
//     // foo 함수에서 dynamic_cast를 사용하여 Child*로 변경 후 함수를 사용할 때 어떻게 될까?
//     // 그러한 경우 "값을 보장할 수 없는 상태"가 된다.
//     foo(p);
// }

// class Parent {
// public:
//     int num = 3;
//     virtual ~Parent(){}
    
// };

// class Child : public Parent {
// public:
//     int num2 = 6;
//     void func() {
//         cout << "func" << endl;
//     }
//     virtual void func3() {
//         cout << "child" << endl;
//     }
// };

// void foo(Parent* p) {
//     // pointer로 받을 때, 실제 가리키고 있는 값이 아니면 nullptr이 들어간다고 했는데
//     // 그렇다면 실제로는 Parent를 가리키고 있는 p를 dynamic_cast를 통해 Child(null이 없는)레퍼런스로 cast하면 어떻게 될까?
//     //  -> 런타임중 "abort"에러가 발생한다.
//     Child& child = dynamic_cast<Child&>(*p);

//     child.func();
// }

// class Parent {
// public:
//     int num = 3;
//     virtual ~Parent(){}
    
// };

// class Child : public Parent {
// public:
//     int num2 = 6;
// };

// 업캐스트
// int main() {
//     Parent* p = new Child;
//     Child* c = dynamic_cast<Child*>(p);

//     cout << p->num << endl; // 3 -> parent에 num이 있으므로 런타임 정상실행
//     cout << p->num2 << endl; // 컴파일타임에 Parent class에 num2가 없으므로 컴파일불가.

//     cout << c->num << endl; // 3 -> Child에 parent에서 받은 num이 있으므로 런타임 정상실행
//     cout << c->num2 << endl; // 6 -> Child에 스스로 num2가 있으므로 런타임 정상실행
// }

// 다운캐스트
// int main() {
//     // Parent* p = new Parent;
//     Parent p;
//     Child* c = dynamic_cast<Child*>(&p);
//     cout << c << endl; // 0x0
//     // cout << p->num << endl; // 3
//     // cout << p->num2 << endl; // 컴파일타임에 Parent class에 num2가 없으므로 컴파일불가.

//     cout << c->num << endl; // abort -> c의 주소값이 0x0임으로 인한 런타임 에러
//     cout << c->num2 << endl; // aobrt -> c의 주소값이 0x0임으로 인한 런타임 에러
// }


// Diamond 상속 형태에서 dynamic casting
// class A {
// public:
//     virtual ~A(){}
// };

// class B0 : public A {};

// class B1 : public A {};

// class D : public B0, public B1 {};

// int main() {
//     // 최하위 D클래스 객체 생성
//     D d;

//     // D클래스 객체를 B0 스타일 포인터로 업캐스팅
//     B0* b0 = &d;

//     // b0 포인터를 B1스타일 포인터로 크로스 캐스팅
//     B1* b1 = dynamic_cast<B1*>(b0); // 결과적으로 D d가 담겨있다.
// }

// virtual이 없을 때 -> static_cast
class A {
public:
    virtual ~A(){}
};

class B0 : public A {};

int main() {
    // virtual이 없을 때, static_cast를 사용할 수도 있다. 그런데 static_cast를 사용시 큰 문제가 생길 수 있다.
    // 아래와같이 A* a에 new B0를 담고 이를 다시 B0* 타입으로 다운캐스팅한다면, B0타입으로 쓰여진 메모리를
    // B0스타일로 읽게 되는 것이니 dynamic이나 static이나 다르지 않다.
    // 그런데 A* a 에 new A를 담게 된다면 문제가 생긴다.

    // 이럴 때 Dynamic cast의 경우, 런타임에서 동적으로 검사를 하여, 현재 캐스팅하려고 하는 값이 B0 스타일로
    // 읽을 수 없다는 것을 파악하고, 0x0값을 반환한다. 그러므로 이에 대한 예외처리를 해 주면 된다.
    // 그러나 static cast는 이미 "a의 값을 b0으로 casting한다."고 컴파일때 정해놓고 런타임 검사가 없기 때문에
    // b0에 a의 주소값이 그대로 들어가게 된다. A타입으로 저장되어있는 메모리를 B0 스타일로 읽게 되는 것이다.

    // 만약 아래와 같은 과정을 통해 B0에만 있는 int num 이라는 멤버변수를 변경하고자 한다면
    // dynamic_cast의 경우 런타임 예외처리를 통해 잘못 들어가있다는 것을 바로 알 수 있지만
    // static_cast의 경우 A타입에는 존재하지 않는 num이라는 변수에 대한 연산을 진행하게되고
    // 이로 인해 예측할 수 없는 문제가 발생할 수 있다.

    // A* a = new B0;
    A* a = new A;

    B0* b0 = static_cast<B0*>(a); // virtual이 없어도 가능
    B0* b1 = dynamic_cast<B0*>(a);

    // A* a = new B0일 때는 아래 세 개의 출력이 모두 같은 주소값이다.
    cout << a << endl; // 0x12d6069d0
    cout << b0 << endl; // 0x12d6069d0
    cout << b1 << endl; // 0x0
}