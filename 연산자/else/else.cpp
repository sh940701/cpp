#include <iostream>
#include <limits>

using namespace std;

int main() {
    // 삼항연산자
    // int num = 10;
    // int abs = num < 0 ? -num : num;

    // cout << abs << endl;

    // int num = 0;
    // num == 0 ? (cout << "num == 0" << endl) : (cout << "num != 0" << endl);
    // cout은 연산 후 자기 자신을 리턴하는 함수이다. 예를 들어 cout << 1 << 2; 라는 실행문이 있으면
    // (cout << 1)을 먼저 실행한 후에, 자기 자신(cout)을 다시 리턴해서 cout << 2가 실행되는 구조인 것이다.
    // 그래서 위와 같은 실행문을, 반복되는 cout 선언을 제거하고 아래와 같이 나타낼 수도 있다.
    // cout << (num == 0 ? "num == 0" : "num != 0") << endl;

    // int num = 0;
    // cout << sizeof num << endl; // 4(byte)
    // cout << sizeof(int) << endl; // 4(byte) => type도 넘겨줄 수 있다.

    // short sNum = std::numeric_limits<int>::max(); // short는 2byte이다. 그리고 int는 4byte이다.
    // cout << sNum << endl;

    // 01111111111111111111111111111111 -> int의 최대값
    // 32byte인 int를 short로 암시적 형변환하게되면 좌측 16개가 잘리고, 우측 16개만 남게된다.
    // 1111111111111111 => 부호 있는 정수의 값을 구하려면 2의 보수를 취해야 한다.
    // 0000000000000001 => 결국  -1이 출력된다.

    // 명시적 형변환
    std::cout << 'a' << std::endl;
    std::cout << (int)'a' << std::endl; // C 스타일 형변환
    std::cout << int('a') << std::endl; // C++ 스타일 형변환

    // C++ 스타일의 다른 형변환 방법들
    static_cast<int>('a');
    const_cast<int>('a');
    dynamic_cast<int>('a')
    reinterpret_cast<int>('a')

}