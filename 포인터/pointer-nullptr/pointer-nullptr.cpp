#include <iostream>

using namespace std;

int main() {
    // pointer를 초기화할 수 없는 경우, 무엇을 넣을지 아직 안 정해진 경우
    // int* p = nullptr;
    // cout << p << endl; // 0x0

    // 동적 할당을 해준 경우
    // int* p = new int;
    // 동적 할당 후에 지웠다.
    // delete p;

    // 그런데 코드 어딘가에서는 p가 지워졌는지 안 지워졌는지 알 수 없고
    // 아래와같이 다른 값을 할당해줄 수도 있다.
    // int num = 0;
    // p = new int;

    // p = &num;
    // p에 유효한 포인터가 있는지 없는지 알 수 없는 경우가 있다.

    // int* p = new int;
    // delete p;
    // p = nullptr;

    // // 이후 사용할 때는 p에 값이 들어있는지를 두고 판단하면 된다.
    // if(p != nullptr) // p가 nullptr이 아닌지(true인지)
    // if (p) // p에 값이 들어있는지(true인지)\

    // nullptr은 사실 std::nullptr_t 타입의 상수이다.
    // std::nullptr_t a;
    // boolean 타입의 값은 true/false밖에 없는 것 처럼 std::nullptr_t타입의 값은 nullptr밖에 없다.
    
    // 이 타입은 특별취급을 해주어, 어떤 타입으로든 변환을 할 수 있게 된다.
    // float* fp = new float;
    // int* p = fp;
    nullptr_t n;
    int* p = n;
}