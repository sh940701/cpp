#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    float _weight;
    float _height;
    char* _name;

public:
    Person(){};
    Person(float weight, float height, const char* name)
        :_weight(weight), _height(height), _name(new char[strlen(name) + 1]) {
            strcpy(_name, name);
        }
    
    void printName() const {
        cout << &_name[0] << endl;
    }

    void changeName() {
        _name[0] = 'q';
    }

    // 복사 생성자를 오버로딩해보자
    Person (const Person& person) // 복사 생성자의 프로토타입이다.
        :_weight(person._weight), _height(person._height), _name(new char[strlen(person._name) + 1])
        // 위와 같이 생성자를 그대로 인용해도 되고, 아래와 같이 이미 만들어진 생성자를 사용해 위임생성해도 된다.
        // :Person(person._weight, person._height, person._name)
    {
        strcpy(_name, person._name);
    }

    // 대입 연산자를 오버로딩해보자
    Person& operator=(const Person& person) {
        _weight = person._weight;
        _height = person._height;
        // 대입 연산자는 이미 초기화 되어있는 대상에 대입을 하는 것이다.
        // 그러므로 이미 선언되어있는 _name을 해제 후 새로운 동적 할당을 하여야 메모리 누수가 발생하지 않는다.
        // 강의에서는 그냥 delete[] _name;을 선언해주었는데, 내가 하니까 에러가 자꾸 났다.
        // 그래서 생각을 해보니 기본 생성자로 인자값 없이 생성을 한 객체는 _name에 메모리가
        // 할당되지 않았을 것이라는 생각이 들어, 동적으로 _name 메모리를 할당받은 객체에 대하여만 delete를 해주었다.
        if (strlen(_name)){
            cout << "delete" << endl;
            delete[] _name;
        }
        // 이후 새로운 동적 할당 배열을 만들어서 값을 넣어준다.
        _name = new char[strlen(person._name) + 1];
        strcpy(_name, person._name);
        return *this;
    }

    ~Person() {
        if (strlen(_name)) {
            cout << strlen(_name) << endl;
            delete[] _name;
        }
    }
};

int main() {    
    Person person0{70.f, 180.f, "Json"};
    Person person1 = person0; // 복사 생성자 호출
    Person person2;
    // person2 = person0; // 대입/할당 연산자 호출
    // person2 = person1;

    // person0.changeName();

    person0.printName();
    person1.printName();
    person2.printName();
}