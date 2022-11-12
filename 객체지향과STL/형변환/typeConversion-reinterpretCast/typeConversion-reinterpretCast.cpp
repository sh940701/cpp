#include <iostream>
#include <cfloat>

using namespace std;

// union ID {
//     char char0;
//     int integer;
// };

// int main() {
//     ID id;
//     // id라는 union의 integer에 97을 넣었다.
//     id.integer = 97;
    
//     // id를 int* 스타일로 변환한 포인터 ip
//     int* ip = reinterpret_cast<int*>(&id);

//     // id를 char* 스타일로 변환한 포인터 cp
//     char* cp = reinterpret_cast<char*>(&id);

//     cout << *ip << endl; // 97
//     cout << *cp << endl; // a
//     // union의 경우, 한 공간의 메모리를 각 변수가 공유하여 사용한다.
//     // 현재 활성화되어있는 data는 97이라는 데이터이고, 위에서는 이 데이터를
//     // char 방식으로 읽을 것인지, integer 방식으로 읽을것인지 정해준 것이다.
//     // 같은 데이터지만 char 방식으로 읽으면 a, integer 방식으로 읽으면 97이 나오는 것을 알 수 있다.
// }

int main() {
    // 0000,0000,0000,0000,0000,0000,0000,0001 -> i가 실제 저장되어있는 bits 모양
    unsigned int i = 1;
    // 위와 같은 data를 float 타입으로 읽겠다. -> 데이터에 변화를 주는것이 아니다.
    float* a = reinterpret_cast<float*>(&i);

    cout << i << endl; // 1 -> 위와 같은 데이터를 int 타입으로 읽은 값.
    cout << *a << endl; // 1.4013e-45 -> 위와 같은 데이터를 float 타입으로 읽은 값.
    // 위 데이터는 사실상 들어갈 수 있는 가장 작은 숫자의 값이므로, float 으로는 아래와 같다.
    cout << FLT_TRUE_MIN << endl; // 1.4013e-45

    // 변환 연산자와는 다르다.
    float f = i;
    // 위의 경우에는 f의 위치에 값이 들어갈 때, 형변환이 이루어져 float의 형태로 1이 들어간 것이다.
}