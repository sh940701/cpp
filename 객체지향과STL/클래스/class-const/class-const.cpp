#include <iostream>

using namespace std;

// class Person{
// private:
//     const string _name = "abc";
//     float _weight;
//     float _height;
// public:
//     Person(const string& name, int weight, int height) 
//     : _name(name), _weight(weight), _height(height) {
//     }
//     // 아래와 같이 멤버함수에 const를 붙일 수 있다. 그 원리에 대해 생각해보자
//     // 멤버함수 내에서 this를 선언할 수 있다. 그리고 this는 해당 인스턴스를 가리킨다.
//     // 이를 통해서, this는 Person type의 pointer이고, 멤버함수의 파라미터에 포함되어
//     // 오는 것임을 알 수 있다. 그리고 함수 프로토타입 뒤에 const를 붙여주는 것은
//     // 아래와 같이 Person* this 앞에 const가 붙는 것과 마찬가지이다.
//     float getWeight( /* const Person* this */ ) const
//     {
//         // 위와 같이 const로 선언해주면 _weight에 대한 초기화가 불가능하다.
//         // _weight = 10 -> error
//         // 그 이유는, _weight = 10은 this->_weight = 10과 같은 것이라고 했는데
//         // this가 const로 상수화되었기 때문에 그 값을 변경할 수 없는 것이다.
//         return _weight;
//     }
// };

// int main() {
//     Person person("david", 75, 181);
//     cout << person.getWeight() << endl;
// }

// class Person{
// private:
//     const string _name = "abc";
//     float _weight;
//     float _height;
// public:
//     Person(const string& name, int weight, int height) 
//     : _name(name), _weight(weight), _height(height) {
//     }

//     float getWeight( /* Person* this */ )
//     {
//         return _weight;
//     }
// };

// int main() {
//     // 만약 프로그래머가 아래 david 객체를 변경할 수 없도록 const 선언을 한다고 하자.
//     // 그런데 이 때 class 내의 멤버함수 프로토타입 뒤에 const가 선언되어있지 않으면
//     // person.getWeight()함수는 실행되지 않는다. 그 이유는 const Person type 포인터는
//     // 일반 Person type 포인터로 바뀔 수 없기 때문이다.
//     // 멤버함수의 프로토타입 뒤에 const를 선언해주지 않으면, 넘어갈 때 const Person type 포인터가 아니라
//     // 위 멤버함수에 주석처리 되어있는 것 처럼 일반 Person type 포인터로 변경되어 넘어간다.
//     // 이러한 변경이 불가능하기 때문에 에러가 발생하는 것이다.

//     const Person person("david", 75, 181);
//     cout << person.getWeight() << endl; // error


// }

class Person{
private:
    const string _name = "abc";
    float _weight;
    float _height;
public:
    Person(const string& name, int weight, int height) 
    : _name(name), _weight(weight), _height(height) {
    }

    float getWeight( /* Person* this */ )
    {
        return _weight;
    }
};

int main() {
    // "값"을 복사해보자
    // const person을 person에 대입 -> 가능
    // const person을 const person에 대입 -> 가능
    // person을 person에 대입 -> 가능
    // person을 const person에 대입 -> 가능
    // 값을 "=" 연산자로 할당하는 것은, 그저 "복사"가 되는 것이기 때문에 언제든 가능하다.
    // const Person person0("daniel", 56, 174);
    // const Person person1 = person0;

    // 포인터에 대한 연산은 다르다.
    // 포인터의 경우 일반 포인터를 const 포인터에 대입은 가능하지만
    // const 포인터를 일반포인터에 대입할 수는 없다.
    // 일반 포인터를 const 포인터에 대입하여 상수화 하면 앞으로 안 바꾸면 되지만
    // const 포인터를 일반 포인터로 대입하게 되면 이미 상수화된 값을 바꿀 수 있게 되기 때문이다.
    // 당연히 const 포인터를 const 포인터에 대입하는 것은 가능하다.

    // 같은 맥락에서, 외부에서 const 선언이 된 객체가 있으면, 이에 대한 멤버함수를 사용할 때
    // 멤버함수 프로토타입 뒤에 const 선언이 되어 있으면 const 포인터 -> const 포인터(this)로 넘어가지만
    // const 선언이 되어있지 않으면, const 포인터 -> 일반 포인터(this)로 변경되어 넘어가기 때문에
    // 실행이 불가한 것이다.
    // 만약 멤버함수에 const 선언을 해주지 않으면, 다른 누군가가 const 인스턴스를 만들었다가
    // 변경이 되면 안 되는 객체임에도 불구하고 함수를 사용하기 위해 const를 해제할 수도 있고
    // 이로 인해 추후 프로그래밍을 진행할 때 바뀌면 안되는 객체가 바뀌게 되는 불상사가 생길 수도 있다.
    const Person* person0 = new Person("Daniel", 56, 174);
    const Person* person1 = person0;
}