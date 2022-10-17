#include <iostream>

using namespace std;

// int sum (int x, int y) {
//     return x + y;
// }

// int abs(int x) {
//     // return x >= 0 ? x : -x; // 삼항연산자

//     // if문
//     if (x >= 0) {
//         return x;
//     } else {
//         return -x;
//     }
// }

// void print(int x, int y) {
//     cout << x << endl;
//     (y > 0) && (cout << y << endl);
//     return;
// }

// void noParameter() {
//     cout << "Hello World!" << endl;
// }

// int main(int argc, char* argv[]) {
//     // for (int i = 0; i < argc; ++i) {

//     // }
//     // cout << argc << endl; // 1
//     // cout << argv[0] << endl; // /Users/sunghyun/cpp/함수/function/function

//     // cout << sum(5, 10) << endl; // 15

//     // cout << abs(10) << endl;
//     // cout << abs(-10) << endl;

//     // print (10, 20);
//     noParameter();
// }

int abs(int);
int sum(int, int);
int abssum(int, int);

int main() {
    cout << abssum(1, -3) << endl; // 4
    cout << abssum(20, -70) << endl; // 90
    cout << abssum(-30, -10) << endl; // 40
}

int abssum(int x, int y) {
    return sum(abs(x), abs(y));
}

int sum (int x, int y) {
    return x + y;
}

int abs(int x) {
    return (x >= 0) ? x : -x;
}
