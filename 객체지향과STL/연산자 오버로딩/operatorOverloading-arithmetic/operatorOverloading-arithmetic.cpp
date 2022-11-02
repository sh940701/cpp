#include <iostream>

using namespace std;

// // Vector를 하나 선언, 3d 좌표에서 위치나 방향, 높이를 나타내는 역할
// class Vector {
// public:
//     float x;
//     float y;
//     float z;
// };

// int main() {
//     // 멤버변수를 public으로 선언하면 아래와 같이 인스턴스화를 할 수 있다.
//     Vector v0{0, 1, 2};
//     Vector v1{1, 2, 3};
    
//     // 아래는 내부적으로 다음과 같다. Vector v2 = v0.operator+(v1);
//     // v0에 +라는 operator를 사용하여 v1을 인자값으로 주는 것이다.
//     // 이를 사용하기 위해서는 class 내에서 +를 어떻게 사용할 것인지 정해주어야 한다.
//     Vector v2 = v0 + v1;
//     Vector v3 = -v1;
// }


// class Vector {
// public:
//     float x;
//     float y;
//     float z;

//     // + 연산자 overloading
//     // 내부적으로 this의 값을 바꾸는 함수가 아닌 경우 const를 선언해주자
//     // 또한 parameter의 경우 굳이 인자값을 복사해서 처리할 필요가 없는 경우, 레퍼런스로 받아주자
//     Vector operator+(const Vector& v) const {
//         return Vector{x + v.x, y + v.y, z + v.z};
//     }

//     // 비어있는 - 연산자 overloading
//     Vector operator-() const {
//         return Vector{-x, -y, -z};
//     }
// };

// int main() {
//     // 만약 아래와 같이 const로 선언되어있는 경우, 위 operator 멤버함수도 const로 해주어야 한다.
//     // operator 함수에 this 가 넘어갈 때 const this가 일반 this로 넘어갈 수 없기 때문이다.
//     const Vector v0{0, 1, 2};
//     const Vector v1{1, 2, 3};
    
//     Vector v2 = v0 + v1; // {1, 3, 5}
//     Vector v3 = -v1; // {-1, -2, -3}
// }

// class Vector {
// public:
//     float x;
//     float y;
//     float z;

//     // 이항연산자 +
//     Vector operator+(const Vector& v) const {
//         return Vector{x + v.x, y + v.y, z + v.z};
//     }

//     // 단항연산자 -
//     Vector operator-() const {
//         return Vector{-x, -y, -z};
//     }

//     // 단항연산자 +
//     Vector operator+() const {
//         return *this;
//     }

//     // 이항연산자 -
//     Vector operator-(const Vector& v) const {
//         return Vector{x-v.x, y-v.y, z-v.z};
//     }

//     // 이항연산자 *(Vector * float)
//     Vector operator*(float f) const {
//         return Vector{x * f, y * f, z * f};
//     }

//     // 이항연산자 *(Vector * Vector)
//     float operator*(const Vector& v) const {
//         return x*v.x + y*v.y + z*v.z;
//     }

//     // 이항연산자 /
//     Vector operator/(float f) const {
//         return Vector{x / f, y / f, z / f};
//     }

//     // 이 녀석은 내부적으로 값을 바꾸고 그 값을 복사해 다음 변수에 담아줄 것이기 때문에
//     // const this가 아닌 this만 선언해줘야하여 const를 붙이지 않는다.
//     // *this를 리턴할 때 리턴 타입을 Vector로 하면 틀리다고 하고, 그 이유는 그렇게 보내면
//     // 복사된 값이 보내지기 때문이라고 한다. 따라서 Vector& 타입을 리턴해줘야한다고 하는데
//     // 지금은 사실 무슨 말인지 잘 모르겠다. 결과값도 똑같이 나오는 것 같은데 말이다.....
//     // 단항 전위연산자 ++
//     Vector& operator++() {
//         ++x;
//         ++y;
//         ++z;
//         return *this;
//     }

//     // 단항 전위연산자 --
//     Vector& operator--() {
//         --x;
//         --y;
//         --z;
//         return *this;
//     }

//     // 후위연산자는 전위연산자와 구분해주기 위해 단항연산자임에도 불구하고 파라미터란에
//     // int를 넣어준다. 실제로 int는 아무 역할도 하지 않고, 구분해주기 위해 들어간다.
//     // 단항 후위연산자 ++
//     Vector operator++(int){
//         Vector temp = *this;
//         // 기존에 만들어놓은 전위연산자를 사용해 연산
//         ++(*this);
//         return temp;
//     }
    
//     // 단항 후위연산자 --
//     Vector operator--(int){
//         Vector temp = *this;
//         // 기존에 만들어놓은 전위연산자를 사용해 연산
//         --(*this);
//         return temp;
//     }
// };

// int main() {
//     const Vector v0{0, 1, 2};
//     const Vector v1{1, 2, 3};

//     Vector v2 = +v0; // v2 : {0, 1, 2}

//     Vector v3 = -v0; // v3 : {0, -1, -2}

