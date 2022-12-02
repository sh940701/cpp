#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// int main() {
//     // 비어있는, 아직 할당받지 않은 thread
//     // std::thread th;

//     // 메인 쓰레드의 아이디
//     std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

//     // 안에 callable한 객체를 넣어야 할당받았다고 할 수 있다.
//     std::thread th([]{
//         // 현재 쓰레드의 아이디
//         std::this_thread::sleep_for(1s); // 쓰레드를 1초 sleep 시킴
//         std::cout << "Custom thread ID: " << std::this_thread::get_id() << std::endl;
//     });
//     // join이라는 녀석은 thread가 끝날 때까지 대기한다.
//     th.join(); // 이 녀석이 없으면 런타임 에러가 발생한다.

//     // thread는 복사가 불가능하다. std::move를 사용해서 소유권을 옮겨주는 것만 가능하다.
//     std::thread th0 = std::move(th);

//     // main thread로 sleep 시킬 수 있다.
//     std::this_thread::sleep_for(1s);
//     std::cout << "Complete" << std::endl;
// }



// 쓰레드별로 할당되는 공간 호출
// template <typename T>
// void foo(T id){
//     for (int i = 0; i < 10; ++i) {
//         // 각각 thread의 thread_local 이라는 공간의 num에 대한 증가.
//         static int num = 10;
//         num ++;
        
//         std::cout << id << "  :  " << num << std::endl;
//     }
// }

// // main 함수 외부에 있는 녀석은 정적공간에 할당
// int num;

// int main() {
//     // 함수 내에 있는 변수는 자동공간에 할당이 된다.
//     int num;

//     // 함수 내에 있는 static 변수는 정적 공간에 할당된다.
//     static int num1;

//     // new로 선언된 녀석은 동적 공간에 할당된다.
//     int* num2 = new int(1);

//     // thread local - 정적 공간과 비슷하다. -> 정적 공간은 프로그램 시작하고 한번 초기화
//     // 끝날때 해제 -> thread local은 thread가 존재하는 동안 한번 초기화, thread 종료시 한번 해제
//     // static 공간은 프로그램의 글로벌한 공간, thread local은 thread 별로 존재하는 정적 공간

//     // foo(std::this_thread::get_id());

//     std::thread th([]{
//         foo(std::this_thread::get_id());
//     });
//     std::thread th2([]{
//         foo(std::this_thread::get_id());
//     });

//     th.join();
//     th2.join();

//     /* 각각의 thread_local에 대한 변수를 변경하는 함수의 결과값이 아래와 같이 나왔다.
//     0x16efd3000  :  0x16f05f00011  :  
//     0x16efd3000  :  12
//     0x16efd3000  :  13
//     0x16efd3000  :  14
//     0x16efd3000  :  15
//     0x16efd3000  :  16
//     110x16efd3000  :  
//     0x16f05f000  :  12
//     0x16f05f000  :  13
//     0x16f05f000  :  14
//     0x16f05f000  :  15
//     0x16f05f000  :  16
//     0x16f05f000  :  17
//     170x16f05f000  :  
//     0x16efd3000  :  18
//     0x16efd3000  :  19
//     0x16efd3000  :  20
//     18
//     0x16f05f000  :  19
//     0x16f05f000  :  20
//     동시에 실행하게 될 경우, 각 쓰레드마다 함수를 실행하는데, 각각의 공간에 있는 변수를
//     변경해야 하기 때문에 이런 결과가 나타난 것이다. 완전히 따로 연산을 하는 것
//     */

//    /* 함수 내의 static 변수를 변경하는 함수의 결과값이 아래와 같이 나왔다.
//     0x16b213000  :  11
//     0x16b29f000  :  11
//     0x16b29f000  :  12
//     0x16b29f000  :  13
//     0x16b29f000  :  0x16b213000  :  15
//     0x16b213000  :  16
//     0x16b213000  :  17
//     0x16b213000  :  18
//     0x16b213000  :  19
//     0x16b213000  :  20
//     0x16b213000  :  21
//     14
//     0x16b29f000  :  23
//     0x16b29f000  :  24
//     0x16b29f000  :  25
//     0x16b29f000  :  26
//     0x16b213000  :  27
//     0x16b213000  :  28
//     0x16b29f000  :  28
//     0x16b29f000  :  29
//     이 경우에는 static 변수를 각 쓰레드에서 변경하는데, 이 때 완결성이 보장되지 않는다.
//     num을 th1에서 변경하고 있는데 th2에서도 변경하고자 하면 ++한 값에 대해서 둘이 같은 값을
//     내놓을 수도 있는 개념이다.
//     */
// }



void foo() {
    for (int i = 0; i < 10; ++i) {
        static int num = 10;
        num++;
        std::cout << num << std::endl;
    }
}

int main() {
    int num = 10;
    num += 1;
}

// 전역 변수를 thread0, thread1에서 동시에 제어하는 예를 들어보자.
// 컴퓨터 수준에서 +1를 하기 위해 인지하는 단계는 아래와 같다고 가정하자.
// 1. load num
// 2. register += 1
// 3. store register

// 아래와 같이 진행했을 때, 둘 다 0에 대해서 1을 더하게 되면, 연산은 두 번이 이루어졌지만
// 실제로 num의 결과값은 2가 아닌 1인 상황이 벌어질 수 있는 것이다.
// 이런 상황을 한 공유 데이터에 대해서 경쟁하게 되는 race condition이라고 한다.
// 근데 실제로 이런 경우는 커널 스레드가 여러개일 때 생기는 현상이 아닌가?
// 사용자 수준 스레드에서는 이런 일이 생기지 않을 것 같은,, 차라리 위 경우처럼
// 시분할로 인해 중간에 멈추고, 그 때 뭐 다른 작업이 수행돼서 완결성이 침해되는?
// 그런 예시가 더 맞을 것 같다. 사용자 수준 스레드에서는

// thread0     thread1
// 1. reg(0)
//             1. reg(0)
// 2. reg(1)   2. reg(1)
// 3. num(1)   3. num(1)