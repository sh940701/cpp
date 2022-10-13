#include <iostream>

using namespace std;

int main() {
    // void i; // 불가
    int num = 10;
    int* p = &num;

    // void type의 포인터 선언 가능 -> 어떤 형의 포인터든, 보이드 포인터로 변환이 가능하다.
    // void* vp = p;
    // cout << *p << endl;
    // cout << *vp << endl;

    // 이를 해결하기 위해서는 void pointer에 다른 형 pointer로 형변환을 해 주면 된다.
    // void* vp = p;
    // int* p0 = (int*)vp;
    // cout << *p0 << endl;

    // void포인터 배열 예시
    // // 배열도 일반 포인터처럼 void포인터에 담아줄 수 있다.
    // int nums[] = {1, 2, 3};
    // void* vp = nums;
    // // 그러나 type이 void이기 때문에 읽는 것 자체가 불가하다.
    // vp[0]; // error -> 읽는 것 자체가 안된다.

    // 그렇다면, void는 왜 있는 것일까?
    // C style의 할당 중 아래와 같은 것이 있다.
    // int* p = malloc(sizeof(int) * 3);
    // int size * 3만큼의 메모리(12byte)를 어딘가에서(heap) 할당해서 주소값을 넘겨주는 것(동적 할당)
    int* p = (int*)malloc(sizeof(int) * 3);
    delete(p);
    free(p);
}