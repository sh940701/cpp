#include <iostream>

using std::cout;
using std::endl;

// int func(float x) {
//     return 10;
// }

// struct Person {
//     float weight;
//     float height;
// };

// int main() {
//     decltype(1) num0 = 10; // num의 타입은 int

//     decltype(num0) num1 = 20; // int
//     decltype(num1)& num2 = num1; // int&

//     const decltype(num0) num3 = 10; // const int
//     const decltype(num0)& num4 = 10; // const int&

//     decltype((num0)) num5 = num0; // int& -> 괄호를 한 번 더 붙여주면 레퍼런스로 추론이 됨
//     decltype(1 + 22.2f) num6 = 1.f; // float

//     int nums0[] = {1, 2, 3};
//     auto nums1 = nums0; // int*
//     decltype(nums0) nums2 = {1, 2, 3}; // int 요소가 3개인 배열 타입. -> nums0대입은 안된다.
//     // 배열끼리 = 연산자 사용은 불가능하기 때문

//     auto f = func; // 함수포인터 int (*f)(float x)
//     decltype(func) ff; // int f(float x) 함수의 선언을 한 것 -> 정의를 해줘야 사용가능하다.
//     // cout f(10.0f) << endl; // error -> 정의가 없으면 에러 발생

//     decltype(func)& f0 = func;
//     cout << f0(10.f) << endl; // 10

//     decltype(func)* f1 = func;
//     cout << f1(10.f) << endl; // 10

//     decltype(f1(10.1f)) num7; // 내부 함수의 반환값이 int이기 때문에 num7의 타입은 int이다.
//     // 위에서 함수가 실행되는 것은 아니다. 단순히 컴파일타임에 어떤 타입이 나오는지 추론하는 것

//     Person p;
//     decltype(p.weight) weight0; // float
//     decltype(Person::weight) weight1; // float
// }



struct Wrapper0 {
    int value;
    // 값으로 리턴하는 함수
    int getValue() const {
        return value;
    }
};

struct Wrapper1 {
    float value;
    // 레퍼런스로 리턴하는 함수
    float& getValue() {
        return value;
    }
};

template<typename T>
// 아래 세 가지 decltype() 대입이 모두 가능하다.
// auto getValue(T& t) -> decltype(t.getValue())
// auto getValue(T& t) -> decltype(auto)
decltype(auto) getValue(T& t)
{
    return t.getValue();
}

int main() {
    int num0 = 10;
    auto num1 = 20;
    decltype(num0) num2; // int
    decltype(auto) num3 = 30; // int -> 우측 항(30)의 타입을 추론하여 auto에 들어간다.

    Wrapper0 w0{0};
    Wrapper1 w1{1};

    cout << getValue(w0) << endl; // 0
    cout << getValue(w1) << endl; // 1

    getValue(w1) = 10; // 이 값은 레퍼런스가 아니다. w1의 getValue는 레퍼런스를 반환하는데 왜일까?
    // 레퍼런스 타입을 auto로 치환할 때, auto는 레퍼런스가 아닌 값으로 추론되기 때문이다.
    // 이를 해결하기 위해서 템플릿 함수의 반환값을 auto&로 하면 w0을 넣는 것이 안 된다.
    // 위와같은 문제를 decltype을 사용하여 해결할 수 있다.
}