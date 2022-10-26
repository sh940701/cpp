#include <iostream>

using namespace std;

int main() {
    // for (int i = 0; i < 10; ++i) {
    //     if (i % 3 == 0) continue;
    //     cout << i << endl;
    // }

    // int i = 0;
    // while (i < 10)
    // {
    //     if (i % 3 == 0)
    //     {    ++i;
    //         continue;}
    //     cout << i << endl;
    //     ++i;
    // }

    // factorial - for
    // int num;
    // cin >> num;

    // int total = 1;
    // for (; num; --num) {
    //     total *= num;
    // }
    // cout << total << endl;

    // factorial - while

    // int num;
    // cin >> num;

    // int total = 1;
    // while(num){
    //     total *= num--;
    // }
    // cout << total << endl;

    // a-z 출력
    // char ch = 'a';
    // while(ch <= 'z'){
    //     cout << ch << endl;
    //     ++ch;
    // }

    // 피보나치 수열
    int num;
    cin >> num;

    if (0 == num) {
        cout << 0 << endl;
    }
    else {
        int prevValue = 0;
        int currValue = 1;

        while (num-- - 1) // 후위연산자이므로, num - 1이 들어간 조건으로 계산이 되고, 연산이 시작할 때의 num은 num - 2인 상태이다.
        // while (--num) 이렇게 표현한 것과 같다.
        {
            int nextValue = prevValue + currValue;
            prevValue = currValue;
            currValue = nextValue;
        }
        cout << currValue << endl;
    }

}