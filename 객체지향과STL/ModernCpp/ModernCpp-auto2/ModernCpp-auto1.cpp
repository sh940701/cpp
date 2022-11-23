#include <iostream>
#include <map>
#include <tuple>
#include <list>

using std::cout;
using std::endl;

// 아래와 같은 경우, 파라미터의 타입에 따라 계속해서 타입을 바꿔줘야 한다.
// C++ 17부터는 이 때도 auto를 사용할 수 있다.
// template<auto N0, auto N1>
// auto add() {
//     return N0 + N1;
// }

// template<auto... Args>
// // Fold Expression 식에 대한 반환값을 auto로 설정해줄 수도 있다.
// auto sum() {
//     return (Args + ...);
// }

// int main() {
//     cout << sum<1, 3000000000, 100000000>() << endl;
// }

// Fold Expression의 종류 : Args -> A로 표현함

// Args + ... -> unary RIGHT fold        : (A[0] + (A[1] + (A[2] + ... (A [n - 1] + A[n]))))
// ... + Args -> unary LEFT fold         : (((A[0] + A[1]) + A[2]) ... + A[n])
// Args + ... + B ->  binary RIGHT fold  : (A[0] + (A[1] + (A[2] + ... (A [n - 1] + (A[n] + B)))))
// B + ... + Args -> binary LEFT fold    : ((((B + A[0]) + A[1]) + A[2]) ... + A[n])


// structed binding declaration

// int main() {
//     std::map<int, std::string> m {
//         {1, "10"}
//     };
//     // iterator를 auto를 사용해서 가져오면, structed binding declaration을 사용할 수 있음
//     // pair를 unpack해주는 것이다.
//     const auto& [key, value] = *m.begin();
//     std:: cout << key << endl; // 1
//     std:: cout << value << endl; // 10

//     // 정적 배열에 대해서도 가능하다.
//     int nums[]{1, 2, 3};
//     auto& [x, y, z] = nums; // 만약 좌측 원소가 4개면 컴파일이 안된다.

//     cout << x << endl; // 1
//     cout << y << endl; // 2
//     cout << z << endl; // 3

//     // auto& 이기 때문에 x를 통해 원본 배열에 대한 변경도 가능하다.
//     x = 10;
//     cout << nums[0] << endl; // 10
// }


// int main() {
//     // tuple은 타입이 다른 녀석들을 묶어준다.
//     std::tuple<int, float, std::string> t0{1, 2.0f, "3"};
//     // 아래와 같이 make_tuple을 사용하여 타입 추론도 가능하다.
//     auto t1 = std::make_tuple(1, 2.0f, "3");

//     // 기존 tuple을 unpack하는 방법
//     int x0;
//     float y1;
//     std::string z2;
//     std::tie(x0, y1, z2) = t0;

//     cout << x0 << endl; // 1
//     cout << y1 << endl; // 2
//     cout << z2 << endl; // 3

//     // 기존 tuple의 개별 원소를 가져오는 방법
//     cout << std::get<0>(t0); // 1

//     // structed binding을 이용하여 unpack 하는 방법
//     // 레퍼런스로 선언하여 각각의 녀석들을 바꿔줄 수도 있음
//     auto& [x, y, z] = t0;
//     cout << x << endl; // 1
//     cout << y << endl; // 2
//     cout << z << endl; // 3
// }


// class Person {
// public:
//     float weight;
//     float height;

//     void func(){}
// };

// int main() {
//     Person p{64.f, 172.f};
//     auto [weight, height] = p;

//     cout << weight << endl; // 64
//     cout << height << endl; // 172
// }


// template<typename T>
// void foo(T t){
//     cout << typeid(t).name() << endl;
// }

// int main() {
//     // auto에서는 num3가 int type의 원소를 가진 initializer_list라는 타입 추론이 됨
//     auto num3 = {10, 20};
//     // template에서는 위와 같은 상황에서 타입 추론이 안 됨 -> num3로 넣어주면 되넹 ㅎㅎ
//     foo({10, 20}); // error
// }


template<typename T>
// return형에서 추론을 할 때, lambda에서 auto를 사용할 때
// 실제로 템플릿이 쓰이는, parameter와 return타입 위치로 auto가 갔을 때
// 즉 함수의 시그니처에서 사용이 될 때 template type parameter로 인식이 된다.
auto foo(T t){
    return {10, 20}; // template에서 처럼 추론 불가하다.
}

int main() {
    foo(1); // error
}