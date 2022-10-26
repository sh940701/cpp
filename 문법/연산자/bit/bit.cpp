#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // "~" not 연산자
    // unsigned int num = 0;
    // int num = 0;
    // cout << ~~num << endl;

    // 00000000000000000000000000000000 == 0
    // 11111111111111111111111111111111 == -1

    // "&" 연산자
    // int num0 = 5;
    // int num1(10);

    // int result = num0 & num1;
    // cout << result << endl;

    // uint32_t attendanceBook = 7u;

    // if (attendanceBook & ((int)pow(2, 0) + (int)pow(2, 1))) {
    //     cout << "1 or 2" << endl;
    // }

    // int flag = (int)pow(2, 0) + (int)pow(2, 1);
    // if ((attendanceBook & flag) == flag) {
    //     cout << "1 and 2" << endl;
    // }


    // cout << attendanceBook << endl;
    // 00000000 = 4 + 1 = 2^2 + 2^0
    // 00001010 = 10 = 8 + 2 = 2^3 + 2^1
    // 00000000 = 0 

    // uint32_t attendanceBook = 5u;
    
    // attendanceBook &= ~((int)pow(2, 2) | (int)pow(2, 0));

    // cout << attendanceBook << endl;

    // XOR
    // 1 ^ 1 == 0
    // 1 ^ 0 == 1
    // 0 ^ 1 == 1
    // 0 ^ 0 == 0

    // uint32_t attendanceBook = 0u; // 0000

    // attendanceBook |= (int)pow(2, 0); // 0001
    // cout << attendanceBook << endl; // 1

    // attendanceBook ^= (int)pow(2, 0); // 0001 ^ 0001 == 0000
    // cout << attendanceBook << endl; // 0

    // attendanceBook ^= (int)pow(2, 0); // 0000 ^ 0001 == 0001
    // cout << attendanceBook << endl; // 1

    // 숫자의 집합이 있다고 가정해보자, 이 숫자들은 짝수 개 있는 숫자와 홀수 개 있는 숫자로 나뉜다.
    // 1의 경우, a와 d(짝수 개)가 있고, 2는 c와 e(짝수 개), 3은 b(홀수 개)가 있다.
    // 이런 경우에 홀수 개인 숫자만 찾으려면 모든 항에 대해 XOR연산을 실행하면 된다.
    // int a = 1, b = 3, c = 2, d = 1, e = 2;
    // cout << (a ^ b ^ c ^ d ^ e) << endl; // 3
    
    // XOR연산은 결합법칙이 성립하기 때문에 위 식과 아래 식이 같다.
    // 같은 값에 대해 XOR연산을 하면 0이된다. 그러므로 아래 식에서
    // a ^ d == 0, c ^ e == 0, 0 ^ 0 == 0, 0 ^ 3 == 3이 성립되기때문에
    // 결과값으로 유일하게 홀수 개만큼 있는 수인 3이 출력되는 것이다.
    // cout << (a ^ d ^ c ^ e ^ b) << endl; // 3

    cout << (1 << 3) << endl; // 8
    
    // 00000001 // 1
    // 00000010 // 1 << 1
    // 00000100 // 1 << 2
    // 00001000 // 1 << 3
}

