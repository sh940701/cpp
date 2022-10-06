#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // 구조체 -> Person 이라는 자료형을 만든 것이다.
    // struct Person {
    //     float height;
    //     float weight;
    //     char name[10];
    //     short grade;
    // };

    // Person person;
    // person.height = 174.2;
    // person.weight = 67.8;
    // person.name = "sunghyun"; 좌측과같이 선언이 불가하다. C스타일의 string은 주소값이기 때문이다.
    // C스타일로 name을 초기화해주려면 아래와 같이 strcpy 함수를 사용해야 한다.
    // strcpy(person.name, "sunghyun");
    // person.grade = 1;

    // Person person = {174.2, 67.8, "sunghyun", 1};
    // Person person = {.height = 174.2, .weight = 67.8, .name = "sunghyun", .grade = 1};

    // struct EyeSight {
    //     float left;
    //     float right;
    // };

    // struct Person {
    //     float height;
    //     float weight;
    //     char name[10];
    //     short grade;
    //     EyeSight eyeSight;
    // };

    // Person person = {174.2, 67.8, "sunghyun", 1, {1.0, 1.1}};
    

    // cout << person.height << endl;
    // cout << person.weight << endl;
    // cout << person.name << endl;
    // cout << person.grade << endl;
    // cout << person.eyeSight.left << endl;
    // cout << person.eyeSight.right << endl;

    // 구조체를 요소로 갖는 배열 만들기
    // struct EyeSight {
    //     float left;
    //     float right;
    // };

    // struct Person {
    //     float height;
    //     float weight;
    //     char name[10];
    //     short grade;
    //     EyeSight eyeSight;
    // };

    // Person persons[5];
    // persons[0].grade = 1;

    // cout << persons[0].grade << endl; // 1

    // Person& person = persons[1];
    // person.grade = 5;

    // cout << person.grade << endl; // 5
    // cout << persons[1].grade << endl; // 쓰레기값이 나옴

    // cout << &person << endl;
    // cout << &persons[1] << endl;

    // 구조체의 크기 알아보기
    // struct Person0 {
    //     float height; // 4
    //     float weight; // 4
    //     char name[10]; // 10
    //     short grade; // 2
    // };

    // cout << sizeof(Person0) << endl; // 20

    // 요소들의 위치를 바꿔보자
    // struct Person1 {
    //     float height; // 4
    //     short grade; // 2
    //     float weight; // 4
    //     char name[10]; // 10
    //     // short hihi;
    // };

    // cout << sizeof(Person1) << endl; // 24바이트가 출력된다. 왜 그럴까?

    struct alignas(16) Person {
        float height; // 4
        float weight; // 4
        char name[10]; // 10
        short grade; // 2
    };

    cout << sizeof(Person) << endl;
}