#include <iostream>

using namespace std;

// void swap(int& px, int& py) {
//     int temp = px;
//     px = py;
//     py = temp;
// }

// int main() {
//     int x= 10, y = 20;
//     swap(x, y);

//     cout << x << endl;
//     cout << y << endl;
// }

// struct Weapon{
//     int price;
//     int power;
// };

// void upgrade(Weapon& pWeapon) {
//     pWeapon.price += 10;
//     pWeapon.power += 10;
// }

// int main() {
//     Weapon weapon{10, 20};
//     upgrade(weapon);

//     cout << weapon.price << endl;
//     cout << weapon.power << endl;
// }

// const reference



// int main() {
    // int& def = 1; // error

    // int x;
    // int& def0 = x; // 정상

    // const int& def = 1;

    // float f = 1.f;
    // int& def = f; // error
    // const int& def = f; // 정상

    
    // float f = 1.f;
    // const int& def = f;

    // 위와같이 선언 된 상황에서 f의 값은 바꿀 수 있다.
    // f = 10;
    // 그러나 def는 const로 선언되었기때문에 바꿀 수 없다.
    // def = 1;

    // 그리고 f와 def를 출력해보면, f는 바뀐 값, def는 이전 값을 나타낸다.
    // cout << f << endl; // 10
    // cout << def << endl; // 1 -> def는 f의 "별명"인데 왜 이런 일이 발생하는것일까?
    // 사실 def는 내부적으로 f 자체를 가리키는 것이 아니라, 임시 객체를 만들어서 그 녀석을 가리킨다.
    // 그렇다면 왜 이런 과정을 거치는것일까?
// }

// // 값으로 받는 제곱 함수
// int squarev(int value) {
//     return value * value;
// }
// // reference로 받는 제곱 함수
// int squarer(int& ref) {
//     return ref * ref;
// }

// int main() {
//     int x = 10;
//     // 값과 reference로 받는 함수 둘을 동시에 실행해보자
//     cout << squarev(x) << endl; // 100
//     cout << squarer(x) << endl; // 100 -> 잘 출력된다.

//     // 그렇다면 리터럴 데이터를 넣어보자
//     cout << squarev(10) << endl; // 100
//     cout << squarer(10) << endl; // error -> reference에 리터럴 데이터를 보내니 에러가 난다.
//     // 이는 reference 변수에 리터럴 데이터를 넣을 수 없는 것과 같은 원리이다.
//     // 이를 해결하기 위해서는 squarer함수의 인자값에 const를 붙여주면 된다. (const int& ref)
// }

// 레퍼런스값을 리턴해주는 함수

struct Weapon {
    int price;
};

// weapon값을 레퍼런스로 받고, weapon의 price를 레퍼런스로 리턴해줘보자
int& func(Weapon& weapon) {
    return weapon.price;
}

int main() {
    Weapon weapon{10};
    func(weapon) = 20;

    cout << weapon.price << endl;
}