#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

// 피보나치 수열을 constexpr로 만들어보자.
// 만약 함수가 컴파일 타임에 평가가 끝난다고 하면, 컴파일 하는 도중 연산을 끝내고 
// 그 결과값만을 넣어버린다.
// 만약 user가 num값을 넣어주거나 하는 경우, 컴파일타임에 값을 알 수 없게 된다.
// 이런 경우에는 런타임 도중 계산을 해준다.

// constexpr int fib(int num) {
//     return num <= 1 ? num : fib(num - 2) + fib(num - 1);
// }

// template<int N>
// void print() {
//     cout << N << endl;
// }

// int main() {
//     constexpr int value = fib(10);

//     cout << value << endl;

//     // 만약 위 값이 컴파일 타임에 나왔다면, 아래와 같이 배열의 길이로 사용이 가능해야 한다.
//     // template에도 사용이 가능해야 한다. 현재 아래는 안된다.
//     // int value앞에 constexpr을 붙여주면 가능해진다.
//     int nums[value] = {1, 2, 3};
//     print<value>();
// }



// constexpr long long fib(long long num) {
//     // return num <= 1 ? num : fib(num - 2) + fib(num - 1);

//     // fib함수를 바꿔보자

//     if (num <= 1) {
//         return num;
//     }
//     long long prev = 0;
//     long long curr = 1;

//     for (int i = 2; i <= num; ++i) {
//         long long next = prev + curr;
//         prev = curr;
//         curr = next;
//     }
//     return curr;
// }

// int main() {
//     constexpr long long value = fib(50); // -> recursive 단계가 너무 많아져서 안됨
//     // fib 함수를 바꾼 뒤 다시 실행해보자
//     // constexpr long long value = fib(50);

//     cout << value << endl;
// }


// struct Test {
//     // 안에 있는 녀석이 다 literal -> 암시적으로 constexpr 생성자가 있음
//     int i;
//     float f;
// };

// struct Item {
//     // 만약 아래 녀석이 std::string등의 타입이었다면 안된다. -> 리터럴 타입이 아니기 때문
//     int power;
//     constexpr Item(int power) : power(power) {}
//     // 아래 operator는 받는 녀석과 리턴타입이 모두 literal type을 갖는 객체이기 때문에 가능하다.
//     constexpr Item operator+(const Item& other) const {
//         return Item(power + other.power);
//     } 
// };

// int main() {
//     // 아래 item들의 의 값도 상수시간에 다 정해져버림
//     constexpr Item item0(10);
//     // 암시적으로 constexpr기본 생성자가 있기 때문에 아래와 같이도 생성할 수 있다.
//     constexpr Item item1{20};
//     constexpr Item newItem = item0 + item1;

//     // 정적 배열의 길이에 newItem.power를 대입할 수 있다. -> 컴파일 타임에 정해졌다.
//     int nums[newItem.power] = {1, 2, 3};
// }

// literal type data -> constexpr 생성자를 가지고 있음
// 1, 2, 'c'

// constexpr constructor -> 멤버들이 literal type이어야 constexpr생성자를 만들 수 있다.


// constexpr if

// 형식 : if constexpr (...) {}

// template<typename T>
// auto getValue(T t) {
//     // 아래에서 constexpr이 있으면 잘 되지만, 없으면 에러가 발생한다.
//     if constexpr (std::is_pointer<T>::value) {
//         // 포인터라면 디레퍼런싱하여 리턴
//         return *t;
//     } else {
//         // 포인터가 아니라면 그대로 리턴
//         return t;
//     }
// }

// int main() {
//     int num = 10;
//     int* pNum = &num;

//     // 아래에서 함수를 실행할 때, int type에 대한 함수를 구체화 시키게 된다.
//     // 이 때 int라면, 위에서 return *t를 실행하는 부분은 싹 날려버린다.
//     // 반대로 int* 라면, 위에서 return t를 실행하는 부분은 싹 날려버린다.
//     // 그렇기 때문에 auto에서 함수의 리턴타입에 대해서 한 가지만으로 추론이 가능한 것이다.
//     // 만약 constexpr이 없으면, 두 조건문이 모두 생성되어, 둘 중 어떤 타입을 리턴할지 추론이 불가하다.
//     cout << getValue(num) << endl;
//     cout << getValue(pNum) << endl;

//     // 만약 위 템플릿 함수의 리턴값이 auto가 아닌, void여도 문제가 생길 수 있다.
//     // 위와같이 실행할 때, constexpr if문이 아니라면, getValue(num)을 할 때 모든 조건문이 구체화된다.
//     // 그런데 num의 타입은 포인터가 아닌데, 첫번째 if문은 파라미터를 디레퍼런싱하는 것이기 때문에
//     // 문제가 되어 실행이 안 되는 것이다.(사실 조건에 만족하지 못하여 내려가게 될 텐데 왜그런지는 모르겠당)
// }


// C++17 이후부터 람다에 constexpr사용이 가능하다.
// int main() {
//     auto func = [](int y) constexpr { // constexpr이 실제로는 생략되어있다.
//         return y;
//     };

//     // 컴파일타임에 계산이 되기 때문에 정적배열의 길이로 사용이 가능하다.
//     int nums[func(10)] = {1, 2, 3};
// }

int main() {
    auto func = [](int num) noexcept {
        return num * 10;
    };

    int nums[func(10)] = {1, 2, 3};
    cout << func(10) << endl; // 100
}