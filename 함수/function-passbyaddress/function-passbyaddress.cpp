#include <iostream>

using namespace std;

// // 포인터로 받기
// void swap(int* px, int* py){
//     // 역참조로 내부 연산 실행
//     int temp = *px;
//     *px = *py;
//     *py = temp;
// }

// int main() {
//     // 포인터 복습
//     // 변수 x
//     // int x = 10;
//     // // 포인터 선언 및 초기화
//     // int* px = &x;

//     // cout << x << endl; // 10
//     // cout << *px << endl; // 10

//     // x = 20;
//     // cout << x << endl; // 20
//     // cout << *px << endl; // 20

//     // *px = 30;
//     // cout << x << endl; // 30
//     // cout << *px << endl; // 30

//     int x = 10, y = 20;

//     cout << x << endl; // 10
//     cout << y << endl; // 20

//     // 인자를 주소값으로 넘겨줌
//     swap(&x, &y);

//     // swap이 잘 이루어짐
//     cout << x << endl; // 20
//     cout << y << endl; // 10


// }

// struct Weapon {
//     int price;
//     int power;
// };

// void upgrade(Weapon* pWeapon) {
//     pWeapon->price += 10;
//     pWeapon->power += 10;
// }

// // 그냥 주어진 값을 읽는 print라는 함수 생성
// // pointer가 가리키는 주소 내의 data를 바꿀 수 없도록 하는 const를 선언해주면
// // 값으로 넘겨줬을 때의 장점인 "함수 실행 이후 변수의 값이 바뀌지 않았다는 보장"을 가질 수 있다.
// void print(const Weapon* weapon) {
//     cout << weapon->price << endl;
//     cout << weapon->power << endl;
// }

// int main() {
//     Weapon weapon{10, 20};
//     upgrade(&weapon);
//     // 값을 넘겨주는 함수의 단점에서, 복사 과정으로 인한 overhead가 생길 수 있다고 했다.
//     // 이를 방지하기 위해서는 아래와 같이 주소값으로 넘겨주고, 이를 읽어주면 된다.
//     print(&weapon); // 20 30

//     // cout << weapon.price << endl;
//     // cout << weapon.power << endl;
// }

// void func(int nums[4]){
//     cout << nums << endl; // 0x16da3ef00
    
//     cout << typeid(nums).name() << endl; // Pi -> int type의 pointer
//     // parameter로 받은 nums의 type name을 출력해보면 파라미터로 받기 전과 다른 값이 나온다.
//     // 함수의 파라미터로 배열을 넘겨주면 타입이 변경되기 때문이다!

//     // for (int num : nums){
//     //     cout << num << endl;
//     // } // range based for문이 컴파일되지 않음

//     for (int i = 0; i < 4; ++i) {
//         cout << nums[i] << endl;
//     } // 일반 for문은 잘 작동이 됨
// }

// int main() {
//     int nums[4] = {1, 2, 3, 4};
//     func(nums);
//     cout << typeid(nums).name() << endl; // A4_i -> int type 요소 4 개를 가진 배열
// }

// int* func() {
//     int nums[4] = {1, 2, 3, 4};
//     return nums;
// }

// int main() {
//     func();
// }

// int main(int argc, char* argv[]) {
//     cout << typeid(argv).name() << endl; // PPc
//     // main함수가 parameter로 받는 argv의 타입을 출력해보면 char type의 더블 포인터가 나온다.
//     // 더블 포인터는 "포인터를 가리키는 포인터"이다.

//     // 이전에 main함수 argv의 원소를 출력할 때 아래와 같이 진행해주었다. 결국 argv를 배열 취급을 하는 것이다.
//     for (int i = 0; i < argc; ++i){
//         cout << argv[i] << endl; // Users/sunghyun/cpp/함수/function-passbyaddress/function-passbyaddress
//     }

//     cout << typeid(argv[0]).name() << endl; // Pc -> char type의 pointer

