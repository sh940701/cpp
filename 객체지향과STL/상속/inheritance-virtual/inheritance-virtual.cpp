#include <iostream>

using namespace std;

// class Base {
// public:
//     virtual void func() {
//         cout << "Base" << endl;
//     }
// };

// class Derived : public Base {
// public:
//     // 부모클래스의 같은 이름 함수가 virtual인 경우
//     // 자식의 같은 이름 함수는 overriding 되었다고 한다.
//     // 부모의 가상함수를 override 한 함수는, 뒤에 override라고 표현해줄 수 있다.
//     virtual void func() override { 
//         cout << "Derived" << endl;
//     }

//     // 부모의 가상함수를 override한 함수가 아닌 경우, override를 붙이면 컴파일이 불가하다.
//     // 부모 클래스의 같은 이름 함수가 virtual이 아닌 경우, override를 붙이면 컴파일이 불가하다.
//     // 부모 클래스에서 virtual 함수가 아닌 함수와 같은 이름을 선언한 경우, 덮어쓰기가 된다.
//     // void func2() override {} -> error
// };

// // 한 번 더 상속관계를 만들어보자
// class Derived1 : public Derived {
// public:
//     // 코드를 작성할 때, 암시적으로 부모 클래스의 virtual 함수는 virtual이 되지만
//     // 명시적으로 적어주는 관례가 있다.
//     virtual void func() {
//         cout << "Derived1" << endl;
//     }
// };

// void foo(Base& base) {
//     base.func();
// }

// int main() {
//     // virtual 선언이 없는 경우

//     Base b;
//     b.func(); // Base

//     Derived d;
//     d.func(); // Derived

//     // 부모 클래스 타입의 포인터, 레퍼런스로 자식 클래스 객체를 가리켰을 때
//     Base& b0 = d;
//     Base* b1 = &d;

//     // virtual 선언이 없는 경우, 포인터의 타입만을 반영하여 속해있는 함수를 실행한다.
//     b0.func(); // Base -> 부모 func()가 실행됨
//     b1->func(); // Base -> 부모 func()가 실행됨

//     // 부모 클래스 타입의 객체를 받는 함수에 자식 클래스 객체를 보내줌
//     foo(d); // Base -> 부모 func()가 실행됨

// //==========================================================

//     // virtual 선언이 있는 경우
//     Base b;
//     b.func(); // Base

//     Derived d;
//     d.func(); // Derived

//     // 부모 클래스 타입의 포인터, 레퍼런스로 자식 클래스 객체를 가리켰을 때
//     Base& b0 = d;
//     Base* b1 = &d;

//     b0.func(); // Derived -> 자식 func()가 실행됨
//     b1->func(); // Derived -> 자식 func()가 실행됨

//     // 부모 클래스 타입의 객체를 받는 함수에 자식 클래스 객체를 보내줌
//     foo(d); // Derived -> 자식 func()가 실행됨

// //==========================================================

//     // 상속 관계가 한 번 더 정의되었을 때(+virtual)
//     Derived1 d1;
//     foo(d1); // Derived1
//     // 가장 부모가 어떤 이름 함수에 virtual을 선언해 주었을 때, 
//     // 하위의 모든 자식 클래스의 같은 이름 함수는 암시적으로 virtual이 된다.
// }

// 총괄적인 캐릭터 클래스 생성
// class Character {
// private:
//     int _health;
//     int _power;

// public:
//     Character(int health, int power)
//         : _health(health), _power(power) 
//     {

//     }

//     // 공격을 받는 함수 -> virtual로 선언되어 overriding가능
//     virtual void damaged(int power) {
//         _health -= power;
//     }

//     // 공격을 하는 함수
//     void attack(Character& target) const {
//         target.damaged(_power);
//     }
// };

