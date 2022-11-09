#include <iostream>

using namespace std;

// 추상 클래스는 instance화 할 수 없기 때문에 type으로 쓸 수 없을까?
// 그렇지 않다. 이 녀석은 자식 클래스들을 가리키는 포인터나 레퍼런스 타입으로 사용할 수 있다.
// class Shape {
// public:
//     // 넓이를 구하는 getArea 함수. 그런데 현재는 어떤 도형인지 모르기 때문에
//     // 이 Shape라는 클래스 내에서는 넓이를 구할 수 없다.
//     // 이 Shape라는 클래스를 상속받은 도형들(Circle 등)에서야 getArea()함수를 overriding하여 사용할 수 있다.
//     // 이런 경우에, 함수 앞에 virtual을 붙여주고, 정의 없이 선언에 = 0 을 붙여준다.
//     // 아래 함수를 순수 가상함수 라고 한다.
//     virtual double getArea() const = 0;

//     // 상속을 위한 클래스이기 때문에, 후에 메모리 누수를 예방하고자 파괴자를 virtual로 선언해준다.
//     virtual ~Shape(){}
// };

// int main() {
//     Shape s; // error -> 추상클래스는 instance화 할 수 없다.
// }

// class Shape {
// public:
//     virtual double getArea() const = 0;
//     virtual ~Shape(){}
// };

// // Shape을 상속받은 Circle 클래스
// // 추상 클래스를 상속받은(정의한?) 자식클래스는 순수 가상함수를 overriding하여 구현해줘야한다.
// // 그렇지 않으면 Circle도 추상 클래스가 된다.
// // 현재 Shape 클래스에는 멤버 변수나, 정의되어있는 멤버 함수가 따로 없다.
// // 이런 클래스를 Interface라고도 한다.
// class Circle : public Shape {
// private:
//     double _radius;
// public:
//     Circle(double radius)
//         : _radius(radius){}

//     virtual double getArea() const override {
//         return _radius * _radius * 3.14;
//     }
// };

// class Rectangle : public Shape {
// private:
//     double _width;
//     double _height;
// public:
//     Rectangle(double width, double height)
//         : _width(width), _height(height) {}
    
//     virtual double getArea() const override {
//         return _width * _height;
//     }
// };

// // 각 도형 너비의 평균을 구하는 class
// class AreaAverage {
// private:
//     double _total = 0;
//     double _size = 0;
// public:
//     double operator()(Shape& shape) {
//         _size += 1;
//         _total += shape.getArea();
//         return _total / _size;
//     }
// };

// int main() {
//     // Circle c; // Shape의 순수 가상함수를 overriding하지 않으면 객체화가 불가하다.
//     Circle c(10);
//     cout << c.getArea() << endl; // 314

//     Rectangle r(10, 20);
//     cout << r.getArea() << endl; // 200

//     Shape* s0 = &c;
//     Shape& s1 = r;

//     cout << s0->getArea() << endl; // 314
//     cout << s1.getArea() << endl; // 200

//     // 넓이 평균을 구하는 class 실행
//     AreaAverage aavg;
//     cout << aavg(c) << endl; // 314
//     cout << aavg(r) << endl; // 257
// }

class Shape {
public:
    // 아래와 같은, virtual이 아닌 함수만 가진 클래스를 추상 클래스로 만들고 싶다면
    void func() {
        cout << "do something" << endl;
    }

    // 소멸자에 virtual과 = 0 을 붙여주면 된다.
    virtual ~Shape() = 0;
};

Shape::~Shape(){} // 이렇게 외부에서 소멸자를 정의해주면
// Shape가 추상 클래스가 되면서, 다른 녀석들이 Shape를 상속받아 사용할 수 있고
// Shape는 instance화 할 수 없다.
// 사실 이게 뭔지 왜 필요한지는 잘 모르겠지만 일단 자세한건 나중에 알아보자...

int main() {

}