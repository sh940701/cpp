#include <iostream>

using namespace std;

int main() {
    // int i = 0;
    // while (i < 10){
    //     cout << i << endl;
    //     ++i;
    // }

    // i = 0;
    // do
    // {
    //     cout << i << endl;
    //     i++;
    // } while (i < 10);
    
    // while / do-while 차이
    // int i = 0;
    // while (i < 0){
    //     cout << i << endl;
    //     ++i;
    // }

    // i = 0;
    // do
    // {
    //     cout << i << endl;
    //     i++;
    // } while (i < 0);

    // 위와 같이 정의되었을 때 while문은 i < 0 의 여부 먼저 확인하기 때문에 내부가 실행되지 않는다.
    // do-while문은 먼저 cout을 실행하고 +1을 한 후에, 조건문을 검사하기 때문에 내부가 1회 실행된다.

    // do-while 예외처리
    // int num;
    // cin >> num;
    // do
    // {
    //     if (num % 3 == 0)
    //         break;
    //     if (num % 5 == 0)
    //         break;
        
    //     cout << "wow" << endl;
    // } while (false);
    
    // cout << "abcd" << endl;

    // factorial
    // int num;
    // cin >> num;

    // int total = 1;
    // do
    // {
    //     total *= num;
    // } while (--num);
    
    // cout << total << endl;

    // a-z 출력하기
    // char ch = 'a';
    // do
    // {
    //     cout << ch << endl;

    // }
    //     while (ch++ < 'z');
    // while (++ch <= 'z');
    
    // 피보나치 수열
    int num;
    cin >> num;

    if (num <= 1) cout << num << endl;
    else 
    {
        int prevValue = 0;
        int currValue = 1;
        do
        {
            int nextValue = prevValue + currValue;
            prevValue = currValue;
            currValue = nextValue;
        } while (--num -1);
        cout << currValue << endl;
    }
}