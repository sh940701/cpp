#include <iostream>
#include <string>
#include <functional>

using namespace std;

// 간단한 sum 함수 생성
// int sum(int x, int y){
//     return x + y;
// }

// // sum 함수의 프로토타입
// int sum(int x, int y);

// int main() {
//     // 프로토타입의 함수 이름 영역에 "*포인터명"을 작성, parameter 변수명을 제거 후 type만 나열해준다.
//     // 이후 어떤 함수를 대입할 것인지 할당연산자를 사용해 가리켜준다.
//     int (*f)(int, int) = &sum; // &sum도 가능하고, sum 그대로 할당해줘도 된다.

//     // 역참조를 통해 함수를 사용할 수도 있다.
//     cout << (*f)(1, 3) << endl; // 4
//     // 함수 포인터는 역참조 없이 실행도 허용해준다.
//     cout << f(1, 3) << endl; // 4
// }

// int sum(int x, int y){
//     return x + y;
// }

// int main() {
//     int (&f)(int, int) = sum; // 이 녀석은 주소값(&sum)을 넘겨주면 안된다.
//     cout << f(1, 4) << endl; // 5
//     cout << sum << endl;
// }

// 함수 포인터 사용 예시 - Authentication control

// enum struct RequestType{
//     Login, Register, Update, Delete
// };

// bool onLogin(string id, string password) {
//     cout << "onLogin" << endl;
//     cout << id << endl;
//     cout << password << endl;
//     return true;
// }

// bool onRegister(string id, string password) {
//     cout << "onRegister" << endl;
//     cout << id << endl;
//     cout << password << endl;
//     return true;
// }

// bool onUpdate(string id, string password) {
//     cout << "onUpdate" << endl;
//     cout << id << endl;
//     cout << password << endl;
//     return true;
// }

// bool onDelete(string id, string password) {
//     cout << "onDelete" << endl;
//     cout << id << endl;
//     cout << password << endl;
//     return true;
// }

// int main() {
//     // 함수 포인터들로 이루어진 배열 선언
//     bool (*callbacks[])(string, string) {
//         onLogin, onRegister, onUpdate, onDelete
//     };

//     // RequestType type;
//     int num;
//     cin >> num;
//     // type = (RequestType)num;

//     callbacks[num]("david", "1234");

//     // callbacks[(int)RequestType::Login]("david", "1234");
//     // callbacks[(int)RequestType::Register]("david", "1234");
//     // callbacks[(int)RequestType::Update]("david", "1234");
//     // callbacks[(int)RequestType::Delete]("david", "1234");
// }









// 함수 포인터 사용 예시 - game character

// struct Character{
//     int health;
//     // 함수를 포인터로 가리켜 struct의 구성요소로 넣을 수 있다.
//     void (*dieCallback)();
// };

// // 원본 메모리를 바꿔주기 위해 레퍼런스로 받는다.
// void damaged(Character& character) {
//     character.health -= 100;
//     // 죽었을 때 character의 요소 중 dieCallback함수의 포인터 실행
//     if (character.health <= 0){ 
//         cout << "die" << endl;
//         // 몬스터는 죽으면 끝, 플레이어는 dieCallback이 실행되어 gameOver가 출력된다.
//         if (character.dieCallback){
//         character.dieCallback();
//         }
//     }
// }

// void gameOver() {
//     cout << "gameOver" << endl;
// }

// int main() {
//     // 몬스터와 플레이어로 나눈다.
//     // 몬스터는 gameOver 콜백함수가 존재하면 안된다.
//     Character monster{200, nullptr};
//     // 플레이어는 gameOver 함수의 포인터를 struct의 구성요소로 가지게 된다.
//     // gameOver함수는 struct내에서 포인터로 받아져 dieCallback이라는 포인터명을 가지게 된다.
//     Character player{200, gameOver};

//     damaged(monster);
//     damaged(monster); // die

//     damaged(player);
//     damaged(player); // die gameOver
// }

// void gameOver() {
//     cout << "gameOver" << endl;
// }

// int main() {
    // 기존
    // void (*f)() = gameOver;

    // auto
    // auto f = gameOver; // auto f = &gameOver; 도 가능
    
    // 레퍼런스도 가능
    // auto& f = gameOver; // auto& f = &gameOver; 는 불가
    // f(); // gameOver

    // auto i = 1;
    // cout << typeid(i).name() << endl; // int
    // 결국 auto i = 1;에서 auto 는 int 와 같은 선언인 것이다.
    // 이를 컴파일타임에 추론된다고 표현한다. -> data의 타입을 추론해서 타입으로 입력해주는느낌?
// }

// int main() {
    // typedef
    // type에 대한 변수를 선언해준다. 선언 이후에는 해당 type 대신 typedef 변수를 사용할 수 있다.

    // typedef float real32;
    // typedef double real64;

    // real32 r32 = 3.2;
    // real64 r64 = 6.4;

    // cout << r32 << endl; // 3.2
    // cout << typeid(r32).name() << endl; // float
    // cout << r64 << endl; // 6.4
    // cout << typeid(r64).name() << endl; // double
// }

// void gameOver(int a) {
//     cout << "gameOver" << endl;
// }

// int main() {
//     typedef void (*FuncType)(int);
//     FuncType f = gameOver;
//     f(1);
// }



void gameOver(int a) {
    cout << "gameOver" << endl;
}

int main() {
    // using real32 = float;
    // using real64 = double;

    // real32 f;
    // real64 d;
    // cout << typeid(f).name() << endl; // float
    // cout << typeid(d).name() << endl; // double

    // typedef void (FuncType)(int);
    using FuncType = void(int);
    FuncType *f = gameOver;
    f(1); // gameOver
}