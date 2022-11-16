#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

// int main() {
//     // 여기서 %d의 개수는 정해지지 않았다. 이와 같이 개수가 정해지지 않은
//     // 인자를, 가변인자라고 한다.
//     printf("%d %d", 10, 10);
// }

// C style로 함수 가변 인자를 처리해보자
// #include <cstdarg>
// int sum(int count...) {
//     int result = 0;
//     // 가변 인수들을 저장하는 스택 주소 포인터
//     va_list args;
//     // 포인터가 첫번째 가변 인수를 가리킬 수 있도록 초기화
//     va_start(args, count);
//     for (int i = 0; i < count; ++i) {
//         // int type size * 1 씩 추가해가며 스택에서 인자를 가리킴
//         result += va_arg(args, int);
//     }
//     // 가변 인수 저장 포인터를 null로 초기화해줌
//     va_end(args);
//     return ;
// }

// int main() {
//     cout << sum(4, 10, 20, 30, 40) << endl;
// }

// 템플릿 스타일로 함수 가변 인자를 처리해보자

// 탈출 조건 만들어주기 -> args가 아무것도 없을 때는, 좀 더 구체화된 이 녀석으로 들어오게 된다.
template<typename T>
int sum(T value) {
    return value;
}

template<typename T, typename... Args>
// value에는 10이 들어가고, args에는 이후 값들이 들어간다.
// 그런데 아래 args는 list도, vector도, array도 아니기 때문에 이를 사용하려면 unpack을 해줘야 한다.
// 이를 위해서 args앞에 int value가 있는 것이다.
T sum(T value, Args... args) {
    // 재귀함수를 호출하여 value에 계속해서 첫번째 값이 들어갈 수 있도록 해준다.
    // 그런데 이 때 마지막에 value가 40일 때는 args가 아무것도 없어 에러가 난다.
    // 이를 방지하기 위해 탈출 조건을 만들어준다.
    
    return value + sum(args...);
}

int main() {
    cout << sum<float>(10, 20.3f, 30, 40) << endl;
}