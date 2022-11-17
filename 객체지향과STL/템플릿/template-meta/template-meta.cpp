#include <iostream>

using std::cout;
using std::endl;


// template이 아닌 일반 factorial 함수
// int factorial(int value) {
//     if (value == 1){
//         return value;
//     }
//     return value * factorial(value-1);
// }

// // template 메타 프로그래밍을 이용하면, 컴파일 타임에 factorial 함수를 만들어줄 수 있다.
// template<int N>
// struct Factorial {
// // Q1 : 왜 static일까?
// // static을 사용해야 Factorial<N> "타입에 대한 변수" 로서 접근할 수 있다.
// // Q2 : 왜 const일까?
// // struct나 class 내의 static변수는 내부적으로 초기화가 불가능하다.
// // 그래서 const로 선언하여 상수화함으로 컴파일타임에 그 값이 정해질 수 있도록 한 것이다.
// // Q3 : const 타입은 변경이 안되는데 어떻게 N을 변경해가면서 struct를 만드는 것일까?
// // 사실상 아래 단계에서는 Factorial N, N-1, N-2 이렇게 계속해서 다른 struct 타입을 만들어주는 것이다.
// // 하나의 타입에서 객체를 만드는 것이면 static const값을 바꿀 수 없지만, N 값에 따라
// // 계속해서 새로운 struct 타입을 만들어주고, 그 안에 static const int값이 들어가기 때문에 가능하다.
//     static const int value = N * Factorial<N-1>::value;
// };
// // 탈출조건 -> 특수화를 통해서 만들어줌
// template<>
// struct Factorial<1> {
//     static const int value = 1;
// };

// int main() {
//     cout << factorial(5) << endl;
//     // cout << Factorial<5>::value << endl;
//     cout << Factorial<5>::value << endl;
// }

// 기존 피보나치 함수
// int fib(int value) {
//     if (value <= 1) {
//         return value;
//     }
//     return fib(value - 1) + fib(value - 2);
// }

// int main() {
//     cout << fib(5) << endl;
// }

// template meta programming을 이용한 피보나치

template<int N>
struct Fibonacci {
static const int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

// 특수화를 사용한 탈출조건
template<>
struct Fibonacci<0> {
static const int value = 0;
};

template<>
struct Fibonacci<1> {
static const int value = 1;
};

int main() {
cout << Fibonacci<7>::value << endl;
}