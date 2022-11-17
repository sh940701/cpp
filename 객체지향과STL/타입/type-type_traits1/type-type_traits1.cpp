#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

// is_pointer를 구현해보자
// 일반적인 type이 들어오면 is_pointer에 대하여 false 리턴
// template<typename T>
// struct is_pointer{
//     static const bool value = false;
// };

// // 포인터 타입이 들어오면 true를 리턴하도록 특수화
// template<typename T>
// struct is_pointer<T*> {
//     static const bool value = true;
// };

// int main() {
//     cout << std::boolalpha;
//     // type_traits의 is_pointer
//     cout << std::is_pointer<int*>::value << endl; // true
//     cout << std::is_pointer<int>::value << endl; // false

//     // 내가 만든 is_pointer
//     cout << is_pointer<int*>::value << endl; // true
//     cout << is_pointer<int>::value << endl; // false
// }



// template<typename T>
// struct is_pointer{
//     static const bool value = false;
// };

// // 포인터 타입이 들어오면 true를 리턴하도록 특수화
// template<typename T>
// struct is_pointer<T*> {
//     static const bool value = true;
// };

// // 예를 들어 아래 foo 함수의 경우, T가 pointer인지 아닌지 알 수 없다.
// // 이런 경우에 type_traits의 is_pointer 등을 사용하여 type을 검사해주는 것이다.
// template<typename T>
// void foo(T t) {
//     cout << is_pointer<T>::value << endl;
// }

// int main() {
//     cout << std::boolalpha;

//     int num = 0;
//     int* pNum = &num;
//     foo(num); // false
//     foo(pNum); // true
// }



// int main() {
//     cout << std::boolalpha;

//     // type_traits의 add_pointer
//     // <여기>에 주어진 타입의 포인터를 타입으로 주는 class template
//     int num = 0;
//     std::add_pointer<int>::type pNum = &num;
//     cout << typeid(pNum).name() << endl; // int pointer
//     *pNum = 10;
//     cout << num << endl; // 10

//     // type_traits의 remove_pointer
//     std::remove_pointer<int*>::type num1 = 10;
//     cout << typeid(num1).name() << endl; // int
// }


// remove_pointer와 add_pointer를 직접 구현해보자

// remove_pointer -> 포인터가 아닌 녀석은 그대로 넘겨줌
template<typename T>
struct remove_pointer {
    // static const가 아니라 type alias를 사용해줘야 한다.
    using type = T;
};

// remove_pointer 특수화 -> pointer가 오면 없애주기
template<typename T>
struct remove_pointer<T*> {
    using type = T;
};


// add_pointer
template<typename T>
struct add_pointer {
    using type = T*;
};

// reference에 대한 add_pointer도 특수화해주자
template<typename T>
struct add_pointer<T&> {
    using type = T*;
};

int main() {
    cout << std::boolalpha;

    // int** 타입에 대한 remove pointer
    remove_pointer<int**>::type num;
    cout << typeid(num).name() << endl; // int pointer

    // int 타입에 대한 add pointer
    add_pointer<int>::type num0;
    cout << typeid(num0).name() << endl; // int pointer

    // int& 타입에 대한 add pointer
    add_pointer<int&>::type num1;
    cout << typeid(num1).name() << endl; // int pointer
}