#include <iostream>
#include <cstring>

using namespace std;

// class Player{
// private:
//     int _num;

// public:
//     Player(int num) : _num(num){
//         cout << "Constructor " << _num << endl;
//     }
//     // destructor 생성
//     // 객체가 무언가를 사용했을 때 정리하기 위해 사용
//     // 명시적으로 만들지 않으면, 암시적으로 컴파일러가 만들어준다.
//     ~Player() {
//         cout << "Destructor: " << _num << endl;
//     }

//     // 만약 아래와 같이 파괴자를 만들지못하도록 명시해놓으면, 생성자 호출이 불가하다.
//     // ~Player() = delete; -> 이렇게 해놓으면
//     // Player player(3); -> error
// };

// int main () {
//     Player player(3);
//     Player* player = new Player(1);
// }

// object의 라이프사이클을 알아보자
// class Player{
// private:
//     int _num;

// public:
//     Player(int num) : _num(num){
//         cout << "Constructor " << _num << endl;
//     }
//     ~Player() {
//         cout << "Destructor: " << _num << endl;
//     }
// };

// // 전역적인 player 선언
// Player player0(0);
// // 전역 + 동적인 player 선언
// Player* player1 = new Player(1);

// void func() {
//     // 정적으로 player2 생성
//     static Player player2(2);
// }

// int main() {
//     // main scope 내 player3 생성
//     Player player3(3);
//     // main scope 내 동적인 player4 생성
//     Player* player4 = new Player(4);
//     {
//         // scope를 생성하여 player5 생성
//         Player player5(5);
//         // scope를 생성하여 동적인 player6 생성
//         Player* player6 = new Player(6);
//     }
//     // 동적으로 선언된 player4를 지움
//     delete player4;
//     // 아래에서 func()함수를 두 번 호출해줬지만, 정적 영역에 있는 녀석은
//     // 프로그램 실행중 한번만 할당을 하기 때문에 생성자는 한번만 실행됨
//     func();
//     func();
// }

/* 아래 순서대로 결과값 출력

Constructor 0 전역객체 player0 생성

Constructor 1 전역 동적객체 player1 생성

Constructor 3 main 내 객체 player3 생성

Constructor 4 main 내 동적객체 player4 생성

Constructor 5 scope 내 객체 player5 생성

Constructor 6 scope 내 동적객체 player6 생성

Destructor: 5 scope 빠져나오며 player5 해제

Destructor: 4 main 내 동적객체 player4 해제(delete로 수동해제)

Constructor 2 정적객체 player2 생성(정적이기 때문에 한번만 힙 영역 할당)

Destructor: 3 main함수 종료되며 player3 해제

Destructor: 2 main함수 종료되며 player2 해제

Destructor: 0 프로그램 종료되며 player0 해제

동적으로 생성하여 delete해주지 않은 player1, 6은 실질적으로 Destructor함수가 호출되지 않음
*/

// 전역변수와 정적(static)변수는 프로그램이 종료될 때 해제된다!
// 그렇다면 1번은 전역변수인데 왜 해제가 되지 않았을까?
// player1이라는 변수는 해제되었지만, 1번이 가리키는 메모리 값은 해제되지 않은 것이다.
// 1번이 가리키는 메모리 값(실질적인 Player객체)는 해제되지 않아, Destructor가 호출되지 않았다.


// string이라는 class -> 실제로 c 스타일의 문자열을 받아서 class로 wrapping하는 녀석
class String {
private:
    char* _str;

public:
    // 생성자 -> char 배열을 받아온다(함수 인자값으로 받을 때는 pointer로 받아짐)
    String(const char* str){
        int length = strlen(str);
        // char의 개수보다 1을 더한 길이의 배열의 동적 주소값을 멤버변수인 포인터 _str에 넣어준다.
        // 동적으로 할당해주었기 때문에 생성자를 실행하고, 해제해주지 않으면 메모리 누수가 생기게 된다.
        _str = new char[length + 1]; // "\0"
        // 멤버변수 _str에(배열) str의 내용을 복사해준다.
        strcpy(_str, str);
    }
    
    // 아래와같이 파괴자가 호출될 때 동적 영역에 있는 녀석을 지워주도록 명시해줘야 메모리 누수가 발생하지 않는다.
    ~String() {
        delete[] _str;
    }

    void print() {
        cout << _str << endl;
    }
};

int main() {
    // 아래와 같이 선언되어있을 경우, destructor를 따로 선언해주지 않고 객체를 사용하게 되면
    // 스코프를 벗어날 때마다 object는 해제되지만 동적으로 할당된 메모리는 사라지지 않는다.
    // 따라서 동적으로 할당해준 메모리를 해제해주는 destructor를 명시적으로 만들어주어야
    // 메모리 누수가 발생하지 않는다.
    while (true){
        String str("abc");
    }
}