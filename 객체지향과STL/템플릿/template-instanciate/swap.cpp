// swap 함수 source 파일
#include "swap.h"

// 여기서 구현을 해줌
template<typename T>
void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}
// 이 녀석은 함수가 아니므로, 자동으로 컴파일이 되지 않는다.
// 그러므로 source파일에서 사용하려면 아래와 같이 명시적 구체화를 해줘야한다.
// 아래 녀석을 줌으로써 int에 대한 swap함수가 구체화되었고, 컴파일이 될 수 있었던 것이다.
// 그런데 이렇게 헤더와 소스파일을 분리하면, 사용할 타입에 대한 구체화를 계속 따로 해줘야한다.
// 그렇기때문에, template의 경우 구현을 모두 템플릿에 넣어준다.
template
void swap<int>(int&, int&);