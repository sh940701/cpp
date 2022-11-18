#include <iostream>

using std::cout;
using std::endl;

// enum Unscoped {
//     A, B
// };

// enum class Scoped : long long {
//     A, B = 10000000000
// };

// int main() {
//     cout << std::boolalpha;

//     cout << A << endl;
//     // Scoped의 long long 타입을 추론해줌
//     using T = std::underlying_type<Scoped>::type;
//     cout << static_cast<T>(Scoped::B) << endl;
// }

// enum Unscoped {
//     A, B
// };

// enum class Scoped : long long {
//     A, B = 10000000000
// };

// enum class Scoped1 {
//     A
// };

// template<typename T>
// struct is_scoped_enum {
//     // enum인지 확인, 변환 가능한지 확인
//     static const bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
// };

// template<typename T>
// std::ostream& operator<<(std::ostream& os, const T& value) {
//     // template을 사용해서 is_scoped_enum을 만들어보자
//     // 근데 이걸 여기 넣어놓으면 Unscoped가 일단 들어와 버리기 때문에 assert되어 컴파일 에러가 발생된다.
//     static_assert(is_scoped_enum<T>::value, "T is not enum");

//     // 아래 t에는 long long 등 enum의 숫자 타입이 담긴다.
//     using t = typename std::underlying_type<T>::type;
//     cout << static_cast<t>(value);
//     return cout;
// }

// int main() {
//     cout << std::boolalpha;

//     cout << Unscoped::A << endl;
//     cout << Scoped::B << endl;
//     cout << Scoped1::A << endl;

//     // cout << is_scoped_enum<Unscoped>::value << endl; // true
//     // cout << is_scoped_enum<Scoped>::value << endl; // false
// }

enum Unscoped {
    A, B
};

enum class Scoped : long long {
    A, B = 10000000000
};

enum class Scoped1 {
    A
};

template<typename T>
struct is_scoped_enum {
    static const bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
};

// template<typename T, typename S = typename std::enable_if<is_scoped_enum<T>::value>::type>
template<typename T, typename std::enable_if<is_scoped_enum<T>::value, int>::type = 0>
std::ostream& operator<<(std::ostream& os, const T& value) {
    cout << "operator <<" << endl;
    using t = typename std::underlying_type<T>::type;
    cout << static_cast<t>(value);
    return cout;
}

int main() {
    cout << std::boolalpha;

    cout << Unscoped::A << endl;
    cout << Scoped::B << endl;
    cout << Scoped1::A << endl;
}