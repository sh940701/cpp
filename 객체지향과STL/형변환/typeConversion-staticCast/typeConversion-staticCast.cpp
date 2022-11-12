#include <iostream>

using namespace std;

// class ClassA{};

// class ClassB{};

// int main() {
//     ClassA a;
//     // C style casting -> 서로 다른 클래스로 변경함으로, 정의되지 않은 행동을 할 수도 있어 위험하다.
//     ClassB* b0 = (ClassB*)&a;

//     // 위와같은 상황을 컴파일타임에 예방할 수 있도록 사용하는 것이 static cast이다.
//     // C style casting에선 되었던 것이, static cast를 이용하니 되지 않는다.
//     ClassB* b1 = static_cast<ClassB*>(&a);
// }

class ClassA{};

class ClassB{};

// int main() {
//     float f = 1.1f;
//     // 아래와 같이 서로 다른 타입의 형변환을 지원 및 검사해준다.    
//     int i = static_cast<int>(f); // 정상

//     // 포인터나 레퍼런스 타입에 대해서는 다른 타입끼리 형변환이 불가하다.(상속관계 제외)
//     int* i0 = static_cast<int*>(&f); // error

//     // float을 int로 바꾸나, float pointer를 int pointer로 바꾸나 같은 것이 아닐까 생각이 드는데
//     // 실제로 float을 int로 casting하면 narrowing conversion이 이루어져 소수점부분을 버리게 되는데
//     // 이때는 형변환을 이용하여 i의 위치에 1을 넣어주는 것이다.
//     // float 포인터를 int 포인터로 바꾼다는 것은 float 데이터가 담겨있는 메모리의 주소 &f를
//     // i에 담게 되는 것이고, 그 주소값에 있는 float 1.1에 대한 메모리 배열을 integer형태로 해석을 하게 되는 것이다.

//     // float type pointer
//     float* f = new float;
//     // assign value
//     *f = 10.3f;
//     cout << *f << endl; // 10.3

//     // C style casting
//     int* i = (int*)f; // 컴파일 됨
//     cout << *i << endl; // 1092930765 -> float 타입 메모리 데이터를 int 타입으로 읽게 되어 예상 못한 값이 나옴

//     int* i0 = static_cast<int*>(f) // error -> 위와같은 상황을 방지하기위해 컴파일타임에 에러 발생   
// }

// enum의 static_cast

// enum class TypeA {
//     A, B, C
// };

// enum class TypeB {
//     A, B, C
// };

// int main() {
//     TypeA typeA = static_cast<TypeA>(0);
//     // enum을 정수형으로 변환할 때, 만약 enum의 int 값이 int의 범위를 초과하면, 에러가 발생할 수 있음 주의.
//     cout << static_cast<int>(typeA) << endl; // 0

//     // enum끼리 static_cast도 가능하다.
//     TypeB typeB = static_cast<TypeB>(typeA);
//     cout << static_cast<int>(typeB) << endl; // 0
// }

// 변환 생성자를 사용할 때의 static_cast

// class Test {
// public:
//     explicit Test(int num) {}
    
//     // 변환 연산자도 static cast로 사용해줄 수 있다.
//     explicit operator bool() {
//         return true;
//     }
// };

// int main() {
//     // 아래의 경우, int인 1이 암시적으로 Test type으로 변환된다.
//     // 다만 아래는 암시적 형변환 생성으로, explicit를 붙이면 형변환 생성이 불가하다.
//     Test t0 = 1;

//     // 이 또한 static_cast로 진행해줄 수 있다. -> 이렇게 하면 위 변환 생성자를 호출한다.
//     // explicit가 붙어있어도, 명시적 형변환 생성이기 때문에 정상적으로 작동한다.
//     Test t1 = static_cast<Test>(1);
    
//     // 아래 형변환 또한 암시적 형변환이므로 explicit가 있으면 진행되지 않는다.
//     bool b0 = t1;

//     // static_cast를 사용하면 explicit가 있는 형변환 연산자도 정상적으로 작동한다.
//     bool b1 = static_cast<bool>(t1);
// }


// 부모/자식 클래스간 static_cast

class Parent{};

class Child : public Parent {};

int main() {
    // public 상속 관계에서 부모 클래스로 자식 클래스를 가리키는 것
    // 암시적 / static_cast 둘 다 가능하다.
    Child c;
    Parent& p0 = c;
    Parent& p1 = static_cast<Parent&>(c);

    // 암시적 형변환에서 자식 클래스로 부모 클래스를 가리킬 수는 없다.
    Parent p;
    Child& c0 = p; // error
    // 그러나 static cast를 사용하면 자식 클래스 ref나 pointer로 부모 클래스를 가리킬 수 있다.
    // 컴파일타임에 상호간 호환이 되기 때문에 이런 것이 가능한데, 런타임에서 문제가 발생한다.
    Child& c1 = static_cast<Child&>(p); // 정상

    // 이렇게 될 경우, 해당 pointer나 ref를 사용하여 부모에는 없고 자식에만 있는 멤버에 접근하려하면
    // 쓰레기값이 나오게 된다. -> 이러한 경우를 방지하기 위해 dynamic_cast를 사용하게 된다.
    // 자식으로 부모를 가리키는 것을 down cast라고 하는데, 이런 특이한 경우를 제외하면
    // static cast가 효과적으로 작동하는 것을 알 수 있다.
}