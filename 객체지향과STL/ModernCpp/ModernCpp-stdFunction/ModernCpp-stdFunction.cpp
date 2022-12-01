#include <iostream>
#include <functional>


// template<typename T>
// void foo() {
//     std::cout << typeid(T).name() << std::endl;
// }

// int main() {
//     // std::function 은 아래와 같이 사용해줄 수 있는데,
//     // <int(float)> 은 함수 타입을 의미하는 것이다.
//     std::function<int(float)> func;
    
//     foo<void(int)>(); // FviE(int _cdecl(float))
//     // 위에서 함수타입 foo에 함수 타입 파라미터를 보내주니 함수타입이라는 name이 나왔다.
// }


// int func(float) {
//     return 1;
// }

// struct Func
// {
//     float operator()(float value) {
//         return value * 2;
//     }
// };


// int main() {
//     // std::function을 통해 기존 함수를 이렇게 wrapping해줄 수 있다.
//     std::function<int(float)> f0 = func;

//     // 이렇게 람다를 wrapping해줄 수 있다.
//     std::function<float(float)> f1 = [](float value) {return value;};

//     // 함수 객체를 wrapping해줄 수 있다.
//     std::function<float(float)> f2 = Func();

//     std::cout << f0(1.1f) << std::endl; // 1
//     std::cout << f1(1.1f) << std::endl; // 1.1
//     std::cout << f2(5.0f) << std::endl; // 10
// }


// static 멤버 함수에 대한 wrapping
// struct Func {
//     static int func(float value) {
//         return value;
//     }
// };

// int main() {
//     std::function<int (float)> f = Func::func;
//     std::cout << f(10) << std::endl;
// }

// // non-static 멤버 함수에 대한 wrapping
// struct Func {
//     int func(float value) const {
//         return value;
//     }
// };

// int main() {
//     // non-static 멤버 함수 포인터
//     int (Func:: *f)(float) const = &Func::func;
//     std::cout << (Func().*f)(10) << std::endl; // 10 -> 굉장히 복잡하다... 이를 wrapping해보자

//     // std::function을 이용한 non-static 멤버 함수 wrapping
//     // 내부적으로 this를 넘겨줘야 하기 때문에 Func&를 함께 준다.
//     std::function<int(const Func&, float)> f0 = &Func::func;
//     std::cout << f0(Func(), 20) << std::endl;// -> 이 또한 굉장히 복잡하다...

//     // 위와 같은 복잡함을 해소하기 위해선 bind라는 것을 사용해 줄 수 있다.
//     // std::bind는 첫번째 인자 함수를 뒤에 있는 파라미터들로 bind를 해주겠다는 것이다.
//     // 원래 파라미터는 위와 같이 (const Func&, float)으로 넘겨줘야 한다.
//     // const Func& 위치에 Func()를 넣어주었고, std::placeholders를 사용해서 두 번째 파라미터(float)을
//     // 첫번째 위치로 바꿔준 것이다. 결국 &Func::func와 Func()를 묶고, float을 첫번째 파라미터로 바꾼것이다.
//     std::function<int(float)> f1 = std::bind(&Func::func, Func(), std::placeholders::_1);
//     std::cout << f1(30) << std::endl;

//     // 아래와 같이 한번 더 바인딩을 해줄 수도 있다.
//     // f1과 12를 묶어서 f2로 만들어준 것이다.(??????.....)
//     std::function<int()> f2 = std::bind(f1, 12.f);
//     std::cout << f2() << std::endl;
// }



void foo(int n0, int n1, int n2) {
    std::cout << n0 << std::endl;
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
}

int main() {
    std::bind(foo, std::placeholders::_3, std::placeholders::_1, std::placeholders::_2)
        (1, 2, 3); // 3, 1, 2 가 나온다.
    // std::placeholders는 현재 자신이 위치한 순서에 _n 번째 파라미터를 놓겠다는 것이다.
    // 위에서 첫번째 자리에 std::placeholders::_3이 있으므로 세번째 파라미터가 첫번째 자리로 가고
    // 두번째 자리에 std::placeholders::_1이 있으므로 첫번째 파라미터가 두번째 자리로 가고
    // 세번째 자리에 std::placeholders::_2이 있으므로 두번째 파라미터가 세번째 자리로 가는 것이다.
}