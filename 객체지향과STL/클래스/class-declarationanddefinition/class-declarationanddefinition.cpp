#include <iostream>
#include <string>

using namespace std;

// 함수의 선언
// void func();

// int main() {
//     func(); // 선언만 있어도 컴파일 가능
// }

// // 함수의 정의
// void func() {
//     cout << "Func" << endl;
// }

// int main() {
//     // 아래와 같은 경우는, 정의가 포함된 선언이라고 할 수 있다.
//     int x = 10;
//     // 선언만 되었을 뿐이지만, 바로 사용을 할 수 있기 때문
//     x = 10;
//     x = 20;
// }

// void func();

// int main() {

// }

// void func() {
//     cout << "Func" << endl;
// }

// main에서도 Person.h를 사용하기 위해 include해준다.
// 이 때 <>로 include는 시스템에서 지원되는 header들을 include할 때 사용되고
// 우리가 만든 user defined header 파일은 큰따옴표로 표시해준다.
// #include "Person.h"

// int main() {
//     Person person = {74, 182.1, "david"};
//     person.print();
//     // 현재 Person.h 파일에 foo 함수도 정의되어있기 때문에 foo 함수를 사용할 수 있다.
//     foo();
// }

#include "Person.h"

int main() {
    // 이제 아래에 나열되어있는 Person함수와 print함수, foo함수는
    // 선언은 Person.h 파일에서 복붙, 정의는 Person.cpp파일을 통해 전역적으로
    // 컴파일되어 사용할 수 있는 상태이다.
    Person person = {74, 182.1, "david"};
    person.print();
    foo();
}