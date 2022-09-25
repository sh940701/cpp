// c언어는 <stdio.h>를 include하는 반면, cpp에서는 .h를 빼고 앞에 c를 붙여주면, c언어에서 사용하는 패키지를 불러올 수 있다.
// stdout은 표준 출력 스트림(연속적으로 흐른다.) -> 콘솔 화면에 연결되어있다.
// 우리가 stdout에 뭔가를 쓰게 되면은, 연결되어있는 콘솔 화면에 출력되는 것이다.
#include <cstdio>

int main() {
    // 아래에서 %d라는 형식 지정자가 뒤에 있는 10을 흡수해서 Hello 10이 출력된다.
    // 형식 지정자를 가지고 있는 문자열이라서 형식 문자열이라고 한다.
    // printf("Hello %d", 10);

    // d는 decimal 정수형을 나타낸다. i도 마찬가지이다
    // printf("%d + %d + %i\n", 2, 3, 2 + 3);
    // -1의 경우에는 비트가 전부 1로 세워진 경우이다. 32bit가 모두 1 이를 unsigned로 표현했을 경우 43억 가까운 수(최댓값)이 나온다.
    // printf("%u\n", -1);  

    // 16진수 기준으로 출력해준다. 16진수에서 10은 a, X를 기입하면 대문자 A가 나온다.
    // printf("%x + %x , %X\n", 10, 10, 10);

    // 255 >? overflow
    // printf("%hhx\n", 256);

    // printf("%-10da\n", 1);
    // printf("%-10da\n", -1);
    // printf("%10fa\n", 1.1);
    // printf("%10fa\n", -1.1);
    
    // stdout을 사용해서 콘솔이 아니라, 파일에 출력해보자.
    // freopen -> 가장 오른쪽에 있는 녀석을, 가장 첫번째(왼쪽)파일로 재설정(연결) 해준다.
    // stdout은 원래 콘솔에 연결이 되어있는데, output.txt에 연결해주는 것이다.
    freopen("output.txt", "w", stdout);
    printf("Hello World");
    freopen("output.js", "w", stdout);
    printf("console.log('hi')");
}