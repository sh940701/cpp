#include <iostream>

using namespace std;

// int main() {
//     // 자동변수 : automatic storage - 함수 안에서 사용되는 일반적인 변수들
//     // 함수블럭 또는 함수 안에서 또다른 블럭 안에서 선언이 되고, 이를 벗어나면 해제된다.
//     {
//         int num; // 자동변수
//         static int num1; // 지역변수지만, 자동변수가 아니다.
//         extern int num2; // 이 또한 지역변수지만 자동변수가 아니다.
//         // 지역변수는 '범위'에 관한 것이다. scope단위로 접근여부를 정하는 것이 지역변수의 개념
//         // 자동변수는 메모리 할당과 해제에 관한 것이다.
//     }
//     num1; // 정적변수이기때문에 스코프를 벗어나도 존재하긴 하지만, 지역변수로써 밖에서 접근은 불가하다.
//     num2; // 전역변수를 스코프 내에서 사용 가능하도록 선언해준 것, 마찬가지로 지역변수이므로, 밖에서 접근 불가

//     // 자동공간에 할당된 자동변수는, 블럭을 벗어나는 순간에 자동으로 해제된다
// }

// int num0; // 전역변수는 정적공간(static storage)에 할당됨
// static int num1; // 전역변수 앞에 static을 붙여도 정적공간(static storage)에 할당됨

// int main() {
//     {
//         static int num; // 지역변수에 static을 붙이면 자동변수가 아니라 정적변수가 된다. -> 정적 공간에 할당됨
//     }
// }

// int main() {
//     for (int i = 0; i < 10; ++i) {
//         int num = 0;
//         ++num;
//         cout << num << endl;
//     }
// }

// 전역적으로도 선언이 가능
int *p0 = new int;

int main() {
    // 포인터를 사용하여 동적 변수를 가리켜줘야한다.
    int *p = new int;
    // 동적 변수는 반드시 해제를 해줘야한다.
    delete p;
}