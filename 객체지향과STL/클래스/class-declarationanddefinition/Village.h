#pragma once

// vector를 사용해서 사람들이 살고있는 마을을 표현
#include <vector>

// include 대신 전방선언 사용
// #include "Person.h"
class Person;

class Village{
private:
    std::vector<Person> persons;
public:
    void add(Person);
};