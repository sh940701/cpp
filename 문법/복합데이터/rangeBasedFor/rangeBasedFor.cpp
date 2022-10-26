#include <iostream>
#include <array>

using namespace std;

int main() {
    // int arr[5] = {1, 2, 3, 4, 5};
    // for (int i = 0; i < 5; ++i) {
    //     cout << arr[i] << endl;
    // }
    // for (변수 선언 : 배열)
    // for (int num : arr) {
    //     cout << num << endl;
    // }
    
    // array <int, 5> arr = {1, 2, 3, 4, 5};
    // for (int num : arr){
    //     cout << num << endl;
    // }

    // struct Person {
    //     float weight;
    //     float height;
    // };

    // 원래 struct type의 변수를 초기화하려면 Person person = {1, 2}와 같이 입력한다.
    // struct로 이루어진 배열의 원소를 설정해주려면 아래와같이 기입한다
    // 배열 내에 Person person을 입력하면 "type name is not allowed"에러가 발생하고
    // 변수명 person 만 입력하면 "identifier "person" is undefined"에러가 발생한다.
    // Person persons[] = {
    //     Person{70, 181},
    //     Person{56.2, 167}
    // };

    // 기존 for문 방식
    // for (int i = 0; i < 2; ++i) {
    //     cout << persons[i].weight << " " << persons[i].height << endl;
    // }

    // range based for문 방식
    // for (Person person : persons) {
    //     cout << person.weight << " " << person.height << endl;
    // }

    // for문으로 값 변경
    // for (int i = 0; i < 2; i ++) {
    //     persons[i].weight = 0;
    // }
    
    // for (Person person : persons) {
    //     cout << person.weight << " " << person.height << endl;
    // }

    // for (int i = 0; i < 2; ++i) {
    //     cout << &persons[i] << endl;
    // }
    // cout << endl;
    // for (Person& person : persons) {
    //     cout << &person << endl;
    // }

    int nums[3] = {1, 2, 3};
    for (int i = 0; i < 3; ++i) {
        nums[i] = 0;
    }

    for (int num : nums){
        cout << num << endl;
    }
}