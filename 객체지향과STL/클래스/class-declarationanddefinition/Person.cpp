#include "Person.h"

void foo() {
    Person person1 = {50, 173, "daniel"};
    person1.print();
}

// class에 있는 함수들도 선언과 정의를 분리할 수 있다.

// 만약 함수명만 입력하고 정의해주면, 이는 전역함수로 정의가 되는 것이다.
// 그러므로 Person이라는 class에 포함된 함수라는것을 명시하기 위해 범위 연산자로 표시해준다.
Person::Person(float weight, float height, const std::string& name)
        : _weight(weight), _height(height), _name(name)
        {}
void Person::print() {
    using namespace std;
    cout << _name << endl;
}