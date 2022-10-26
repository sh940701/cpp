#include <iostream>
#include <limits>

using namespace std;

int main() {
    // int a;
    // cin >> a;
    // cout << a << endl;

    // scanf("%d", &a);

    // 버퍼 처리해주기
    // char ch;
    // cin >> ch;
    // cout << ch << endl;

    // cin.ignore(); // cin.ignore() 함수를 사용하여 버퍼에 남아있는 문자열 처리 완료
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // 원래 ignore의 default값은 1로, 입력받은 문자열 뒤로 하나만 무시한다는 의미이다.
    // 이런 문제를 해결하기 위해 ignore값에 max int값을 넣어주고, 또한 개행문자가 나올때까지 무시해준다는 조건을 달아주면 해결된다.

    // cin >> ch;
    // cout << ch << endl;

    // 위와같은 상황에서 input으로 ab를 입력하면, a가 출력되고, b가 버퍼에 남아서 a, b가 연속적으로 출력이 된다.

    // int로 지정했는데 문자열을 입력하면, 0이 출력되고, 두 번째 것도 자동으로 0으로 출력되는 문제
    // int num;
    // cin >> num;
    // cout << num << endl;

    // if (cin.fail()) // fail 여부를 반환하는 함수 -> 잘못된 입력값을 받으면 fail의 의미로 1을 반환한다.(fail에 대해서 true라는 뜻)
    //     cin.clear(); // cin.fail이 true(1을 반환)이면 cin 내부 값을 초기화해줌으로서 해결한다.
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // cin >> num;
    // cout << num << endl;

    // bool b;
    
    // cin.setf(ios_base::boolalpha);

    // cin >> b;
    // cout << b << endl;

    // int num;
    // cin.setf(ios_base::hex, ios_base::basefield);
    // cin >> num;
    // cout << num << endl;

    // int num;
    // cin >> hex >> num;
    // cout << num;

    // num1, num2 변수 저장
    // int num1, num2;

    // // stdout 경로를 num1.txt로 설정
    // freopen("num1.txt", "w", stdout);
    // // input을 받아 num1 변수에 저장
    // cin >> num1;
    // // num1 변수에 담긴 숫자를 num1.txt로 out
    // cout << num1;

    // // stdin 경로를 num1.txt로 설정
    // freopen("num1.txt", "r", stdin);
    // // stdout 경로를 num2.txt로 설정
    // freopen("num2.txt", "w", stdout);
    // // num1.txt를 받아서 num2에 저장
    // cin >> num2;
    // // num2 변수에 담긴 숫자를 num2.txt로 out
    // cout << num2;

    int num;
    freopen("num1.txt", "r", stdin);
    cin >> num;
    cout << num << endl;
    
}