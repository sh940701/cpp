#include <iostream>
#include <vector>
#include <map>
#include <type_traits>

using std::cout;
using std::endl;

// int main() {
//     // int 타입 추론
//     auto i = 10;
    
//     // vector와 같은 container 타입에서 iterator를 가리키는 경우 등 간결함이 극대화
//     std::vector<int> v;

//     // 기본적인 타입 명시 방법 -> C++ 11 이전
//     std::vector<int>::iterator iter0 = v.begin();
//     // auto를 활용한 타입 명시 방법
//     auto iter1 = v.begin();

//     // 동적 할당을 해줄 때도 좋음 -> int* 타입
//     auto dynamicInt = new int(10);
// }

// int main() {
//     // map의 경우
//     std::map<int, int> m {
//         {1, 1}
//     };

//     // 복사 방지 및 원본 데이터의 변경을 막기 위해 보통 const를 붙여줌
//     for (const auto& pair : m) {
//         pair.first; // -> key
//         pair.second; // -> value
//     }

//     // auto를 사용하지 않을 경우 -> 아래와 같은 표기는 틀린 표기이다.
//     // std::pair<const int, int> -> map은 key를 변경할 수 없기 때문에 이것이 맞는 표현이다.
//     // 만약 아래와 같이 선언을 하면, 이 또한 key를 변경할 수 없기 때문에 에러는 생기지 않지만
//     // pair에 대한 const 타입의 임시객체가 만들어질 것이고, 이는 성능에 부정적 영향을 미친다.
//     // 그렇다고 앞에 const를 빼면 에러가 발생하여 진행이 안된다.
//     // auto를 사용하면 자동으로 std::pair<const int, int>로 컴파일해주기 때문에 위와같은 문제를 없앨 수 있다.
//     for (auto& pair : m) {
//         pair.second = 3;
//         cout << pair.first << endl;
//         cout << pair.second << endl;
//     }
// }


// int main() {
//     const int a = 10; // const int
//     const int& b = a; // const int&
//     const int* c = &a; // const int*

//     // auto로 타입을 추론해보자
//     // auto는 const나 레퍼런스를 떼는 경우가 많다.
//     // auto만 있으면 값으로만 추론이 된다. -> 그저 복사가 되는 것이다.
//     auto aa = a; // int

//     // const int& b의 값은 a 이기 때문에 a의 값으로 추론이 된다.
//     // 이 경우, bb를 바꿔도 b는 바뀌지 않는다.
//     auto bb = b; // int

//     // const int* c의 값은 const int a의 주소값이기 때문에 주소값을 그대로 갖게 된다.
//     auto cc = c; // const int*


//     // 레퍼런스를 넣은 상태로 추론을 하고 싶으면 어떻게 해야 할까?
//     // 이렇게 auto&로 표기해주면 된다.
//     // 이 경우에는 값이 아닌 그대로 레퍼런스를 담기 때문에 const int&가 그대로 담기는 것이다.
//     auto& aaa = b; // const int& -> const 레퍼런스로 추론이 된다. -> b대신 a가 들어가도 결과는 같다.
    
//     // 위에서 cc는 const int* 라고 했다. 이를 분리해서 선언할 수도 있다.
//     // 아래의 경우 auto는 const int가 되고 *로 인해 포인터가 되는 것이다.
//     // 결과적으로 아래 ccc와 위 cc의 타입은 같다.
//     auto* ccc = c; // const int*

//     // 아래에서 결과 타입은 const int*로 같으나, auto는 int가 된다. 앞 뒤로 const, *가 있기 때문이다.
//     const auto* cccc = c; ///
// }


// int main() {
//     int nums[] = {1, 2, 3};
//     // 이 때 nums0의 타입은, int*이다. -> 배열이 함수 인자로 넘어갈 때 디케이되는 것과 같음
//     auto nums0 = nums;
//     // 이 때 nums1의 타입은 길이 3인 int 배열의 레퍼런스 타입이 된다.
//     auto& nums1 = nums;
// }


// int func(float) {}

// int main() {
//     // 이녀석은 함수 포인터가 된다. -> 디케이 된 것임
//     auto func0 = func;
//     // 마찬가지로 레퍼런스를 붙이면, 함수 레퍼런스가 된다.
//     auto& func1 = func;
// }


// template<typename T, typename S>
// void add(T t, S s) {
//     // t와 s를 더할 때, 결과 type은 어떻게 될까?
//     // 아래 경우에는 앞선 인자의 타입으로 정해진다.
//     T result = t + s;
//     std::cout << result << endl;
// }

// int main() {
//     add(1, 1.2); // 2 -> T의 타입이 int이므로, 다운캐스팅되어 2가 출력된다.
//     add(1.2, 1); // 2.2 -> T의 타입이 double이므로 2.2가 출력된다.
// }

// template<typename T, typename S>
// void add(T t, S s) {
//     // auto가 결과값의 타입을 추론해준다.
//     auto result = t + s;
//     std::cout << result << endl;
// }

// int main() {
//     add(1, 1.2); // 2.2
//     add(1.2, 1); // 2.2
// }


// template<typename T, typename S>
// // C++ 11부터 auto와 decltype(declared type)을 이용하여 리턴타입을 추론해줄 수 있다.
// // decltype은 괄호 안에 있는 식에 대해서, 어떤 타입의 결과가 나오는지 보고, 이를
// // 추론해내는 것이다. 이 때 decltype(t + s)는 결국 double이다.
// // 그리고 사실 C++ 14부터는 -> decltype()을 따로 명시해주지 않아도 된다. ㅎㅎ
// auto add(T t, S s) -> decltype(t + s)
// {
//     // 아래와 같이 return을 해줘야 할 때는 리턴 타입을 어떻게 설정해줘야 할까?
//     return t + s;

//     // decltype은 타입이기 때문에 아래와 같이도 써줄 수 있다.
//     decltype(t + s) result = t + s;
//     return result;
// }

// int main() {
//     cout << add(1, 1.2) << endl; // 2.2
//     cout << add(1.2, 1) << endl; // 2.2
// }


// 아래와 같은 상황에서는 decltype으로 해결해 줄 수 있다.
// 아래와 같은 상황에선 auto가 컴파일타임에 유추가 안되기때문에 컴파일 에러가 난다.
// 이럴 경우, decltype으로 두 수를 다 표현해줄 수 있는 t + s의 타입을 지정해줌으로 해결할 수 있다.
// template<typename T, typename S>
// auto add(T t, S s) -> decltype(t + s)
// {
//     if (t < s) {
//         return t;
//     } else {
//         return s;
//     }
// }

// int main() {
//     cout << add(1, 1.2) << endl; // 2.2
//     cout << add(1.2, 1) << endl; // 2.2
// }


enum class Type {
    A, B
};

template<typename Enumeration>
auto asInteger(Enumeration value) {
    // std::underlying_type<Enumeration>::type에서 마지막 ::type이 내부 변수인지, 타입인지
    // 컴퓨터는 알 수 없기 때문에 앞에 typename을 명시해준다.
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

int main() {
    cout << asInteger(Type::A) << endl; // 0
    cout << asInteger(Type::B) << endl; // 0
}