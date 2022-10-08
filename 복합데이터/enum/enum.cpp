#include <iostream>

using namespace std;

enum Color {
    Red, Green, Blue
};

struct ColorStruct {
    int red;
    int green;
    int blue;
};

int main() {
    // 기존에 숫자로 색깔을 나타낸다고 할  때 사용할 수 있는 방법
    // 0 : Red, 1 : Green, 2 : Blue
    // int colors[3] = {255, 128, 64};

    // 이런 방법도 사용할 수 있다. => 상수로 설정해서 가독성 최적화
    // 그런데, 아래와 같은 방법을 사용하면 읽는 사람으로 하여금 어디에 쓰는지 알기 힘들다.
    // 이런 상황을 극복하기 위해서 사용하는게 열거형(enum)이다.
    // const int red = 0;
    // const int green = 1;
    // const int blue = 2;
    // cout << "Red : " << colors[red] << endl;
    // cout << "Green : " << colors[green] << endl;
    // cout << "Blue : " << colors[blue] << endl;

    // int colors[3] = {255, 128, 64};

    // cout << "Red : " << colors[Red] << endl;
    // cout << "Green : " << colors[Green] << endl;
    // cout << "Blue : " << colors[Blue] << endl;
    // // 아래와 같이 평균값을 구할 수도 있다.
    // int avg0 = (colors[Red] + colors[Green] + colors[Blue]) / 3;
    // // 그러나 이렇게 구해주기보다는 for문을 사용하여 구해주는 것이 더 효과적이다.
    // int total = 0;
    // for (int i = 0; i < 3; ++i) {
    //     total += colors[i];
    // }
    

    // ColorStruct cs = {256, 128, 64};

    // int avg1 = (cs.red + cs.green + cs.blue) / 3;

    // cout << cs.red << endl;
    // cout << cs.green << endl;
    // cout << cs.blue << endl;

    // cout << total / 3 << endl;
    // cout << avg0 << endl;
    // cout << avg1 << endl;

    // enum과 비트와이즈 연산자 - 텍스트 속성 주기 예시

    enum TextAttribute {
        Bold = 1,
        Underline = 2,
        Italic = 4,
        Strikethrough = 8
    };

    int textAttrs = 0;
    // bitwise or 연산자를 통해 text에 Bold, Underline 속성 추가
    textAttrs |= TextAttribute::Bold;
    textAttrs |= TextAttribute::Underline;
    // bitwise and 연산자를 통해 text에 속성이 포함되어있는지 확인하기
    if (textAttrs & Underline) {
        cout << "Underline" << endl;
    }
    if (textAttrs & Italic) {
        cout << "Italic" << endl;
    }

    // Color라는 scoped enum을 만들어 이를 이용해 배열을 이용하려면 아래와 같이 해야한다.

    // enum struct Color {
    //     Red, Green, Blue, SIZE
    // };


    // // enum값을 이용해 배열 만들기
    // int colors[(int)Color::SIZE] = {255, 128, 64};
    
    // // enum값을 이용해 배열 값에 접근
    // cout << colors[(int)Color::Red] << endl;

    enum struct Color{
        Red, Green, Blue
    };

    // 아래와 같이 Color형의 변수를 선언하여, 그 안에 enum값을 넣을 수 있다.
    // Color color = Color::Red;
    // if (color == Color::Red){
    //     cout << (int)color << endl;
    // }
    // if (color == Color::Green){
    //     cout << "Green" << endl;
    // }

    Color color = (Color)1;
    if (color == Color::Green){
		cout << (int)Color::Green << endl; // 1
        cout << (int)color << endl; // 1
        // cout << color << endl; // error
    }
}