//     // 정리해보면, 현재 argv는 더블 포인터이기 때문에 char** 형태이다.
//     // 그런데 배열은 포인터 형태로 받기 때문에 포인터 하나를 배열 표시로 생각하면
//     // 그 내부는 [char* a, char* b, char* c]등의 형식으로 이루어져 있을 것이다.
//     // 그런데 char*는 문자열로 취급을 한다.
//     // 그러므로 위에서 argv 내부의 값을 출력했을 때 정상적으로 문자열이 출력된 것이다.
// }

// int main(int argc, char** argv) {
//     for (int i = 0; i < argc; ++i){
//         cout << argv[i] << endl;
//     }
// }

아래 상황은 문자열로 이루어진 배열을 넘겨주는 상황이다. 다만 위와 다른 점은,
위에서는 요소가 배열(주소값)로 이루어진 배열을 보냈지만 아래에서는 요소가 주소값이 아닌 문자열 배열 그 자체로 이루어진 배열인 것이다.
따라서 아래에서는 더블 포인터를 사용할 수 없다. 배열의 내부 요소가 주소값이 아니라 문자열 그 자체이기 때문이다.
배열을 정의할 때, 그 type은 배열을 구성하는 최소단위의 요소의 type이다. -> 아래에서는 char
함수에서 배열을 파라미터로 받아올 때, 최소 요소의 type + 받아서 복사할 변수명 + 변수가 어떻게 구성되어있는지를 알려줘야한다.
그 예로 위 main 함수에서는 포인터를 요소로 가지고 있는 배열을 받을 때 char* argv[]로 선언해주었다.
첫째 배열의 하위 요소도 배열이기 때문에 메모리에는 { {"a", "b", "c", "d"}, {"e", "f", "g", "h"} }로 저장되어있을 것이다.
그러므로 아래에서 요소를 받을 때는 저장된 형식 그대로 char argv[][5]라고 선언해주면 정상적으로 작동한다.
윗줄의 변수 argv는 윗윗줄에 나열되어 있는 배열 데이터가 저장되어 있는 메모리의 주소값을 담고있는 변수이다.

void func(int argc, char argv[][5]) {

아래 선언 방법에 대해 알아보자. 사실은 위와 같다고 볼 수 있다. -> 열심히 분석했는데
알고보니 아래 주석처리된 설명은 틀린 것 같다. 그치만 일단 남겨두자 혹시모르니
//메모리에 data가 { {"a", "b", "c", "d"}, {"e", "f", "g", "h"} } 형식으로 저장되어있다고 할 때,
//위에서 선언한 char argv[][5]의 경우, [5]앞의 빈 배열[]표시는 data 내에서 가장 큰 배열을 뜻한다.
//가장 큰 배열 안에 char type 요소 5개로 이루어진 배열들이 있다는 것이다.
//아래의 상황에서 argv는 전체 data의 주소값이다. 그리고 이를 역참조하면 주소값에 담긴 data가 나오는데
//{ {"a", "b", "c", "d"}, {"e", "f", "g", "h"} } 이 데이터에 대한 주소값을 역참조했으니 이는 data 내에서 가장 큰 배열을 의미한다.
//결국 아래 표기법도 가장 큰 배열 안에 char type 요소 5개로 이루어진 배열들이 있다는 것을 나타내게 되는 것이다.

아래 선언 방법은 그냥 문법적 표기라고 한다. 포인터인데, char요소 5개로 이루어진 배열들을 요소로 가지고 있는 pointer 표현법
void func(int argc, char (*argv)[5]) {
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }
    cout << typeid(argv).name() << endl; // PA5_c -> 요소가 char인 길이 5의 배열을 가지고있는 포인터
    
}

int main() {
    char strs[][5] = {"abcd", "efgh"};
    cout << strs << endl; // 0x16ef6af08
    cout << typeid(strs).name() << endl; // A2_A5_c -> 요소가 char인 길이 5의 배열을 두 개 요소로 가지고 있는 배열
    cout << strs[1] << endl; // efgh
    func(2, strs);
}