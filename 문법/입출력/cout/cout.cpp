#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // cout << 1 << endl;
    // cout << "1" << endl;

    // cout << "a" << endl;
    // cout << (char)97 << endl;

    // operator<<(cout, 'a');

    // cout.put('a');
    // cout.put('\n');
    // cout.write("Hello world", 5);

    // float num = 0.1234567f;
    // cout << num << endl;
    // 0.123457

    // cout.precision(10);
    // cout << num << endl;
    // 0.1234567016

    // cout.setf(ios_base:: showpos);
    // cout << 1 << endl;
    // cout.unsetf(ios_base::showpos);
    // cout << 2 << endl;

    // cout << true << endl;
    // cout << false << endl;

    // cout.setf(ios_base:: boolalpha);
    // cout << true << endl;
    // cout << false << endl;

    // cout.setf(ios_base:: left, ios_base::adjustfield);
    // cout.width(10);
    // cout << -10 << 20 << endl;
    
    // cout.setf(ios_base:: right, ios_base::adjustfield);
    // cout.width(10);
    // cout << -10 << 20 << endl;

    // cout.setf(ios_base:: internal, ios_base::adjustfield);
    // cout.width(10);
    // cout << -10 << 20 << endl;

    // cout.setf(ios_base::hex, ios_base::basefield);
    // cout << 16 << endl;

    // cout << std::hex << 16 << endl;

    // cout << hex << 16 << endl;

    // hex(cout);
    // cout << 16;

    // freopen("output.txt", "w", stdout);
    // cout << setw(10) << setfill('#') << setprecision(3) << showpos << 1.1f << endl;

    // int 타입의 num과 num2 라는 변수 선언
    int num, num2;

    // scanf로 숫자를 받아와 num이라는 변수에 넣어줌
    scanf("%d", &num);

    // stdout 종착지(출력할 곳)를 num.txt로 변경해줌
    freopen("num.txt", "w", stdout);

    // scanf로 받아온 num을 cout을 이용하여 출력(종착지를 num.txt로 설정해두었기 때문에 num.txt에 들어가게 됨)
    cout << num << endl;

    // stdin의 종착지(읽어올 곳)를 num.txt로 바꿔줌
    freopen("num.txt", "r", stdin);
    
    // scanf로 받아온 num.txt(위에서 stdin 경로를 설정해줘서, userinput이 아닌 num.txt의 내용을 받아오게 됨)내용을 num2변수에 넣어줌
    scanf("%d", &num2);

    // freopen("CONOUT$", "w", stdout);
    
    // 출력해보자 ㅎㅎ
    cout <<  num2 << endl;
}