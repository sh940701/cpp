#include <iostream>

using namespace std;

int main() {
    // if문의 기본 구조
    // if (condition) {
    //     statement;
    // }

    // condition == "식"이다. 식은 단독으로 실행될 수 없다. 실행되기 위해서는 statement가 있어야 한다.
    // statement가 있어야 문장이 되고, 실행될 수 있다.
    // 표현식이 있고, 그 뒤에 세미콜론이 있을 때 문장이 되어 실행할 수 있게 된다.

    // 그러나 반대로, 세미콜론이 있다고 해서 반드시 문장이고, 실행할 수 있는 것은 아니다.
    // int num = 0 // 같은 경우이다.

    // 세미콜론 하나만 놓을 수도 있다.
    // ; // 이런 것을 null statement라고 한다.

    // if (condition);
    //     cout << "wow" << endl;
    // 위와 같은 식은 condition의 true/false 여부와 관계없이 무조건 statement가 실행된다.
    // 식 뒤에는 statement가 있어야된다고 했는데, 세미콜론이 붙으면서 null statement가 들어가게 된 것이다.
    // 그로인해 "표현문 + statement => 식" 의 구조가 완성되어 아래 있는 statement가 실행되게 된다.

    // if (num == 0){
    //     cout << "wow" << endl;
    //     cout << "wow1" << endl;
    // }
    // 위와 같이 중괄호로 두 개를 묶어주는 것을 "복합문"이라고 한다.

    // int num0 = 0;
    // if (num0++ + num0++ == 1){
    //     cout << num0 << endl; 
    // => 실행 안됨(이건 환경마다 다름, condition 내에서 어떻게 num0이 내부적으로 연산되고 있는지는 정의된 것이 없음)
    // 다만 condition이 마무리되었을 때, num0은 +1이 두 번 실행된 상태여야 한다는 것만 확실하다.
    // }
    // cout << num0 << endl; // => 2가 출력된다.
    // if문 안의 condition도 하나의 시퀀스 포인트이다. -> if문의 condition이 마무리되는 순간, condition은 모두 계산되어있어야 한다.
    
    // int score;
    // cin >> score;
    // char grade;
    // if (score == 100)
    //     grade = 'A';
    // else if (90 <= score < 100)
    //     {grade = 'B';}
    // else if (80 <= score < 90)
    //     {grade = 'C';}
    // else
    //     {grade = 'D';}

    // cout << grade << endl;

    // 95를 넣으면 B가 나오는데, 85를 넣어도 B가 나온다. 그 이유가 무엇일까?
    // 연산자 우선순위 때문에 그렇다. 우선순위가 같은 경우, 부등호는 left to right의 차례로 흐른다.
    
    // 95를 넣었을 때, 좌측의 90 <= score부터 계산이 된다. 이는 true이고, true는 1로 변환된다.
    // 이어서 1 < 100 이 평가가 되고 이는 true이기 때문에 B가 출력이 되는 것이다.

    // 85를 넣었을 때도 좌측의 90 <= score가 계산이 되고, 이는 false이기 때문에 0으로 변환된다.
    // 이어서 0 < 100 이 평가가 되고 이는 true이기 때문에 B가 또 출력이 되게 된다.

    // 위와같은 상황을 방지하기 위해서는 조건문을 "90 <= score && score < 100"과 같은 형식으로 넣어줘야 한다.

    // int score;
    // cin >> score;
    // char grade;
    // if (score == 100)
    //     grade = 'A';
    // else if (90 <= score && score < 100)
    //     {grade = 'B';}
    // else if (80 <= score && score < 90)
    //     {grade = 'C';}
    // else
    //     {grade = 'D';}

    // cout << grade << endl;

    // int score0 = 90;
    // int score1(80);
    // if (score0 >= 90 && score1 >= 90){
    //     cout << "pass" << endl;
    // } else {
    //     cout << "fail" << endl;
    // }

    // if문 안에 선언도 가능하다.
    // int num0, num1;
    // if (int count = scanf("%d %d", &num0, &num1)) 
    //     printf("count : %d", count);
    // scanf의 return 값은, 뒤에 있는 변수들을 얼마나 성공적으로 받았느냐이다.
    // 그러므로 두 개를 다 받으면 2, 한 개만 받으면 1이 된다.
    // count가 0이면, if문이 실행이 되지 않고 count가 1 이상이면 if문이 실행된다.
    // 또한 이렇게해주면 count의 scope가 if문과 이어지는 else문으로 한정되어, 추후 작업환경에 좋다.

    // if문 안에 변수 선언도 가능하다.
    if (int num0, num1; int count = scanf("%d %d", &num0, &num1))
        printf("count : %d\n", count);
}