//     Vector v4 = v0 + v1; // v4 : {1, 3, 5}

//     Vector v5 = v0 - v1; // v5 : {-1, -1, -1}

//     float v6 = v0 * v1; // v6 : 8

//     Vector v7 = v0 * 3.0f; // v7 : {0, 3, 6}

//     Vector v8 = v0 / 3.0f; // v8 : {0, 0.3333, 0.6666}

//     Vector v9 = ++v2; // v9 : {1, 2, 3}, v2 : {1, 2, 3}

//     Vector v10 = v2++; // v10 : {1, 2, 3}, v2 : {2, 3, 4}

//     Vector v11 = --v3; // v11 : {-1, -2, -3}, v3 : {-1, -2, -3}

//     Vector v12 = v3--; // v12 : {-1, -2, -3}, v3 : {-2, -3, -4}
// }

// class Vector {
// private:
//     float x;
//     float y;
//     float z;

// public:
//     Vector(float x, float y, float z) 
//     : x(x), y(y), z(z) {
//     }
//     Vector operator* (float f) {
//         return Vector{x*f, y*f, z*f};
//     }
//     // 전역 operator* 함수의 프로토타입 넣어줌, 이제 전역함수에서 private 멤버에 접근 가능
//     friend Vector operator*(float v0, const Vector& v1);
// };

// // Vector v2 = 3.0f * v0; 를 가능하게 해주기 위해 전역함수 생성
// Vector operator*(float v0, const Vector& v1) {
//     return {v0 * v1.x, v0 * v1.y, v0 * v1.z};
// }

// int main() {
//     Vector v0{0, 1, 2};
//     Vector v1 = v0 * 3.0f; // 이건 된다. -> v0.operator*(3.0f); 와 같다.
//     Vector v2 = 3.0f * v0; // 이건 안된다. -> 3.0f.operator*(v0)는 지원해주지 않기 때문
//     // 전역함수로 선언해준 것은 지원이 안되는 3.0f.operator*(v0); 이 아니라 operator*(3.0f, v0)이다.
//     // 그런데 전역함수는 Vector의 멤버인 x, y, z가 private일 때는 접근할 수 없게 된다.
//     // 이런 경우에는 Vector class 내에 friend를 선언해주고 operator* 전역함수의 프로토타입을 넣어준다.
// }




// 서로 다른 인자를 가지고 있는 object끼리의 연산
// 사실 아래 코드에서는 class 하나가 무조건 밑에 가기 때문에, 내부 friend 선언으로
// 원하는 class간 operator를 구현할 수 없다. 이를 해결하기 위해선 header 파일과 소스파일을
// 사용하여 코드를 작성해야 한다. 다만 중요한 것은 class 간 서로 friend 를 선언해줄 수 있고
// friend로 선언되면 해당 class의 private 멤버에 접근할 수 있다는 것이다.

// 번외로 header파일과 소스파일 없이 아래 class간 operator 함수를 실행시키기 위해서는
// 전역에 두 클래스 간 operator+ 함수를 정의하고, 이를 두 클래스에 각각 friend선언해주면 된다.
// 이 때는 순서 상관없이, 전방선언을 해주면 prototype만 class에 friend되기 때문에 정상적으로 작동한다!

// VectorI 전방선언 -> 전방선언만으로는 안됨
class VectorI;

// float 인자만 갖고 있는 VectorF
class VectorF {
private:
    float x;
    float y;
    float z;

public:
    VectorF(float x, float y, float z) 
    : x(x), y(y), z(z) {}

    // 먼저, 아래 함수를 컴파일 하는 시점에는 VectorI가 선언되어있어야한다.
    // 따라서 최상단에 VectorI를 전방선언해준다.
    // 그런데 전방선언을 해도 에러가 난다! 왜냐하면 아래에서 VectorI v을 사용한 연산이 실행되는데
    // 전방선언만으로는 내부적인 로직을 알 수 없기 때문이다. 따라서 선언이 아닌 정의가 되어있어야 한다.
    VectorF operator+(const VectorI& v) const {
        // 다음으로, VectorI의 멤버는 private이기 때문에 VectorF 멤버함수에서 접근할 수 없다.
        // 그러므로 VectorF의 이 오퍼레이터 멤버함수를 VectorI 내부에 friend로 추가해줘야한다.
        // 그런데 그것보다 좋은 방법은, VectorF클래스 자체를 VectorI 내부에 friend로 추가해주는것이다.
        return VectorF(x + v.x, y + v.y, z + v.z);
    }
};

// int 인자만 갖고 있는 VectorI
class VectorI {
    // 아래와같이 VectorF자체를 VectorI 내부에 선언해준다.
    // 이렇게되면, VectorF는 VectorI의 private 멤버들에 접근할 수 있게 된다.
    friend class VectorF;
private:
    float x;
    float y;
    float z;

public:
    VectorI(int x, int y, int z) 
    : x(x), y(y), z(z) {}

    // VectorF의 멤버함수 friend 추가
    // friend VectorF VectorF::operator+(const VectorF) const; -> 외않됨?
};

int main() {
    
}