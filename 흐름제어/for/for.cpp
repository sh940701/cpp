#include <iostream>

using namespace std;

int main() {
    // int i;
    // for (i = 0; i < 10; ++i){
    //     cout << i << endl;
    // }

    // int i;
    // for (i = 10; i; --i){
    //     cout << i << endl;
    // }

    // for (int i = 10; i; --i){
    //     cout << i << endl;
    // }

    // for (int i = 0, j = 0; i < 10 && j < 10; ++i, j += 2){
    //     cout << i << " " << j << endl;
    // }

    // for (int i = 0; i < 10; ++i){
    //     cout << i << endl;
    //     if (i == 5)
    //         break;
    // }

    // for (int i = 0; i < 10; ++i){
    //     if (i % 3 == 0)
    //         continue;
    //     cout << i << endl;
    // }

    // switch와 반복문
    // for (; ;)
    // {
    //     cout << "Food" << endl;
    //     cout << "1) kimchi" << endl;
    //     cout << "2) bbq" << endl;
    //     cout << "3) chicken" << endl;
    //     int num;
    //     cin >> num;
    //     switch(num){
    //         case 1:
    //             cout << "kimchi" << endl;
    //             break;
    //         case 2:
    //             cout << "bbq" << endl;
    //             break;
    //         case 3:
    //             cout << "chicken" << endl;
    //             break;
    //         default:
    //             continue;
    //     }
    //     break;
    // }

    // factorial 구하기
    // int num;
    // cin >> num;
    // unsigned int total = 1;
    // // 아래 for문 첫 번째에 num; 을 해줘도 되고 ;만 입력해줘도 된다.
    // // num만 쓰면, 0이 num이면 종료되기때문에 아래와 같이 구성이 가능하다.
    // for (; num; num--){
    //     total *= num;
    // }
    // cout << total << endl;

    // a부터 z까지 출력해보기
    // for (char ch = 'a'; ch <= 'z'; ch++){
    //     cout << ch << endl;
    //     cout << int(ch) << endl;
    // }

    // 피보나치 수열 출력해보기
    int num;
    cin >> num;

    if (num == 0){
        cout << 0 << endl;
    } else if (num == 1) {
        cout << 1 << endl;
    } else{
        int prevValue = 0;
        int currValue = 1;
        for (int i = 0; i < num - 1; ++i) {
            int nextValue = prevValue + currValue;
            prevValue = currValue;
            currValue = nextValue;
            }
        cout << currValue << endl;
    }
}