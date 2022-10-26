#include <iostream>
#include <string>

using namespace std;

// 파라미터로 넘어오는 정수가 몇자리수인지를 알려주는 함수 생성
// int countDigit(int num){
//     if (num == 0) {
//         return 1;
//     }

//     int count = 0;
//     while (num) {
//         num /= 10;
//         count++;
//     }
//     return count;
    
// }

// int countDigitStr(string num) {
//     return countDigit(stoi(num));
// }

// int main() {
//     cout << countDigit(12345) << endl; // 5
//     cout << countDigitStr("12345") << endl; // 5
// }

// void func(int); // func#int-int
// void func(int, int); // func#int
// void func(char); // func#char

// int main() {
//     // 함수를 호출할 때도, 컴파일 타임에 호출하는 함수의 이름이 바뀐 채로 호출하게 된다. 아래 함수명은 예시이다.
//     // 이를 통해 우리가 보기엔 이름이 같지만 실제로는 다른 함수에 각각 binding이 되는 것이다.
//     func(10, 10); // func#int-int
//     func('a'); // func#char
// }

// 함수 오버로딩은 객체지향의 특성 중 하나인 "다형성"의 성격을 띤다.
// 같은 이름으로 다른 일을 할 수 있기 때문이다.(한개의 이름으로 여러개의 형을 가지기 때문에)


// 형만 다른 같은 'a'를 출력할 때의 예시
int main() {
    cout << 'a' << endl; // a
    cout << (int)'a' << endl; // 97
}