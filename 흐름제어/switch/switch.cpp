#include <iostream>

using namespace std;

int main() {
    // cout << "What's your favorite food?" << endl;
    // cout << "1) Kimchi" << endl;
    // cout << "2) Korean BBQ" << endl;
    // cout << "3) Chicken" << endl;
    // cout << '>';

    // char ch;
    // cin >> ch;

    // // switch문 안에 들어가는 조건은(아래에서는 ch) 항상 "정수형"으로 평가가 되어야 한다.
    // // 문자'열' "a"같은 경우에는 되지 않는다.
    // switch(ch)
    // {
    //     // if ch == 'a' 와 같은 의미
    //     case 'a':
    //     // 이와같은 경우에는, a와 A 둘 다 같은 output을 내길 원하기 때문에 사이에서 break를 의도적으로 뺀 것이다.
    //     // break문이 없이 그대로 흐르도록 case 두 개를 쓸 때, 경고에러가 발생할 수 있다.
    //     // 이를 해결하기 위해서는 아래와같은 attribute를 추가해주면 된다.
    //     // 근데 왜 에러가 나지.. 무튼 그렇다.
    //     cout << "Couverted A" << endl;
    //     // [[fallthrough]];
    //     case 'A':
    //         cout << "You selected Kimchi" << endl;
    //         // 숫자로 1, 2, 3을 나눴을 경우, break를 넣어주지 않으면, 1을 입력했을 때도
    //         // 아래의 case2까지 내려가서 두 개가 출력된다.
    //         break;
    //     case 'b':
    //     case 'B':
    //         cout << "You selected Korean BBQ" << endl;
    //         break;
    //     case 'c':
    //     case 'C':
    //         cout << "You selected Chicken" << endl;
    //         break;
    //     // default는 if문의 else와 유사하다. 마지막에 있기 때문에 break를 넣어주지 않아도 된다.
    //     default:
    //         cout << "Invalid input" << endl;
    // }

    // switch문도 if문처럼 조건문 내부에 변수 선언이 가능하다.
    // int num0, num1;
    // switch (int count = scanf("%d %d", &num0, &num1))
    // num0, num1도 scope를 switch문 내로 한정짓고싶으면, 아래와 같이 선언도 가능하다. -> C++ 17 이상 version
    switch (int num0, num1; int count = scanf("%d %d", &num0, &num1))
    {
    case 1:
        cout << num0 << endl;
        break;
    case 2:
        cout << num0 << endl;
        cout << num1 << endl;
    default:
        break;
    }
}