#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    Person p0; // num = 0 -> 1
    Person p1; // num = 1 -> 2

    p0.print(); // 2
    p1.print(); // 2

    // 클래스 멤버함수를 static으로 정의하면, 객체가 아니라 클래스 자체에서도 접근이 가능하다.
    Person::print();
}