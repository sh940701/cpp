// 구체적인 작업(정의)를 명시해주는 소스파일

// Village의 구성이 명시되어있는 Village.h파일 include
#include "Village.h"

// Village.h 파일에 적어놓았듯이, 이곳에서는 class Person에 대한 구체적인 작업을 수행할
// 것이기 때문에 Person의 구체적인 정의가 나와있는 Person.h파일을 include해줘야 한다.
// Person 안에서 어떤 일이 벌어진다.
void Village::add (Person person){
    persons.push_back(person);
}