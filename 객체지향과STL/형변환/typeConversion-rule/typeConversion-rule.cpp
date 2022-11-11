#include <iostream>

using namespace std;

// void func(float f) {

// }

// int main() {
//     // int type을 float에 대입 -> int에서 float으로 형변환
//     float f = 1;

//     // 함수의 매개변수로 전달할 때 -> int 에서 float으로 변환됨
//     func(1);

//     // 어떤 식에서 데이터 형을 사용할 때
//     // 1은 int에서 float으로 형변환되었다.
//     cout << typeid(1.3f + 1).name() << endl; // float
// }

// int main() {
//     char ch = 'a';
//     // char이 int로 변환되었다.
//     // char는 int보다 사이즈가 작다. 또한 char가 표현할 수 있는 모든 범위를 int가 표현할 수 있다.
//     // 이럴 때는 데이터 형에 대해서 어떤 손실이 일어나지 않고, 이런 것을 promotion, widning 이라고 한다.
//     // 데이터 손실이 없기 때문에 타입 변화에 문제가 없는 것이다. -> 확장변화이기 때문에
//     int num = ch;

//     // 1byte인 char에 그 이상의 int를 넣었기 때문에 다 표현을 할 수 없다. -> 데이터 손실이 일어난다.
//     char ch2 = 1544;
//     // int도 4, float도 4 byte이지만 float은 소수점을 표현할 수 있고 int는 불가하다.
//     // 이러한 경우에도 데이터 손실이 일어난다. -> demotion 등으로 부른다. : 축소변화
//     int i = 1.1f;
// }

// int main() {
//     // 축소변환이 일어나는지 확인하는 초기화 방법 -> uniform initialization
//     char ch{1544}; // error : constant expression evaluates to 1544 which cannot be narrowed to type 'char'
//     int i = {1.1f}; // error : type 'float' cannot be narrowed to 'int' in initializer list
//     char ch{1}; // 얘는 또 된다. -> ch가 표현할 수 있는 범위에 있기 때문
// }

// void func(int num) {
//     char ch{num}; // char ch{num}; 만 있을 때 error발생, num에 ch로 표현가능한 값이 들어올지 아닐지 파악할 수 없기 때문
// }

// void func() {
//     int num = 10;
//     char ch{num}; // 이렇게 변수에 10을 할당하고 실행해도 불가. 변수는 값이 바뀔 수 있기 때문(?)
// }

// void func() {
//     // const int num = 10;
//     const int num = 10000; // 이렇게 되면 손실이 생기기 때문에 안됨
// 	  // 이렇게 상수를 선언하고 넣어주면 정상작동함
// 		// 상수는 바뀔 수 없고, 컴파일타임에 알 수 있으며, 들어있는 수가 표현가능한 수인 것을 알기 때문
//     char ch{num};
// }

// int main() {
    
// }

// 산술연산자.
// 같은 타입일때
// int main() {
//     // short는 2byte, unsigned short의 최대표현값은 65535이다.
//     unsigned short s0 = 40000;
//     // int보다 작은 data인 short나 char같은 경우, 산술연산을 할 때 기본적으로 int로 promotion이 된다.
//     // 아래의 경우 short 끼리의 연산이었지만 + 연산자를 사용함으로 인해 int + int 로 변환된 것이다.
//     // 따라서 결과값도 int이기 때문에 80000이 제대로 출력되었다.
//     cout << s0 + s0 << endl; // 80000

//     // int는 4byte, unsigned int의 최대표현값은 대략 42억이다.
//     unsigned int i0 = 4100000000;
//     // int 이상인 녀석들은 따로 명시를 해주지 않으면 같은 타입으로 연산을 할 때 promotion이 안 된다.
//     // 따라서 아래 결과값은 그대로 unsigned int 타입이기 때문에, 결과값 출력시 overflow가 발생한 것이다.
//     cout << i0 + i0 << endl; // 3905032704 -> overflow 발생
// }

// 다른 타입일때
// int main() {
//     // 다른타입의 산술연산을 실행할 때에는, 기본적으로 int 아래 녀석들은 다 int로 바뀐다.
//     // int 이상인 녀석들과 관련해서는 기본적으로 더 높은 사이즈를 가진 형으로 변환된다.
//     unsigned short s0 = 40000;
//     cout << s0 + s0 << endl; 

//     unsigned int i0 = 4100000000;
//     long long ll0 = 4100000000;
//     // unsigned int인 i0과 long long인 ll0의 산술연산에서 i0가 더 큰 타입인 long long으로 promotion 되었다.
//     // 따라서 아래 연산의 결과값은 long long type이고, overflow가 발생하지 않는다.
//     cout << i0 + ll0 << endl; // 8200000000

//     // int와 unsigned int간의 산술연산의 결과값은 unsigned int가 나온다.
//     // 그런데 조금 이상하긴 하다. 만약 아래와 같이 두 값이 정해진다면, 결과값은 -100이어야 하는데
//     // 타입은 unsigned int이다. 결과적으로 아래와 같은 underflow가 생길 수 있으니 주의해서 사용해야 한다.
//     unsigned int i1 = 10;
//     int i2 = -110;
//     cout << typeid(i1 + i2).name() << endl; // unsigned int
//     cout << i1 + i2 << endl; // 4294967196 unsigned int이기 때문에 -100만큼 underflow가 되었다.
// }

// 부동소수점끼리
// int main() {
//     // 다른 타입의 부동소수점끼리 계산을 할 때는, 결과값의 type이 둘 중 더 큰 type이라고 생각하면 된다.
//     long double, double, float
//     두 피연산자 중 long double이 있다? -> long double로 변한다.
//     두 피연산자 중 long double이 없고 double이 있다? -> double로 변한다.
// }

// 부동소수점과 정수의 연산은 부동소수점으로 변한다.
// int main() {
//     float f = 1.f;
//     unsigned long long ull = 10ULL;

//     cout << typeid(f + ull).name() << endl; // float
// }

// class Test {
// public:
//     // boolean으로의 형변환 연산자에 explicit를 붙여주었다.
//     explicit operator bool() const {
//         return true;
//     }
// };

// int main() {
//     Test t;
//     // explicit가 선언되어있기 때문에 이를 boolean으로 형변환해주기위해선 명시 과정이 필요하다.
//     bool b = (bool)t; // 정상
//     // bool b = t; // error

//     // contextual conversion에서는 아무리 explicit이더라도 명시해줄 필요가 없다.
//     if (t) {} // if문 정상 -> t가 boolean으로 형변환 되었다는 뜻
//     while (t) {} // while문 정상
//     t ? 1 : 2; // 삼항연산자 정상
//     !t; // not 연산자 정상
//     t && true; // &&연산자 정상
//     false || t; // ||연산자 정상
//     // 위와 같은 것을 contextual conversion이라고 한다.
// }

// 그 외 암시적 형변환들

class Parent {

};

class Child : public Parent {

};

void func(Parent* parent) {

}

void func(const Child& child) {

}

int main() {
    int a = 1;
    // 레퍼런스 / 포인터 암시적 형변환
    // 아래에서도 암시적으로 int -> const int로 형변환이 일어나는 것이다.
    const int& b0 = a;
    const int* b1 = &a;

    // 아래에서는 자식 타입의 값이 암시적으로 부모 타입으로 형변환된다.
    Child c;
    Parent* p0 = &c;
    Parent& p1 = c;

    // 함수를 실행하는 순간 Child type -> Parent type으로 암시적 형변환
    func(&c);
    // 함수를 실행하는 순간 Child type -> const Child type으로 암시적 형변환
    func(c);
}