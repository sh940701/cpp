#include <cstdio>

int main() {
    // int num;
    // int n = scanf("%d", &num);
    // printf("%d\n", n);

    // 아래와 같은 경우, scanf에 형식을 맞춰서 기입해줘야 한다. -> 10, 20, 30 (X) -> 10 + 20 = 30 (O)
    // int num0, num1, num2;
    // scanf("%d + %d = %d", &num0, &num1, &num2);
    // printf("%d, %d, %d\n", num0, num1, num2);

    // scanf에서 %d와 %i는 다르다.
    // 아래에서 10을 넣으면 10이 출력되지만, 0x10을 넣으면 16, 010을 넣으면 8이 출력된다.
    // int num0;
    // scanf("%i", &num0);
    // printf("%i\n", num0);

    // 문자열 출력해보기
    // char ch;
    // scanf("%c", &ch);
    // printf("%c\n", ch);
    // printf("%i\n", ch);

    // float 출력해보기
    // printf에서는 f와 lf가 같다. float이 printf로 들어가면 결국 double로 형변환이 이뤄지기 때문이다.
    // scanf에서는 f와 lf가 다르다. f는 float이고, lf는 double이다.
    // scanf는 직접 메모리에 접근해서 값을 변경하는 것인데, 이렇게 할 때 double과 float의 byte가 다르기때문에 정확하게 명시를 해줘야한다고 기억하면 됨.
    // 그렇게 하지 않으면 printf에서 float(4byte)을 출력하려고 하는데 double(8byte)가 담겨있게 되어, 에러가 나는 현상이 발생할 수 있다.
    // float f0;
    // double d0, d1;
    // scanf("%lf %lf %f", &d0, &d1, &f0);
    // printf("%lf, %lf, %lf\n", d0, d1, f0);

    // 진법 표현을 해보자
    // int num;
    // o를 붙이면 8진수, x를 붙이면 16진수
    // scanf("%o", &num);
    // printf("%d\n", num);

    // 막 먹고 안먹고 하는거에 대한 해결책. 강의 참고할 것
    // char ch;
    // scanf("%c", &ch);
    // printf("1, %c\n", ch);

    // getchar();
    // while(getchar() != '\n');

    // scanf("%c", &ch);
    // printf("2, %c\n", ch);

    // 콘솔과 연결되어있는 stdio를 txt파일과 연결하여, 이미 존재하는 txt파일을 읽어와보자.
    freopen("input.txt", "r", stdin);

    int num;
    scanf("%d", &num);
    printf("%d\n", num);

}