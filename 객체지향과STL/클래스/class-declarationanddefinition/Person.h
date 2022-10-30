#pragma once

#include <iostream>
#include <string>

// header에서 using을 사용하면, header파일을 사용하는 모든 녀석에 적용된다.
// 그러므로 웬만해서는 지양하는 것이 좋다.

// class Person {
// private:
//     float _weight;
//     float _height;
//     const std::string _name;

// public:
//     Person(float weight, float height, const std::string& name)
//         : _weight(weight), _height(height), _name(name)
//         {}
//     void print() {
//         // using namespace를 함수 안에서 선언해줄 수도 있다.
//         using namespace std;
//         cout << _name << endl;
//     }
// };

// // header에 아래와 같이 foo()함수도 넣어줄 수 있다.
// void foo() {
//     Person person1 = {50, 173, "daniel"};
//     person1.print();
// }

class Person {
private:
    float _weight;
    float _height;
    const std::string _name;

public:
    // 정의를 Person.cpp 파일로 옮겨줄 것이기 때문에 header파일에는 선언만 남겨준다.
    Person(float weight, float height, const std::string& name);
    void print();
};

// header에는 선언만 남겨준다.
void foo();