#include <iostream>

using std::cout;
using std::endl;

// noexcept 함수에서 throw 이벤트가 발생하면 terminate를 실행한다.
// noexcept는 false 혹은 true 값을 주어 활성화/비활성화를 정할 수 있다.
// void func() noexcept(true) {
//     throw 1;
// }

// int main() {
//     try {
//         func();
//     // noexcept 함수에서 발생한 throw는 catch가 불가능하다.
//     } catch (int e) {
//         cout << e << endl;
//     }
// }

// void func() noexcept {
//     throw 1;
// }

// // 아래와 같이 noexcept를 연쇄적으로 지정해줄 수 있다.
// // 만약 func가 noexcept(false)이면 main도 noexcept(false)이다. -> 컴파일타임에 정해짐
// int main() noexcept(noexcept(func())) {
//     try {
//         func();
//     } catch (int e) {
//         cout << e << endl;
//     }
// }

// noexcept는 사실상, 함수의 시그니쳐이다.
// 함수 포인터를 만들 때 noexcept 함수에 대한 포인터에 noexcept를 지정해줄 수도 있다.
// 함수가 noexcept가 아닐 때는 함수 포인터에 noexcept를 지정해줄 수 없다.
// void func() noexcept {
// }

// int main() {
//     // 함수 포인터 생성
//     void(*fp)() noexcept = func;
// }

// 연쇄 noexcept

// void func0() noexcept {

// }

// void func1() noexcept {

// }
// // main에서 func0, func1만 실행한다고 할 때, 두 함수가 모두 noexcept(true)이면
// // main함수 또한 noexcept라는 것을 아래와 같이 나타낼 수 있다.
// int main() noexcept(noexcept(func0()) && noexcept(func1())) {

// }

