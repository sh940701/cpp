#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // char str0[] = "abcd";
    // char* str1 = str0; // 배열이기 때문에 pointer에 그대로 담아줄 수 있다.

    // str1[0] = 'b';

    // cout << str0 << endl;
    // cout << str1 << endl;

    // char* str2 = "hello";

    // const char* str2 = "hello"; // error

    // cout << str2 << endl;

    // 문자열 상수의 type을 알아보자
    // cout << typeid(str0).name() << endl;
    // cout << typeid("hello").name() << endl;

    cout << "hihi"[0] << endl;

    char str0[100] = "abcd";
    char* str1 = str0;
    const char* str2 = "hello";
    

    cout << strlen(str0) << endl; // 4
    cout << strlen(str1) << endl; // 4
    cout << strlen(str2) << endl; // 5
    
    strcpy(str0, str2); // str2의 요소를 str0에 복사
    cout << str0 << endl; // hello -> str0도 잘 출력됨
    cout << str1 << endl; // hello -> str0의 포인터인 str1도 잘 출력됨
    cout << strcmp(str0, str2) << endl; // 두 개의 문자열이 같기 때문에 0이 출력됨
}