#include <iostream>

using namespace std;

int main() {
    // 지역변수(블록 안에 있는 변수들) -> 메모리 자동할당
    // int n1;
    // {
    //     int n1;
    // }
    // 지역변수들은 외부에서 접근이 불가하다.
    // n2;

    // 지역변수 앞에 "static"을 붙일 수 있다. 붙인것과 아닌 것의 차이를 알아보자
    // for (int i = 0; i < 3; ++i) {
    //     int num = 0;
    //     ++num;
    //     cout << num << endl;
    // } 
    // num은 항상 1이 출력됨 -> num이 지역변수 중 "자동변수"이기 때문에 블럭을 벗어나는 순간
    // 메모리가 자동으로 해제된다. 결국 0으로 초기화 -> 1 -> 출력 의 반복이다.

    // num 앞에 static을 붙여보자
    // for (int i = 0; i < 3; ++i) {
    //     static int num = 0;
    //     ++num;
    //     cout << num << endl;
    // }
    // 1, 2, 3이 순차적으로 출력됨 -> static을 붙이는 순간, 지역변수가 정적으로 선언된다.
    // 정적 메모리 할당은, 프로그램이 시작할 때 할당되고, 종료될 때 해제된다.
    // 결국 위에서 블록을 넘어가도 이미 선언된 num에 대한 정보가 사라지지 않았기 때문에 상태를 변경해가며 출력된 것이다.

    // 동적 할당에 대해 알아보자
    // int* pNum = new int; // "new"라고 선언해주면, 동적 메모리 할당이 된다.
    // 이 new 라는 녀석은, "힙"이라는 영역에 메모리를 할당하고, 그 메모리에 대한 주소를 리턴해준다.
    // 그렇기 때문에 항상 포인터로 접근해야 한다.
    // 만약 자동메모리로 선언한다고 하면, int num;의 경우 메모리의 위치에 대해 num이라는 이름이 있다.
    // 그러나 동적 할당은 힙의 특정 영역에 integer만큼 size로 할당이 되는데, 이름이 없다.
    // 그래서 바로 주소값을 리턴하고, 그 주소값을 바로 포인터에 저장해주는 것이다.

    // 동적 할당 된 메모리를 사용할 때는 포인터의 역참조 방법을 사용해야 한다.
    // *pNum = 1;

    // 또한 항상 사용 후에는 메모리를 지워줘야한다. 그렇지 않으면 메모리가 계속해서 늘어나게 된다.
    // delete pNum;

    // 메모리가 계속 늘어나는 예시
    // 먼저 일반적인 지역변수 중 자동변수를 계속 선언할 때 -> 프로세스 메모리에 별 문제가 없다.
    // while (true) {
    //     int num; // stack 영역에 할당되어서 블록에 들어올 때 생기고, 블록에서 나갈 때 지워진다.
    // }

    // 동적 메모리로 할당할 때 -> 계속해서 사용하는 메모리의 용량이 늘어난다.
    // while (true) {
    //     int* num = new int;
    //     cout << num << endl;
    //     cout << &num << endl;
    //     delete num;
    // }
    // 위와같은 현상을 메모리 누수(leak)라고 표현한다.

    // 동적 메모리가 할당된 녀석을 사용해보자
    // int* pNum0 = new int(123); // 123을 동적 메모리로 할당
    // int* pNum1 = pNum0; // pNum0과 pNum1은 같은 메모리 주소를 가리키게 됨

    // cout << *pNum0 << endl; // 123
    // // 이제 pNum0을 해제해보자
    // delete pNum0;

    // cout << *pNum0 << endl; // error
    // cout << *pNum1 << endl; // error

    // case2
    // int *pNum = new int;
    // delete pNum;
    // delete pNum; //  pointer being freed was not allocated 에러 발생
    // 이미 지워진 녀석을 다시 지울 수는 없다.

    // pointer 사용시 발생할 수 있는 또 다른 실수
    // 외부에서 포인터를 선언
    // int* pNum;
    // {
    //     // 현재 n은 블록 내에서 자동할당된 상태, 그러므로 블록을 벗어나면 사라짐
    //     int n = 10;
    //     // pNum이라는 포인터에 n의 주소값을 넣어준 것
    //     pNum = &n;
    // }
    // // 블록이 끝났으니 n의 주소값은 사라진 상태
    // cout << *pNum << endl; // -> 여기서 나오는 값은 "보장된다"라고 보기 힘듦

    // 동적 배열
    // c++는 컴파일 시점에 결정되는 언어이기 때문에, 선언되는 배열의 길이도 컴파일 타임에 알아야 한다.
    // 그래서 아래와 같은 특징이 있었다.
    // const int a = 10;
    // int arr[a] = {1, 2, 3}; // 가능

    // int a = 10;
    // int arr[a] = {1, 2, 3}; // 불가능

    // int a;
    // cin >> a;
    // int arr[a] = {1, 2, 3}; // 불가능

    // 동적 메모리 할당을 해주면 입력값을 배열의 길이로 넣어주는 것이 가능하다.
    // int a;
    // cin >> a;
    // int* arr = new int[a]{1, 2, 3}; // 초기화를 미리 선언해줄 수도 있다.

    // cout << arr[0] << endl; // 1
    // cout << arr[1] << endl; // 2
    // cout << arr[2] << endl; // 3

    // 동적 할당된 배열을 지워줄 때는 delete arr; 가 아니라 delete[] arr;로 선언해줘야한다.
    // delete[] arr;

    // 구조체를 다뤄보자
    // 구조체 선언
    // struct Person{
    //     float weight;
    //     float height;
    // };

    // 동적 할당
    // Person* person = new Person{74.1, 182.2};
    // 다만 이전과 다르게 구조체 내의 값에 접근하려면 아래와 같이 화살표로 선언해줘야한다.
    // cout << person->weight << endl;
    // cout << (*person).weight << endl; 위 연산은 좌측과 같다.

    // 동적 할당된 녀석들을 요소로 가지고 있는 배열 만들기
    // pointer형식의 요소를 갖는 배열 선언
    // Person* persons[] = {
    //     // 아래 요소들은 모두 동적 할당 된 녀석들이기 때문에 Person type의 포인터 형식이라고 할 수 있다.
    //     new Person{56.3, 174.3},
    //     new Person{74.2, 184}
    // };

    // range based for 문을 사용 -> 요소들의 타입은 Person pointer 타입이다.
    // for (Person* person : persons) {
    //     cout << person->weight << endl;
    // }

    // 그런데 이전에 range based for 문을 사용할 때는 복사된 값을 가져오기 때문에
    // 값을 변경하고 싶으면 type 뒤에 &연산자를 붙여서 아래와 같이 설정해줘야 했다.
    // for (Person& person : persons) {
    //     person.weight = 0;
    // }

    // 그러나 pointer를 사용하면, 복사된 값을 가져오는 것은 맞지만 복사된 값이 주소 그 자체이기 때문에
    // &연산자를 사용하지 않고 그대로 값을 바꿔주는 것이 가능하다.
    // for (Person* person : persons) {
    //     person->weight = 0;
    // } // 가능
}