#include <iostream>

using namespace std;

// enum class Type {
//     A, B, C
// };

// int main() {
//     // int num0 = (int)Type::A; // C style casting
//     // int num1 = int(Type::A); // functional style casting
//     // // 실제로 Cstyle / functional style casting은 같다.
//     // // 그런데 C언어에서 위와 같은 casting 방법은 위험하다고 생각되어 나온 것이 C++의 casting방법들
//     // // static cast, const cast, reinterpret cast, dynamic cast
// }


// C style 캐스트는 아래와 같이 세 가지 캐스팅이 가능하다.
// enum class Type {
//     A, B, C
// };

// int main() {
//     int i = 10;

//     float& f = (float&)i; // reinterpret

//     const int& j = i;
//     int& k = (int&)j; // const cast

//     int& k0 = const_cast<int&>(j); // C++ 에서의 const cast
//     // 훨씬 목적성이 명확하고 알아보기 쉽다.

//     i = (int)Type::A; // static cast
// }

class Parent {
public:
    // 기본 생성자
    Parent() {}

    // 형변환 생성자
    explicit Parent(int j){}
};

int main() {
    Parent p;

    // 아래 생성자들은, int 를 받아서 Parent 객체를 생성하는 생성자이면서
    // 동시에 int type을 Parent type으로 변환하는 변환자이기도 하다.(?) -> 확실 안함
    // 근데 왜 10을 넣어 만든 객체를 int type으로 읽으면 쓰레기값이 나올까?
    // 잘 모르겠지만, 아무래도 int를 그냥 받기만 할 뿐, 이후 로직에서 어떤 저장 등의 처리를
    // 하지 않고 그냥 Parent 객체를 만들기만 해서 그런 것 같다아아앙

    int i = 10;

    p = Parent(i); // functional style cast

    cout << reinterpret_cast<int&>(p) << endl; // 쓰레기값

    p = (Parent)10; // C style cast
}