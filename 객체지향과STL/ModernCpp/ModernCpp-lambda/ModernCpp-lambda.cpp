#include <iostream>
#include <functional>

using std::cout;
using std::endl;

// int main() {
//     // 람다의 생김새
//     // 파라미터가 없으면 소괄호 생략 가능
//     // auto func = []() // -> 화살표를 사용하여 반환형도 넣을 수 있음
//     // {

//     // };
//     // func();


//     // 람다의 캡쳐
//     int value = 10;
//     [value]() {
//         cout << value << endl;
//     }(); // 좌측과 같이 바로 실행도 가능

//     [](int value) {
//         cout << value << endl;
//     }(value); // 좌측과 같이 파라미터로 받을 수도 있음
// }


// 어떤 곳에 함수를 넘길 때, 아래와 같이 타입의 강제를 하게 될 것이다.
// 반환 및 파라미터 형태 등 -> 파라미터를 강제하는 경우, 람다 객체를 유용하게 사용할 수 있다.
// void foo(std::function<void(void)> func) {
//     func();
// }

// int main() {
//     int value = 10;
//     // 아래와 같은 경우, 파라미터의 타입과 위에서 지정한 타입이 맞지 않아 컴파일 에러가 생긴다.
//     // 이런 경우에, 캡쳐 기능을 사용하여 해결해줄 수 있다.
//     // 레퍼런스로 캡쳐를 하면, 내부적으로 value를 바꿀 수 있다. 그런데 레퍼런스가 아니라면
//     // 아예 내부적으로 값을 바꿔줄 수 없다. 이럴 때는 소괄호 옆에 mutable을 붙여준다.
//     // 그럼 내부적으로만 값이 바뀌고 밖에서는 값이 바뀌지 않는다.
//     auto func = [&value] { // (int param) 삭제
//         std::cout << value << endl; // 10
//         value = 20;
//     };
//     foo(func);
//     cout << value << endl; // 20
//     // 캡쳐시 &를 붙이면 레퍼런스로 받을 수 있음
// }



// 람다는 사실상, 함수객체다. 함수객체를 쉽게 만들어주는 syntatic sugar와 같다고 볼 수 있다.
// struct Func {
//     // 캡쳐한 value가 아래와 같이 멤버변수로 들어간다고 생각하면 된다.
//     int value;
//     void operator()() const {

//     }
// };

// int main() {
    // int value = 20;
    // Func func;
    // func.value = 10; // 람다에서의 캡쳐와 같다.

    // // auto func = [value]() // 위 함수객체 ()operator에서 const가 있는 상태가 현재이다.
    // auto func = [value] () mutable // 위 함수객체 함수에서 const를 지워준 상태와 같다.
    // { 
    //     cout << value << endl;
    // };
    
    // cout << value << endl;
// }


// 그렇다면 왜 기본값이 변경 불가이고, mutable을 붙여줘야만 변경할 수 있는 것일까?
// int main() {
//     int num = 10;
//     auto func = [num]() mutable {
//         ++num;
//         return num;
//     };
//     // 일반적으로 변수를 넣고 같은 함수를 두번 실행하면 둘 다 같은 값이 나올 것이라고 생각한다.
//     // 그러나 아래에서는 지속적으로 증가하는 결과값을 리턴한다.
//     // 이런 부분에 대한 실수를 방지하기 위해 기본적으로 변경이 불가하게 해놓은 부분도 있다.
//     // 또한 함수객체에서의 operator 오버로딩이 기본적으로 const로 이루어지기 때문이기도 하다.
//     cout << func() << endl; // 11
//     cout << func() << endl; // 12
// }


