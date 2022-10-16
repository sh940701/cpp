#include <iostream>
#include <vector>

using namespace std;

int main() {
    // // 레퍼런스 선언해보기
    // // 먼저 변수를 하나 선언 & 초기화해준다.
    // int num0 = 10;
    // // 그리고 선언할 변수(num1)앞에 & 연산자를 붙여준다. 우항에는 어떤 변수를 레퍼런싱 할 것인지 넣어준다.
    // // 포인터는 좌측에 *, 우측에 & 연산자를 붙여주었고, 레퍼런스는 이와 다른 것을 기억해야한다.
    // int& num1 = num0;
    // int* num2 = &num0;

    // cout << num0 << endl; // 10
    // cout << num1 << endl; // 10
    // cout << *num2 << endl; // 10
    // cout << endl;

    // // num0을 바꿔보자
    // num0 = 20;
    // cout << num0 << endl; // 20
    // cout << num1 << endl; // 20
    // cout << *num2 << endl; // 20
    // cout << endl;

    // // num1을 바꿔보자
    // num1 = 30;
    // cout << num0 << endl; // 30
    // cout << num1 << endl; // 30
    // cout << *num2 << endl; // 30
    // cout << endl;

    // // num2를 바꿔보자
    // // num2 = 40; // 안된다.
    // *num2 = 40; // 역참조 형태로 바꿔줘야 한다.
    // cout << num0 << endl; // 40
    // cout << num1 << endl; // 40
    // cout << *num2 << endl; // 40
    // cout << endl;

    // int num = 30;
    // int num0 = 10;
    // int& num1 = num0;
    // int* num2 = &num1;

    // num1 = num;
    // cout << num0;

    // int& num1;

    // int num0 = 10;
    // const int& num1 = num0;

    // 위와같이 const로 레퍼런스 변수를 선언해주면, 레퍼런스 변수에 들어가는 값을 바꿀 수 없다.
    // cout << num0 << endl; // 10
    // cout << num1 << endl; // 10
    // num1 = 30; // error

    // int& num1 = 30;
    // const int& num1 = 30;

    // // 레퍼런스로 vector 자료형을 다뤄보자
    // // vector 자료형 변수 선언
    // vector<int> vec0;
    // // vector 자료형 레퍼런스 변수 초기화
    // vector<int>& vec1 = vec0;
    // // vector 자료형 포인터 변수 초기화
    // vector<int>* vec2 = &vec0;

    // // vector에 데이터 추가
    // vec0.push_back(1);
    // // vector 레퍼런스에 데이터 추가
    // vec1.push_back(2);
    // // vector 포인터에 데이터 추가
    // vec2->push_back(3); // vec2->push_back()은 (*vec2).push_back()과 같은 연산이다.

    // for (int num : vec0){
    //     cout << num;
    // }

    // 레퍼런스 사용시 주의할 점
    // pointer를 사용한 동적할당
    // int* num0 = new int(12);
    // // num1이라는 레퍼런스 변수에 num0의 역참조 값(12) 할당
    // int& num1 = *num0;

    // // 현재 num1은 heap에 할당된 12란 녀석을 레퍼런싱하고있기 때문에 아래와 같이 출력된다.
    // cout << *num0 << endl; // 12
    // cout << num1 << endl; // 12

    // // 그런데 어디선가 num0의 동적할당을 해제해버린다면?
    // delete num0;

    // cout << *num0 << endl; // 12
    // cout << num1 << endl; // 12

    // const int* const num1 = 12;
}