#include <iostream>

using namespace std;

// int pow(int base, int exp = 2) {
//     int result = 1;
//     for (int i = 0; i < exp; ++i) {
//         result *= base;
//     }

//     return result;
// }


// 다른 타입의 파라미터도 아래와같이 default값을 정해줄 수 있다.
// struct Person {
//     float weight;
//     float height;
// };

// // Person 타입의 p를 선언
// Person p{67, 175};

// // foo 함수가 접근할 수 있는 곳에 선언되어있기때문에, default값으로 p를 선언할 수 있다.
// void foo(Person p0 = p) {
// // void foo(Person p0 = Person{30, 30}) { -> 이와같이도 default 매개변수를 넣어줄 수 있다.
//     cout << p0.weight << endl;
//     cout << p0.height << endl;
// }

// int main() {
//     // deafult 매개변수의 값
//     foo(); // 67, 175
//     // 전달한 매개변수의 값
//     foo(Person{74, 183}); // 74, 183
// }

struct Person {
    float weight;
    float height;
};

// Person 타입의 p를 선언
Person p{67, 175};

void print(Person* p0 = nullptr) {
    if (p0) {
        cout << p0->weight << endl;
        cout << p0->height << endl;
    } else {
        cout << "invalid" << endl;
    }
}

int main() { 
    print(); // invalid
    Person p = { 173, 65 };
    print(&p); // 173, 65
}