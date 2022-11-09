#include <iostream>

using namespace std;

// class A {
// public:
//     int num;

//     // A (const A& a) {} -> 기본 복사생성자, 이 인자값으로 B가 들어갈 수 있다.
// };

// class B : public A {

// };

// // A 타입 인자를 받는 함수지만, B가 A의 자식이기 때문에 B를 넣어도 동작한다.
// // A의 레퍼런스 타입이 B를 가리킬 수 있기 때문
// A operator+(const A& x, const A& y) {
//     A a;
//     a.num = x.num + y.num;
//     return a;
// }

// // 똑같이 생긴 operator(+)이지만, 받는 타입이 B이고, 내부적으로 *연산을 해줘보자
// // 아래 함수를 만들어주니, 좀 더 구체적인 타입(B)를 받는 아래 함수로 들어와 200이 나왔다.
// B operator+(const B& x, const B& y) {
//     B b;
//     b.num = x.num * y.num;
//     return b;
// }

// int main() {
//     B b0, b1;

//     b0.num = 10;
//     b1.num = 20;

//     // A operator + 만 있으면, 결과값이 30이 나온다.
//     // B operator + 가 있으면, 인자값의 타입에 따라 B operator + 로 들어간다.
//     // 이 때 결과값(b0 + b1)은 A의 복사생성자에 들어가게 된다.
//     // 나온 결과값은 B 타입이지만, A의 자식이기 때문에 A의 복사생성자에 들어가서
//     // A로 변환되기 때문에 아래 연산자가 문제없이 작동하게 된다. -> 200
//     A a0 = b0 + b1;

//     cout << a0.num << endl; // 30 -> 200
    
//     // 아래와 같은 상황을 추가해보자. A 타입 레퍼런스에 위 b의 객체들을 담아보자
//     A a1 = b0;
//     A a2 = b1;

//     A a3 = a1 + a2;

//     cout << a3.num << endl; // 30
//     // 위와 같이 실행하니 A operator + 로 들어갔다. 실제로 가리키는 녀석은 b1인데 왜 그럴까?
//     // 여기서 a1과 a2는 실제로 가리키는 타입이 아니라 이를 가리키는 A타입으로 취급된다는 것을 알 수 있다.
//     // 이를 통해 overloading은 정적 결합이라는 것을 알 수 있다. 실제로 어떤 타입을 가리키는지가 아니라
//     // 컴파일 타임에 정해진, 선언된 객체의 타입만 보고 간다. -> 정적타입 바인딩 : 실제로 컴파일 타임에 어떤 함수로 갈지 정해진다.
// }


// 정적 바인딩(함수 오버로딩) 다른 예시

// func라는 함수 생성
// void func(int x) {
//     cout << x << endl;
// }

// // 같은 이름의 함수 오버로딩
// void func(int x, int y) {
//     cout << x << endl;
//     cout << y << endl;
// }

// int main() {
//     // 아래와 같이 함수 두 개를 실행할 때, 실제로 어셈블리 파일에서는 두 함수에 다른 이름을 붙인다.
//     // 이를 name decoration이라고 하는데, 결국 실제로 기계가 인식하는 이름은 다르고
//     // 이에 따라서 코드를 컴파일 할 때 어떤 이름의 함수를 사용할지 미리 정해진다.
//     // 그러므로 "함수 오버로딩은 정적 타입 바인딩이다." 라고 할 수 있다.
//     func (1);
//     func (1, 1);
// }

// 동적 바인딩 예시

// Animal이라는 클래스와, 이를 상속받는 Dog, Cat 클래스를 만들었다.

// class Animal {
// public:
//     virtual void eat() const {
//         cout << "냠" << endl;
//     }
// };

// class Cat : public Animal {
// public:
//     Cat(){}
//     virtual void eat() const override {
//         cout << "냥" << endl;
//     }
// };

// class Dog : public Animal {
// public:
//     Dog(){}
//     virtual void eat() const override {
//         cout << "멍" << endl;
//     }
// };

// void func(Animal* animal) {
//     animal->eat();
// }

// int main() {
//     // Animal type의 포인터로 Dog를 가리킨다.
//     Animal* a = new Dog();
//     a->eat(); // 멍 -> 이녀석은 런타임 도중에 a가 무엇을 가리키고 있는지 확인 후 호출을 해준다.
//     func(a); // 멍 -> 이 녀석 또한 virtual이 선언되어있기 때문에 실제 가리키고 있는 타입의 함수에 접근한다.

//     // 만약 위 eat()함수를 상호간 virtual로 선언해주지 않고, override 해주지 않고 함수를 실행하면
//     // 단순히 최종적으로 가리키는 포인터의 타입만 반영하여 함수를 실행하게 된다.
//     // 위와 같은 경우에는 Animal* a 로 어떤 타입을 가리키던지 상관없이 "냠"이 나오게 된다.
// }

class Animal {
public:
    virtual void eat() const {
        cout << "냠" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(){}
    virtual void eat() const override {
        cout << "냥" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(){}
    virtual void eat() const override {
        cout << "멍" << endl;
    }
};

void func(Animal* animal) {
    animal->eat();
}

int main() {
    Animal* a = new Dog();
    a->eat();
    func(a);
}