#include <iostream>
#include <vector>


using std::cout;
using std::endl;

// 암시적 구체화

// int main() {
//     // 아래와 같이 필요할 때 템플릿 파라미터를 명시한다던가
//     std::vector<int> v;

//     // 이런 식으로 호출을 한다던가.
//     int x = 10, y = 20;
//     std::swap<int>(x, y)

//     // 위와같이 사용할 때! 암시적으로 구체화가 된다.
// }


// 명시적 구체화

// 아래와 같이 명시적 구체화를 할 수도 있다. 이렇게 명시적으로 구체화를 할 경우
// 컴파일 타임에서 int& 타입에 대한 std::swap함수가 생성된다.
// template // 특수화는 <>가 있다.
// void std::swap<int>(int&, int&);

// int main() {

// }

#include "swap.h"

template<typename T>
void swap(T& x, T& y);

int main() {
    // 안된다. 링킹 에러가 났음
    // 헤더의 선언은 찾을 수 있었으나, 구체화된 내용은 찾을 수 없었던 것이다. 왜 그럴까?
    // 현재 아래의 swap(x, y)는 암시적 구체화를 한 상태이다. 또한 include를 통해 
    // 위와같이 원형을 가져온 상태이다. 그렇다면 source파일에서 컴파일이 되어 사용 할 수 있지않나?
    // 템플릿이 아닌 일반 함수는 그렇게 된다. 그런데 swap.cpp에 있는 구현은, 함수가 아니다. 템플릿이다.
    // 그 자체는 컴파일이 되지 않는다. 그러니 아래 swap 함수와 링크가 되지 않는 것이다.

    int x = 10, y = 20;
    swap(x, y);

    cout << x << endl;
    cout << y << endl;
}