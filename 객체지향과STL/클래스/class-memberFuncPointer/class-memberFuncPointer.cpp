#include <iostream>
#include <functional>

using namespace std;

// class Person {
// public:
//     void print(int i) {
//         cout << i << endl;
//     }
// };

// int main() {
//     // 위 Person class의 멤버함수를 가리키는 포인터를 만들어보자
//     // 형식 : return type, (class name::, *, 변수명), (parameter) = &, class name::, 함수명
//     void (Person::*fn)(int) = &Person::print;

//     // 아래와 같이 하면 실행이 안된다. 왜그럴까? -> 멤버함수에는 this를 넘겨야하는데
//     // 구체화된 녀석이 없어 this가 없기 때문이다.
//     // *fn(1);

//     // 구체화된 녀석이 필요하다.
//     Person person;
//     // 실행을 하기 위해선 아래와 같이 진행해야 한다.
//     // (instance.*변수명)(parameter)
//     (person.*fn)(1);
// }

// class Person {
// public:
//     void print(int i) {
//         cout << i << endl;
//     }
//     void square(int i) {
//         cout << i*i << endl;
//     }
// };

// int main() {
//     typedef void (Person::*FuncType)(int);
//     FuncType fn = &Person::print;
//     FuncType sq = &Person::square;

//     Person person;
//     (person.*fn)(1); // 1
//     (person.*sq)(3); // 9
// }

// // const 멤버함수 포인터로 변경하여 실행해보기
class Person {
public:
    // 멤버함수내 this를 const Person* this 로 바꿔줌
    void print(int i) const {
        cout << i << endl;
    }
    void square(int i) const {
        cout << i*i << endl;
    }
};

int main() {
    // const Person타입 포인터를 넣어줘야 함
    function<void(const Person*, int)> fn = &Person::print;
    function<void(const Person*, int)> sq = &Person::square;

    // const Person* type의 person 이라는 pointer를 동적으로 생성
    // 일반 Person* type의 pointer에서 const Person* type pointer로 변경은 가능하기 때문에
    // Person* person = new Person(); 으로 선언해줘도 된다.
    const Person* person = new Person();

    // person이 const Person* 포인터이기 때문에 그대로 넣어준다.
    fn(person, 1); // 1
    sq(person, 3); // 9
}


// class Person {
// public:
//     void print(int i) {
//         cout << i << endl;
//     }
//     void square(int i) {
//         cout << i*i << endl;
//     }
// };

// int main() {
//     // function을 사용할 때는 지금까지 계속 말했던 "this pointer"를 넘겨줘야 한다.
//     // 그래서 첫번째 인자로 Person type의 pointer를 넘겨주는 것이고, 이후 파라미터를 넘겨준다.
//     function<void(Person*, int)> fn = &Person::print;
//     function<void(Person*, int)> sq = &Person::square;

//     Person person;

//     // 실제로 포인터로 함수를 실행할 때도 person의 주소값을 먼저 넘겨주어 this 포인터로 만들어주고
//     // 그 뒤부터 parameter를 넣는다.
//     fn(&person, 1); // 1
//     sq(&person, 3); // 9
// }

// static 멤버함수 포인터로 가리켜보기
// class Person {
// public:
//     static void print(int i) {
//         cout << i << endl;
//     }
//     static void square(int i) {
//         cout << i*i << endl;
//     }
// };

// int main() {
//     // static 멤버함수 포인터는 일반 함수와 똑같다.
//     void (*fn)(int) = Person::print; // &Person::print; 심지어 주소값을 보내지 않아도 되는 것도 같다.
//     void (*sq)(int) = Person::square; // &Person::square;

//     fn(1); // 1
//     sq(3); // 3
// }