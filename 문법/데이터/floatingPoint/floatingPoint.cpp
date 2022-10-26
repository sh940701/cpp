// https://www.notion.so/3eaef0b2acb348fc84a872223bbde6d0
#include <iostream>

using namespace std;

/*
int main() {
    float num0 = 1.5;
    float num1 = num0 * 1.5;
    float num2 = num0 / 2;
    float num3 = num0 - 3;

    cout << "num0 " << num0 << endl; // 1.5
    cout << "num1 " << num1 << endl; // 2.25
    cout << "num2 " << num2 << endl; // 0.75
    cout << "num3 " << num3 << endl; // -1.5
}
*/

// 부동소수점 자료형의 사이즈를 살펴보자
/*
int main() {
    float num0 = 1.0;
    double num1 = 1.0;
    long double num2 = 1.0;

    cout << sizeof(num0) << endl; // 4
    cout << sizeof(num1) << endl; // 8
    cout << sizeof(num2) << endl; // 8

    cout << sizeof(1.0f) << endl; // float
    cout << sizeof(1.0) << endl; // double
    cout << sizeof(1.0L) << endl; // long double
}
*/

// 부동소수점이 메모리에 담기는 형태를 알아보자
/*
int main() {
    // memory layout을 확인하기 위해서는 unsigned에 넣어줄 필요가 있다.
    unsigned int num0;
    float num1 = -118.625;
    // memcpy에서 아래 의미는 num1에 있는 값을 num0으로 copy한다는 의미이다.
    // 메모리상에 있는 value를 직접 그냥 copy하는 것 -> num0 = num1과는 아예 다른 개념
    memcpy(&num0, &num1, sizeof(num1));

    cout << num0 << endl; // num0은 3270328320으로 나오고, 이를 Binary로 바꾸면 memory에 저장되어있는 형식이 나오게 된다.
    cout << num1 << endl;
}
*/

// 부동소수점에서 비교 연산을 해보자
/*
int main() {
    float num0 = 0.1f;
    float num1 = 0.02f * 5.0f;

    cout.precision(64); // 정밀도를 추가해주는 함수이다.

    cout << num0 << endl; // 정밀도를 추가하였을 경우 : 0.100000001490116119384765625
    cout << num1 << endl; // 정밀도를 추가하였을 경우 : 0.0999999940395355224609375
    // 2진수로는 10진수의 0.1, 0.2 등을 나타낼 수 없다. 그래서 최대한 근사치를 가져다가 쓰는 것이다.

    if (num0 == num1)
        cout << "Equal 1" << endl; // not work -> 위에 나와있듯, 정확히 같은 값이 아니기때문에 동작하지 않는 것

    if(num0 == 0.1f)
        cout << "Equal 2" << endl; // work

    if(num0 == 0.1)
        cout << "Equal 3" << endl; // not work -> 이 친구는 사실 0.1 double이다.

    if(num0 == 0.1L)
        cout << "Equal 4" << endl; // not work -> 이 친구는 사실 0.1 long double이다.

    cout << 0.1f << endl;
    cout << 0.1 << endl;
    cout << 0.1L << endl;
    // 각각 다름.
}
*/

// 절대값 비교를 한번 사용해보자
#include <cfloat>
#include <math.h>
/*
int main() {
    float num0 = 1.0f;
    float num1 = 0.0f;
    for (int i = 0; i < 10; i ++)
        num1 = num1 + 0.1;
    if (num0 == num1)
        cout << "Equal 0" << endl;
    // abs는 절댓값 (absolute)를 구한다는 뜻, 앞 뒤로 f를 붙인것은 float에 대한 절댓값을 구한다는 뜻
    // 강의 동영상에서는 cfloat만 include해줘도 되었는데, 내 컴퓨터에서는 math.h도 include해줘야 사용할 수 있다. IDE의 차이인지 잘 모르겠다.
    if (fabsf(num0 - num1) <= FLT_EPSILON) // FLT_EPSILON은 1보다 큰, 가장 작은 실수를 뜻한다.
        cout << "Equal 1" << endl;
}
*/

// EPSILON 값을 한 번 유도해보자
/*
int main () {
    // 0b를 입력하면, 바로 메모리의 바이너리 형태를 표현할 수 있다. 뒤에 붙은 0은 양수이기 때문에 붙는 것이다.
    // 또한 지수부는 8자리이고, 지수부의 0 == 127이다. 그러므로 0b(바이너리 표시)0(플러스)01111111(지수부 127 == 0)00000000000000000000000(가수부 0 * 23)
    unsigned int num0 = 0b00111111100000000000000000000000; // <= 얘가 1이다.
    float num1;
    memcpy(&num1, &num0, sizeof(num0));

    cout.precision(64);
    cout << "num1 " << num1 << endl; // 1이 출력된다.
    cout << "num0 " << num0 << endl;

    unsigned int num2 = 0b00111111100000000000000000000001; // <= 메모리상으로 표현할 수 있는, 1보다 큰 수 중 가장 작은 수
    float num3;
    memcpy(&num3, &num2, sizeof(num2));

    // cout << "num3 " << num3 << endl; 
    cout << "num2 " << num2 << endl; // 이대로 출력하면 10진수로 출력된다. 1065353217

    cout << num3 - num1 << endl;
    cout << FLT_EPSILON << endl;
}

// 1 = 1.0(0은 가수부) * 10^0(2)(지수부)
*/

/*
// float에서 더하거나 뺐는데 인지를 못하는 현상
int main() {
    float num0 = 1.0f;

    unsigned int num1 = 0b00110100000000000000000000000000;
    float num2;
    memcpy(&num2, &num1, sizeof(num1));

    cout.precision(64);
    cout << num0 + num2 << endl;
}

// 0011,1111,1000,,0000,0000,0000,0000,0000 == 1.0(2)
*/

// float의 최댓값을 구해보자
int main() {
    float num0 = FLT_MAX;

    cout.precision(64);
    cout << num0 << endl;

    float num1;
    unsigned int num2 = 0b01111111000000000000000000000000;
}