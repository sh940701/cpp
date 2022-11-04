#include <iostream>
#include <string>

using namespace std;

// class Vector {
// private:
//     int x, y, z;
// public:
//     Vector (int x, int y, int z) : x(x), y(y), z(z) {

//     }

//     friend ostream& operator<<(ostream& os, Vector& v) {
//         os << v.x << " " << v.y << " " << v.z;
//         return os;
//     }
// };



// int main() {
//     Vector v{1, 2, 3};
//     // 아래와 같이 하여 출력하고싶다. 그런데 cout.operator<<(v);의 오버로딩은 불가능하다.
//     // 그 이유는, cout은 다른 어떤 클래스에서 정의가 되어있기 때문이다.
//     // 해당 클래스 내에서 직접 << 연산자 오버로딩을 하지 않는 이상 불가하다.
//     // 따라서 전역함수로 overloading을 진행해보자 -> operator<<(cout, v);
//     cout << v;
//     // cout의 멤버함수로서 << 연산자에 대해  endl 을 받을 때의 오버로딩이 되어있다.
//     // 따라서 아래 함수는 내부적으로 operator<<(cout, v).operator<<(endl); 의 모습으로 실행된다.
//     cout << v << endl;
// }


// class Vector {
// private:
//     int x, y, z;
// public:
//     Vector(){};
//     Vector (int x, int y, int z) : x(x), y(y), z(z) {
//     }

//     friend ostream& operator<<(ostream& os, Vector& v) {
//         os << v.x << " " << v.y << " " << v.z;
//         return os;
//     }

//     // cin으로 값을 입력받아 vector를 만들어보자
//     friend void operator>>(istream& is, Vector& v) {
//         string temp;
//         // 10 20 30 을 입력하면 한번에 세 개가 채워진다.
//         // null 문자를 기준으로 입력값을 받기 때문이다.
//         // 10만 누르고 enter를 입력하면 나머지 cin을 입력해줘야한다.
//         // null 문자를 기준으로 잘랐을 때, 입력값이 하나밖에 없기 때문이다.
//         is >> temp;
//         v.x = stoi(temp);

//         is >> temp;
//         v.y = stoi(temp);

//         is >> temp;
//         v.z = stoi(temp);
//     }
// };

// int main() {
//     Vector v;
//     cin >> v; // operator>>(cin, v);
//     cout << v << endl;
// }

class Vector {
private:
    int x, y, z;
public:
    Vector(){};
    Vector (int x, int y, int z) : x(x), y(y), z(z) {
    }

    // 출력 연산자 << 오버로딩
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }

    // ~ 연산자 오버로딩
    Vector operator~() const {
        return Vector(~x, ~y, ~z);
    }

    // & 연산자 오버로딩
    Vector operator&(const Vector& v) const {
        return Vector(x & v.x, y & v.y, z & v.z);
    }

    // | 연산자 오버로딩
    Vector operator|(const Vector& v) const {
        return Vector(x | v.x, y | v.y, z | v.z);
    }

    // ^ 연산자 오버로딩
    Vector operator^(const Vector& v) const {
        return Vector(x ^ v.x, y ^ v.y, z ^ v.z);
    }
    
    // 비트연산자 << 오벼로딩
    Vector operator<<(int v) const {
        return Vector(x << v, y << v, z << v);
    }

    // 비트연산자 >> 오벼로딩
    Vector operator>>(int v) const {
        return Vector(x >> v, y >> v, z >> v);
    }
};

int main() {
    Vector v{0, 0, 0};
    Vector v1{1, 1, 1};
    Vector v2{1, 1, 0};
    Vector v3{1, 4, 8};
    // 아래가 실행이 안된다. 왜그럴까?
    // 아래에서 ~v 를 실행한 결과값은, 어떠한 변수에 담기는 게 아니라
    // 임시값으로 리턴이 된다. 그냥 Vector {int, int, int} 그 자체인 것이다.
    // 어떤 변수에 담기지 않은 리터럴 데이터는 Vector&와 같이 레퍼런스로 담을 수 없다.
    // 그런데 위에서 출력 << 연산자 오버로딩에는 Vector를 받을 때 그냥 레퍼런스로 받아온다.
    // 이를 변경이 되지 않는다는 의미로 const로 받아주면 문제가 해결된다.
    cout << ~v << endl; // {-1, -1, -1} -> 0인 비트를 모두 1로 바꿔주면, 보수를 취해서 -1이 된다.
    cout << (v & v1) << endl; // {0, 0, 0}
    cout << (v | v1) << endl; // {1, 1, 1}
    cout << (v1 ^ v2) << endl; // {0, 0, 1}
    cout << (v3 << 2) << endl; // {4, 16, 32}
    cout << (v3 >> 1) << endl; // {0, 2, 4}
}