// // 캐릭터 클래스의 자식, 플레이어 클래스
// class Player : public Character {
// public:
//     // 생성자는 아래와 같이 사용해줄 수 있다.
//     Player(int health, int power) : Character(health, power)
//     {}
//     // player의 경우, 공격을 받으면 으악 소리를 내고싶다.
//     // 부모 클래스의 damaged 함수를 override하여 사용
//     virtual void damaged(int power) override {
//         // 아래와 같이 _health를 조작해야 하는데, 부모의 private멤버여서 불가하다.
//         // 이를 해결하기 위해선 부모의 _health를 protected로 선언해주거나
//         // 부모 클래스에 있는 damage 함수를 직접 사용해도 된다.
//         // _health -= power; -> error
//         Character::damaged(power);
//         cout << "으악" << endl;
//     }
// };

// // 캐릭터 클래스의 자식, 몬스터 클래스
// class Monster : public Character {
//     // 자식 클래스에서 따로 더 초기화 해 줄 멤버변수가 없는 경우
//     // 아래와 같이도 진행이 가능하다.
//     using Character::Character;
//     virtual void damaged(int power) override {
//         Character::damaged(power);
//         cout << "꽤액" << endl;
//     }
// };

// int main() {
//     Player player(200, 100);
//     Monster monster(100, 50);

//     // attack을 virtual화 했기 때문에 Character의 damaged가 아니라 Monster의 Damaged가 호출됨
//     player.attack(monster); // 꽤액
//     monster.attack(player); // 으악
// }

// class Character {
// public:
//     ~Character() {
//         cout << "~Character" << endl;
//     }
// };

// class Player : public Character {
// public:
//     ~Player() {
//         cout << "~Player" << endl;
//     }
// };

// int main() {
//     // 부모 클래스의 포인터로 자식 클래스를 가리킴
//     Character *ch = new Player;
//     delete ch;
//     // 둘 다 virtual가 있을 때는 정상,
//     // 자식만 virtual가 있을 때는 error
//     // virtual이 없을 때는 부모 파괴자만 호출

//     // 이유: virtual이 없으면, 자식 클래에서 overriding이 되지 않고
//     // 함수 실행시 상속 관계와 상관없이 해당 포인터 타입의 class 내부의 함수만 실행한다.

//     // 위 예시에서 virtual없이 ch의 파괴자를 호출하면, ch의 타입만 보고
//     // Character class에 있는 함수만 호출하는 것이다.

//     // virtual이 있다면, ch가 실제 어떤 타입을 가리키고 있는지 참작하여 함수를 호출한다.
//     // 따라서 부모가 될 수 있는 class의 소멸자는, 항상 virtual을 붙여줘야한다.
// }

// class Character {
// public:
//     int get() {
//         return 1;
//     }
// };

// class Player : public Character {
// public:
//     // 이름이 가린 상황에서 부모 함수를 쓰고 싶으면 using을 사용한다.
//     using Character::get;

//     int get(int num) {
//         return num;
//     }
// };

// int main() {
//     Player p;
//     p.get(1); // 정상
//     p.get(); // error -> 이름이 가려져서 Character의 get()은 p에 없음
// }

// class Character {
// public:
//     virtual Character* get() {
//         return nullptr;
//     }
// };

// class Player : public Character {
// public:    
//     virtual Player* get() {
//         return nullptr;
//     }
// };

// int main() {
//     Player p;
//     p.get(); // 정상
//     p.get(); // error -> 이름이 가려져서 Character의 get()은 p에 없음
// }

// 문제
// class Character {
// public:
//     int num;
// };

// class Player : public Character {
// private:
//     int num;
// };

// int main() {
//     Player p;
//     p.num; // -> Player class의 private num이다.
//     // 내부적으로 Character의 num과 Player의 num 두 개를 갖게 된다.
// }

// 해결
class Character {
public:
    int num;
};

class Player : public Character {
private:
    using Character::num;
};

int main() {
    Player p;
    p.num; // -> Character class의 num이자, Player class의 private한 num이다.
}