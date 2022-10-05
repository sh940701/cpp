#include <iostream>
#include <string>

using namespace std;

int main() {
    // string type은 std안에 포함되어있는 객체이다.
    // string str = "abcd";
    // cout << str << endl;
    // cout << str[0] << endl;
    // cout << str[1] << endl;
    // cout << str[2] << endl;
    // cout << str[3] << endl;
    // cout << sizeof(str) << endl;

    // string 비교
    // string str0("abc");
    // string str1("abc");
    // cout << (str0 == str1) << endl;

    // string concat
    // string str0("abc");
    // string str1("abc");
    
    // int result = strcmp(str0.c_str(), str1.c_str());
    // cout << result << endl;

    // str0 = str0 + str1;
    // cout << str0 << endl;
    
    // size 구하기
    // string str0("abc");
    // string str1("abc");

    // cout << str0.size() << endl;
    // cout << str1.length() << endl;

    // 형변환하기 to_string
    // string str0 = to_string(123);
    // cout << str0 << endl;

    // string str1 = to_string(123.3);
    // cout << str1 << endl;

    // string str2 = to_string(true);
    // cout << str2 << endl;

    // 형변환하기 문자열 -> 숫자
    // int num0 = stoi("1");
    // cout << num0 << endl;

    // float num1 = stof("1.1");
    // cout << num1 << endl;

    // 
    string str;
    getline(cin, str);

    cout << str << endl;
}