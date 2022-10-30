// main에서도 Person.h를 사용하기 위해 include해준다.
// 이 때 <>로 include는 시스템에서 지원되는 header들을 include할 때 사용되고
// 우리가 만든 user defined header 파일은 큰따옴표로 표시해준다.
#include "Person.h"

int main() {
    Person person = {74, 182.1, "david"};
    person.print();
    // 현재 Person.h 파일에 foo 함수도 정의되어있기 때문에 foo 함수를 사용할 수 있다.
    foo();
}