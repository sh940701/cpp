#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

using std::cout;
using std::endl;

// void goo(int&& value) {
//     cout << "goo(int&&)" << endl;
// }

// void goo(int& value) {
//     cout << "goo(int&)" << endl;
// }

// void foo(int&& value) { // parameter == LValue
//     // value 는 RValue ref로 받는 LValue이기 때문에 goo(int&)로 가게 된다.
//     // goo(value); // int&
//     // std::move()를 통한 캐스팅으로 RValue로 바꿔 넘겨줄 수 있다.
//     goo(std::move(value)); // int&&
// }

// // 아예 LValue를 받으면 LValue로 넘겨주고, RValue를 받으면 RValue로 넘겨주는 함수를 따로 만들수도 있다.
// void foo(int& value) {
//     goo(value); // int&
// }

// // 그러나 위와 같은 방법은, LValue와 RValue 파라미터를 여러개 가지고 있게 되는 경우
// // 매번 상황별 함수를 만들어줘야 하고, 이는 불필요한 작업의 반복이 되는 것이다.

// int main() {
//     // 아래와 같이 실행했을 때, 최종적으로 LValue 함수에 들어가게 된다.
//     // 함수에서 파라미터로 받는 녀석은 결국 LValue가 되기 때문이다.
//     // RValue reference로 받는 녀석은 결국 LValue임과 같은 맥락이다.
//     foo(10);
//     int num = 10;
//     foo(num);
// }



// int main() {
//     // std::move()는 LValue와 RValue를 모두 인자로 받을 수 있다. 그런데 move함수는 하나다.
//     // move함수는 실제로 move(_Tp&& __t) 이렇게 파라미터를 받는다. 그런데 어떻게 LValue가 들어갈까?
//     // move함수에서 사용하는 &&는 RValue ref가 아니다. 타입을 추론해야 하는 상황에서 &&는
//     // R/LValue를 모두 나타낼 수 있으며, 이를 universal reference(보편 참조)라고 한다.
//     // 타입 추론은 auto에서도 일어나는데, auto&& 또한 RValue ref가 아닌 보편 참조이다.
//     std::move(10);
//     int num = 10;
//     std::move(num);
// }




// 그렇다면, 보편참조를 통해 추론한 T는 대체 어떤 타입인걸까?
// template<typename T>
// void foo(T&& value) {
//     cout << std::boolalpha;

//     cout << "lvalue ref T : " << std::is_lvalue_reference<T>::value << endl; // T -> int&
//     cout << "rvalue ref T : " << std::is_rvalue_reference<T>::value << endl;

//     cout << "lvalue ref T& : " << std::is_lvalue_reference<T&>::value << endl; // T& -> int& & -> int&
//     cout << "rvalue ref T& : " << std::is_rvalue_reference<T&>::value << endl;

//     cout << "lvalue ref T&& : " << std::is_lvalue_reference<T&&>::value << endl; // T&& -> int& && -> int&
//     cout << "rvalue ref T&& : " << std::is_rvalue_reference<T&&>::value << endl;
// }

// int main() {
//     int num = 10;
//     foo(num);
//     cout << endl;

//     int& num0 = num;
//     foo(num0);
//     cout << endl;

//     foo(10);

//     // RValue를 인자로 보냈을 때는 결과값이 조금 다르다.

//     // RValue로 넘겼을 때, T는 reference 타입이 아니다.
//     // lvalue ref T : false -> int
//     // rvalue ref T : false -> int

//     // lvalue ref T& : true -> int & -> int& 여서 LValue이다.
//     // rvalue ref T& : false

//     // lvalue ref T&& : false
//     // rvalue ref T&& : true -> int && -> int&& 여서 RValue이다.
    
//     cout << endl;
// }

// 타입 붕괴 규칙
// & -> &
// && -> &&
// && & -> &
// & && -> &
// && && -> &&



// int main() {
//     std::vector<int> v;
//     v.push_back(10);

//     int num = 10;
//     v.push_back(num);
    
//     // 위에서 첫번째 push_back은 다음과 같이 구성되어 있다. push_back(value_type&& __x)
//     // 그렇지만 여기선 &&가 붙었다고 해서 보편 참조인 것이 아니다.
//     // 이전에 vector<int>를 선언했을 때 이미 요소의 타입이 정해졌기 때문이다.
//     // 결국 push_back을 할 때는 타입 추론이 따로 발생하지 않기 때문에 보편 참조가 아니다.
//     // push_back에서의 && 는 단순히 RValue reference이다.

//     // 두 번째 push_back은 구성이 다르다. push_back(const_reference __x)
//     // 이 녀석은 LValue reference를 받는다고 생각하면 된다.
// }


void goo(int& value) {
    std::cout << "int&" << std::endl;
}

void goo(int&& value) {
    std::cout << "int&&" << std::endl;
}

// 타입 추론을 통해 RValue를 받을 수는 있지만, 내부적으로 함수를 호출하면 다시 LValue가 된다.
// 이런 경우, 보낼 때 다시 RValue로 캐스팅을 해주면 된다.
template<typename T>
void foo(T&& value) {
    // 이런 것을 perfect forwarding, 완벽 전달이라고 한다.
    goo(static_cast<T&&>(value));
    // 위와같이 static_cast<T&&>도 가능하지만, 아래와 같이 std::forward를 사용하여
    // 완벽 전달을 위해 캐스팅을 진행한다고 명시적으로 알려줄 수도 있다.
    goo(std::forward<T>(value));
}

int main() {
    foo(10); // int&&
    int num = 10;
    // LValue로 보내도 잘 간다.
    // 캐스팅을 해줄 때, int& + && 는 int&이기 때문
    // 마찬가지로 RValue는 int로 가고, int + && 는 int&& 이기 때문에 잘 되는 것이다.
    foo(num); // int&
}