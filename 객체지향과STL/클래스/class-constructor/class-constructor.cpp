#include <iostream>

using namespace std;

// class Player{
// private:
//     int _health;
//     int _power;

// public:
//     // 아래에서 player3, 4, 5의 형식으로 선언해주기 위한 생성자
//     Player() {
//         _health = 100;
//         _power = 50;
//         cout << "Player " << _health << ", " << _power << endl;
//     }

//     // 생성자를 만들었다.
//     // 클래스 안에 있는 멤버함수들도 모두 overloading이 가능하다.
//     Player (int health, int power) {
//         _health = health;
//         _power = power;
//         cout << "Player " << _health << ", " << _power << endl;
//     }
// };

// int main() {
//     // 생성자의 형식에 맞춰, 다양한 방식으로 생성자를 호출할 수 있다.
//     Player player0(200, 100);
//     Player player1 = Player(300, 150);
//     // new를 이용하여 힙 영역에 동적으로 선언
//     Player* player2 = new Player(400,200);

//     Player player3;
//     Player player4 = Player();
//     Player* player5 = new Player();
// }

// 생성자가 없는 class의 default 생성자는 멤버들의 default 생성자를 호출한다
// class Test {
// public:
//     int num;
//     Test() {
//         num = 10;
//     }
// };

// class Player{
// public:
//     int _health;
//     int _power;
//     // Test라는 class의 객체인 _test를 인자값으로 넣어줬다.
//     Test _test;
// };

// int main() {
//     // player3의 멤버에는 _test가 포함되어있고, 이는 class를 인스턴스화 한 객체이다.
//     // 위에서 언급한대로 멤버의 default 생성자를 호출해주어 plyaer3._test.num의 값이 있는 것이다.
//     Player player3;
//     Player player4 = Player();
//     Player* player5 = new Player();

//     cout << player3._test.num << endl; // 10
// }


// class Player{
// private:
//     int _health;
//     int _power;

// public:
//     // 아래와 같은 선언 방법을 "위임 생성자", "Delegating constructor"라고 한다.
//     // 인자값이 없이 생성자가 실행되면 아래 생성자에 100, 50을 넣고 실행시키는 것이다.
//     Player() : Player(100, 50) {}
//     Player (int health, int power) {
//         _health = health;
//         _power = power;
//         cout << "Player " << _health << ", " << _power << endl;
//     }
// };

// int main() {
//     Player player6; // 100, 50
// }


// class Player{
// private:
//     int _health;
//     int _power;
//     // 이름을 인자값으로 받고싶은데, 이름은 한 번 정하면 바꿀 수 없으므로 const로 선언해줬다.
//     const string _name;

// public:
//     // name의 입력값이 없으면 _name을 "noname"으로 정해줌
//     Player() : Player(100, 50, "noname") {}
//     Player (int health, int power, string name) {
//         _health = health;
//         _power = power;
//         // 그런데 할당이 안 된다. 왜 그럴까?
//         // 위에서 const staring _name;으로 선언했기 때문에, 이미 상수화가 되었고, 초기화가 불가능한 상태인 것이다.
//         _name = name;
//         cout << "Player " << _name << ", " << _health << ", " << _power << endl;
//     }
//     void print() {
//         cout << _name << ": " << _health << ": " << _power << endl;
//     }
// };

// int main() {
//     Player player6; // 100, 50
// }


class Player{
private:
    int _health = 100;
    int _power = 50;
    const string _name = "noname";

public:
    // 컴파일러가 만들어준 생성자를 default로 한다고 명시하고 싶을때는 아래와 같이 선언해준다.
    Player() = default;
    Player (int health, int power, string name)
		 : _health(health), _power(power), _name(name)
		{
        cout << "Player " << _name << ", " << _health << ", " << _power << endl;
    }
    void print() {
        cout << _name << ": " << _health << ": " << _power << endl;
    }
};

int main() {
    Player player6;
    player6.print(); // noname: 100: 50
}
