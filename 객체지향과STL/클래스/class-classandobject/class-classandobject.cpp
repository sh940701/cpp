#include <iostream>
#include <string>

using namespace std;

// Player라는 class 선언 -> 기본적으로 접근 지정자가 private이다.
// class Player {
// public: // 접근 지정자 -> 접근 허용
//     int health; // 클래스가 가지고 있는 변수들을 "멤버변수"라고 한다.
// private: // 접근지정자 -> 접근 불허
//     int power;
// };

// int main() {
//     // Player형의 player0변수 선언
//     Player player0; // 이 class 형으로 선언된 변수를 "객체"라고 한다.
//     // 또한 player0은 Player class의 인스턴스라고도 하고,
//     // Player class를 사용하여 player0 변수를 만든것을 "인스턴스화"라고 한다.

//     // struct와 다른 점
//     Player player1 = {100, 200}; // error -> public 없이 이와같이 초기화 불가
//     player0.health = 10; // error -> public 없이 이와같이 초기화 불가
//     // class는 struct와 다르게 기본적으로 멤버변수에 대해 외부에서 접근이 불가능하다.
//     // class내에 public이라는 레이블을 선언해주면 외부에서 접근이 가능하다.
// }

class Player {
private:
    int _health;
    int _power;
    string _name;
public:
    // 멤버변수들이 private이기 때문에, object 생성을 위한 생성자를 만들어준다.
    // 생성자는 해당 클래스가 생성될 때, 가장 처음에 호출되는 함수로, 리턴하는 타입이 없다.
    Player(int health, int power, string name){
        _health = health;
        _power = power;
        _name = name;
    }

    // public한 멤버함수 선언 -> 같은 class의 다른 object player를 공격하는 함수
    // 주체가 parameter에 담긴 대상을 공격하는 함수 -> 레퍼런스로 받아야 원본 데이터를 변경한다.
    void attack(Player& target) {
        // Player class의 멤버함수 내에서는 private으로 선언된 멤버 변수들에 접근할 수 있다.
        // 이는 같은 class의 다른 변수에도 적용되어, 아래처럼 private인 target._name을 출력할 수 있는 것이다.
        cout << "Attack " << _name << "-> " << target._name << endl;
        target.damaged(_power);
    }

    // 공격을 당하는 target 입장에서 실행되는 함수
    // power는 공격자의 power
    void damaged(int power){
        // 공격을 받아서, 공격자의 power만큼 내 health가 차감
        _health -= power;
        // health가 0 이하면 die
        if (_health <= 0) {
            cout << "Died. " << _name << endl;
        }
    }
};

int main() {
    // 멤버변수가 private이므로 생성자를 사용해야 초기화 할 수 있다.
    Player david{200, 100, "David"}; // 소괄호도 가능
    Player daniel(200, 100, "Daniel");

    // 위 상황에서 만약 멤버변수들이 public인 경우, 아래와 같이 누군가가 프로그래밍 과정에서
    // 특정 object의 멤버변수를 변경할 수도 있다. 이렇게 될 경우 프로그램이 의도한대로
    // 동작하지 않게 된다. 그러므로 아예 private으로 선언하여, 프로그램이 오작동할 가능성을 배제하는 것이다.
    // david._health -= 200;

    david.attack(daniel);
    david.attack(daniel); // 두번 때리면 쥬금
}