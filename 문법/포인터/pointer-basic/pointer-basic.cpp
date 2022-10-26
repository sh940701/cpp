#include <iostream>

using namespace std;

int main() {
    // 포인터를 선언하는 방법
    // 먼저 가리킬 변수 선언
    // int num = 147;

    // pointer 선언 -> 자료형 뒤에 *를 붙임, 가리킬 변수 앞에 &기호 붙임
    // &기호는 "a & b" 형식으로 사용하면 bitwise 연산이고, 변수 앞에 붙으면 주소 반환 연산자가 된다.
    // int* pointer = &num;

    // cout << num << endl; // 147
    // cout << pointer << endl; //  0x16ddeef5c -> num의 "주소값"
    // cout << *pointer << endl; // 147 -> 주소값에 저장되어있는 값(역참조)

    // 역참조 값 바꿔주기
    // *pointer = 100;
    // cout << *pointer << endl;
    // cout << num << endl;

    // 변수 선언
    // int num = 147;

    // // pNum 0과 1에 같은 주소값 할당
    // int* pNum0 = &num;
    // int* pNum1 = &num;

    // // pNum2에 pNum0의 값 할당
    // int* pNum2 = pNum0; // -> int* pNum2 = &num; 과 같음

    // cout << &num << endl;
    // cout << pNum0 << endl;
    // cout << pNum1 << endl;
    // cout << pNum2 << endl;
    // cout << endl;

    // cout << num << endl;
    // cout << *pNum0 << endl;
    // cout << *pNum1 << endl;
    // cout << *pNum2 << endl;
    // cout << endl;

    // num = 100;
    // cout << num << endl;
    // cout << *pNum0 << endl;
    // cout << *pNum1 << endl;
    // cout << *pNum2 << endl;
    // cout << endl;

    // cout << &num << endl;
    // cout << pNum0 << endl;
    // cout << pNum1 << endl;
    // cout << pNum2 << endl;
    // cout << endl;

    // 아무것도 가리키지 않는 포인터 선언 후 출력
    // int* pNum0 = 0;
    // cout << pNum0 << endl;

    // 포인터에 리터럴 변수를 직접 입력한 후 출력
    // int* pNum0 = 0;
    // cout << pNum0 << endl;

    // // 역참조 값은?
    // cout << *pNum0 << endl;

    // int num = 1;
    // int* pNum = &num;
    // 위와같이 변수와 포인터를 선언해줬을 때 포인터에 int라는 자료형은 왜 붙는걸까?
    // 포인터가 가리키고 있는 주소를 어떻게 취급을 해줄지 정해주는 것이다.

    // union Union {
    //     int i; // 4byte
    //     float f; // 4byte
    //     double d; // 8byte
    // };

    // Union u; // 8byte
    
    // 원래 union형의 포인터를 적용하기 위해서는 union*으로 선언을 해줘야한다.
    // 그러나 아래에서는 포인터의 특성을 알아보기 위해 각자 타입의 포인터로 강제 형변환을 해 준 것이다.
    // int* ip = (int*)&u;
    // float* fp = (float*)&u;
    // double* dp = (double*)&u;

    // union은 memory를 공유하기 때문에, 세 변수의 포인터 value(Address)는 모두 u의 주소값과 같다.
    // cout << &u << endl; // 0x16d606f58
    // cout << ip << endl; // 0x16d606f58
    // cout << fp << endl; // 0x16d606f58
    // cout << dp << endl; // 0x16d606f58

    // u라는 uinon 변수 내의 i에 1을 넣어보자
    // union은 메모리 주소를 공유하기 때문에 i, f, d의 메모리 주소는 같다.
    // u.i = 1;

    // cout << *ip << endl; // 1
    // cout << *fp << endl; // 1.4013e-45
    // cout << *dp << endl; // 2.122e-314
    // ip의 역참조만 제대로 된 값을 출력한다. 왜 그런 것일까?
    // i에 값을 넣게 되면 union이 가지고 있는 메모리 위치에 integer의 memory layout에 맞게 값을 저장한다.
    // 그렇기때문에 같은 주소라도 다른 방식으로 해당 memory를 읽으면 의도하지 않은 값이 출력되는 것이다.

    // u.f에 값을 할당해보자
    // u.f = 1;

    // cout << *ip << endl; // 1065353216
    // cout << *fp << endl; // 1
    // cout << *dp << endl; // 2.64835e-314
    // 마찬가지로 fp의 역참조 값만 의도한대로 출력이 된다.
    // union의 메모리 위치에 float방식(부동소수점. 가수부 진수부 등)대로 저장하였기 때문에 그런 것이다.

    // 알 수 있는 것
    // 포인터는 주소값인데 왜 앞에 type이 명시되어 있는가?
    // type은 주소값에 갔을 때 있는 값을 어떤 식으로 취급할지를 명시해주는 것이다.

    // 포인터에 상수 넣기

    // num이라는 변수 선언
    // int num = 10;

    // num에 대한 pointer pNum 선언
    // const int* pNum = &num;

    // num2라는 변수 선언
    // int num0 = 20;

    // "const int num = 0;" 으로 초기화했을 때에는 num = 1; 과 같이 값의 변경이 불가능하다.
    // 그러나 pointer에서의 개념은 조금 다른데, "const int* pNum;"으로 선언해준 후에
    // "pNum = &num1;"과 같이 pNum이라는 변수가 다른 주소값을 value로 가지도록 초기화가 가능하다.
    // 다만 어떠한 주소값을 가졌을 경우, 그 주소값을 역참조하여 주소값에 있는 data를 변경하는 것이 불가능해진다.

    
    // pNum = &num0; // 정상
    // *pNum = 200; // error

    // pNum = &num; // 정상
    // *pNum = 100; // error

    // num = 100; // 정상
    // num0 = 200; // 정상
    // 즉 위와같이 사용할 경우, num이라는 변수의 value를 다른 값으로 직접 초기화는 가능하지만
    // 역참조를 통한 값의 변경이 불가능해진다고 생각하면 된다.

    // "int* const pNum"의 형식으로 선언해줬을 때
    // int* const pNum의 형식으로 선언해주게 되면 pNum이라는 변수의 value인 주소값을 바꿀 수 없게 된다.

    // int num0 = 0;
    // int num1 = 1;

    // 또한 위와 반대로 역참조를 통한 값의 변경은 가능해지게 된다.
    // int* const pNum = &num0;
    // pNum = &num1; // error
    // *pNum = 10; // 정상

    // 만약 pNum의 value인 address값도 변경하지 못하고, pNum의 역참조 값도 변경하지 못하게 하고싶다?
    // 그럼 아래와 같이 const를 두 번 사용하여 선언해주면 된다.
    // const int* const pNum = &num0;
    // pnum = &num1; // error
    // *pNum = 10; // error
}