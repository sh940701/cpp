#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// 강제종료 abort
// int main() {
//     std::abort();
// }

// 정상종료 exit
// int main() {
//     exit(123);
// }


// int main() {
//     // printf에서 반환형은 출력한 문자의 개수를 반환한다. 에러 발생시에는 - 값을 반환한다.
//     // printf가 출력할 stdout에 대한 파일을 읽기 전용으로 연다. -> 쓰기 함수인 printf의 에러 발생

//     freopen("input.txt", "r", stdout);
    
//     int result = printf("%d", 10); // result = -1
    
//     cout << result << endl;
//     bool r = cout.fail(); // true
//     // 위와같이 return 형으로 알려주거나, 행위에 대한 실패 여부(r)를 알려주는 방식으로 예외처리 가능
// }

// 나누기 함수를 만들어서, 에러처리를 해보자
// v가 0일 때 에러가 발생한다고 가정

// 전역적으로 errorCode라는 변수를 두어 진행할 수도 있다.

double divide (double d, double v, double& result) {
    if (v == 0) {
        // return 형으로 문제를 알려줄 때
        result = 0;
        return -1;
    }
    // return 형으로 문제를 알려주면, 연산 결과 전달을 못한다.
    // 답을 전달해줄 변수를 하나 더 받아서 처리한다.
    result = d / v;
    return 0;
}

int main() {
    double result;
    int errorCode = divide(10, 0, result);
    cout << result << endl;
    // 에러 상황일 때와 그렇지 않을 때 로직 추가해야함
    if (errorCode) {

    } else {

    }
}