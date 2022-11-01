#pragma once

class Person {
private:
    // static 멤버는 클래스 내에서 초기화가 불가능하다.
    static int num = 10; // error
    // class 내 static 멤버는 class scope 내에서 접근할 수 있는 전역변수라고 생각할 수 있다.
    static int num;
    int a;

    // 만약 멤버변수가 static const 타입인 경우, class를 정의해줄 때 초기화가 가능하다.
    static const int num = 0; // 정상

public:
    Person();
    // 멤버함수도 static으로 선언해줄 수 있다.
    // 다만 static으로 선언한 경우, 뒤에 const를 붙여줄 수 없고, 정적멤버가 아닌 멤버에도 접근할 수 없다.
    // 그 이유는 static 멤버에는 this가 넘어가지 않기 때문이다.
    // 객체가 구체화되어야 this가 활성화되는데, static 멤버는 class scope내 전역변수로서
    // 객체가 구체화되지 않아도 접근할 수 있다. 그러므로 this가 넘어가지 않아
    // 멤버변수가 아닌 변수에 접근할 수 없고, const로 this를 상수화 해줄 수도 없는 것이다.
    static void print();
};

// 또한 아래와 같이 header파일에서 static 멤버를 초기화해주면 안된다.
// 그렇게 되면 이를 include하는 모든 파일에서 Person::num을 여러번 초기화 해주는 것이 되기 때문이다.
int Person::num = 10; // 2회 이상 include시 error