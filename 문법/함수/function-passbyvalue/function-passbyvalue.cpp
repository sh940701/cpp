#include <iostream>

using namespace std;

// swap 함수를 만들어보자
// void swap(int* px, int* py) {
//     cout << "px addr: " << px << endl;
//     cout << "py addr: " << py << endl;
//     int temp = *px;
//     *px = *py;
//     *py = temp;
//     cout << *px << endl;
// }

// int main() {
//     // 두 변수의 값을 교환하는 함수
//     int x = 10, y = 20;

//     cout << "x: " << x << endl;
//     cout << "y: " << y << endl;

//     // 교환
//     swap(&x, &y);

//     cout << "x addr: " << &x << endl;
//     cout << "y addr: " << &y << endl;
// }

struct Weapon {
    int price;
    int power;
};

void upgrade(Weapon* weapon) {
    weapon->power += 10;
    weapon->price += 10;
}

int main() {

    Weapon weapon{10, 20};

    cout << "Price: " << weapon.price << endl;
    cout << "Power: " << weapon.power << endl;

    upgrade(&weapon);
    
    cout << "Price: " << weapon.price << endl;
    cout << "Power: " << weapon.power << endl;
}