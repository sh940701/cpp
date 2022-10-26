#include <iostream>

using namespace std;

int main(){
    // char str[] = "abc";
    // cout << str << endl;
    // cout << str[0] << endl;
    // cout << str[1] << endl;
    // cout << str[2] << endl;
    // cout << sizeof(str) << endl;

    // cout << int(str[0]) << endl;
    // cout << int(str[1]) << endl;
    // cout << int(str[2]) << endl;
    // cout << int(str[3]) << endl;

    // str[3] = 'd';
    // cout << str << endl;

    // char str[100] = "hello";
    // cout << str << endl;
    // cout << sizeof(str) << endl;
    // cout << strlen(str) << endl;

    // char str0[] = "hello";
    // char str1[] = "hello";

    // cout << (str0 == str1) << endl; // 0

    // int result = strcmp(str0, str1);
    // cout << result << endl;

    // char str0[100];
    // char str1[] = "hello";

    // str0 = str1;
    // strcpy(str0, str1);
    // cout << str0 << endl;

    // char str0[] = "hello";
    // char str1[] = "world";
    // strcat(str0, str1);
    // cout << str0 << endl;

    // 문자열 -> int
    // char str0[] = "1";
    // int num0 = atoi(str0);
    // cout << num0 << endl;

    // char str1[] = "1.1";
    // float num1 = atof(str1);
    // cout << num1 << endl;

    // 숫자 -> 문자열
    // int num = 100;
    // char str0[4];

    // sprintf(str0, "%d", num);
    // cout << str0 << endl;
    
    // 입력 시 주의할 점
    // char str[6];
    // cin >> str;
    // cout << str << endl;

    char str[6];
    cin.getline(str, 6);
    cout << sizeof(str) << endl;
    cout << str << endl;
}