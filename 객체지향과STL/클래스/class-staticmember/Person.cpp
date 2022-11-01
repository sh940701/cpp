#include <iostream>
#include "Person.h"

Person::Person(){
    num++;
}

// static 멤버는 전역적으로 선언해줘야 한다.
// static 멤버이지만 초기화 할 때는 static을 붙이지 않는다.
int Person::num = 0;

// 만약 멤버가 static이 아니라 static const 이라면 초기화 시 const를 붙여줘야한다.
const int Person::num = 0; // 정상

// print 함수도 static 멤버이지만 초기화 할 때는 static을 붙이지 않는다.
void Person::print() {
    // 클래스의 멤버함수가 정적으로 선언되어있을 때, 클래스 내 정적 멤버에는 접근이 가능하지만
    // 정적 멤버가 아닌 녀석에는 접근이 불가능하다.
    std::cout << a << std::endl; // error
    
    // 정적 변수 외에 정적 함수에도 접근이 가능하다.
    std::cout << num << std::endl;
}

// 정적 멤버가 아닌 일반 함수에서도 정적 멤버에 접근이 가능하다.
// 다만 정적 멤버는 class scope 내 전역변수처럼 생각되어, 객체마다 다른 값이 아니라
// 전부 같은 값을 가지고 있다는 사실을 기억해야 한다.