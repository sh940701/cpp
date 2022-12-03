#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::chrono_literals;


// int main() {
//     int num = 0;
//     // 이 영역에 대해서 한 thread만 접근하게 해주고 싶다. -> mutex사용
//     // mutual exclusive의 약자로, 상호 배제라는 의미이다.
//     std::mutex m;
//     // mutex 객체인 m을 같이 캡쳐하여 넘겨준다.
//     auto func = [&num, &m] {
//         for (int i = 0; i < 1000000; ++i) {
//             m.lock(); // mutex 객체를 lock해준다.
//             // mutex 객체의 lock으로 감싸져있는 부분이 Critical Section이다. -> 한 쓰레드만 접근 가능
//             num++;
//             m.unlock(); // mutex 객체를 unlock해준다.
//             // std::cout << num << std::endl;
//         }
//     };

//     std::thread th0(func);
//     std::thread th1(func);

//     th0.join();
//     th1.join();

//     std::cout << num << std::endl; // 1000000에 대한 근삿값이 나온다.
// }




// 의도적으로 exception을 발생시켜보자
// void foo(int& num) {
//     ++num;
//     throw std::runtime_error("err");
// }

// int main() {
//     int num = 0;
//     std::mutex m;
//     auto func = [&num, &m] {
//         for (int i = 0; i < 10000; ++i) {
//             try
//             {
//                 // CS에서 작업 수행 중 exception이 발생해도, lock_guard로 lock을 걸었기 때문에
//                 // 스코프를 벗어나는 순간 자동으로 lock이 해제된다.
//                 // std::lock_guard<std::mutex> lock(m);
//                 // m.lock(); // 만약 lock / unlock으로 진행할 경우, exception 발생 이후 unlock이 안되기 때문에
//                 // 다른 쓰레드에서 접근이 불가하여 더이상 진행이 되지 않는다.
//                 // foo(num);
//                 // m.unlock();

//                 // unique_lock과 try_to_lock을 사용해서, 락을 걸 수 있는지에 대한 결과를 기준으로 처리해줄 수도 있다.
//                 // unique_lock 객체의 두번째 인자로 std::try_to_lock을 넘겨준다.
//                 std::unique_lock<std::mutex> lock(m, std::try_to_lock);
//                 if (lock.owns_lock()) {
//                     // ... -> lock이 가능할 때의 프로세스 처리
//                 } else {
//                     // ... -> lock이 불가할 때의 프로세스 처리
//                 }
//             }
//             catch(...)
//             {
//                 std::cout << "error" << std::endl;
//             }
//         }
//     };

//     std::thread th0(func);
//     std::thread th1(func);

//     th0.join();
//     th1.join();

//     std::cout << num << std::endl;
// }



// recursive_mutex를 사용하면 같은 쓰레드(m)에 대해서만 recursive하게 lock을 걸 수 있다.
// 아래의 경우 foo()와 goo()에서 lock을 잡는 쓰레드가 같기 때문에 가능한 것이다.
// 또한 recursive_mutex는 lock을 잡은만큼 unlock을 실행해줘야 한다.
// std::mutex m0;
// std::recursive_mutex m;
// // recursive lock 예시를 위한 함수
// void foo() {
//     std::lock_guard<std::mutex> lock(m);
// }

// // 아래와 같이 함수가 생성되어 있을 때, goo()를 호출하면 m에 대해 lock을 잡는다.
// // 그런데 내부적으로 foo()가 m에 대해 lock을 잡고자 하는데 잡을 수 없기 때문에 진행이 되지 않는다.
// // 이런 상황을 위해 recursive_mutex를 사용이 가능하다.
// void goo() {
//     std::lock_guard<std::mutex> lock(m);

//     foo();
// }

// int main() {
//     std::timed_mutex m;
//     // 10초동안 lock 걸기를 대기하겠다. 10초 안에 lock이 걸리면 true, 그러나 그 안에 lock이
//     // 걸리지 않으면 false를 반환하겠다.
//     m.try_lock_for(10s);

//     std::recursive_mutex m0;

// }



// 그런데 사실 아래와 같은 예시에서 하나의 변수에 대한 동기화만 필요하면 mutex를 사용하지 않아도 된다.
// mutex는 어떤 하나의 scope단위에 대한 동기화가 필요할 때 사용하는 것
// #include <atomic>

// int main() {
//     std::mutex m;
//     std::atomic_int num = 0;

//     auto func = [&num, &m] {
//         for (int i = 0; i < 10000; ++i) {
//             // mutex는 이렇게 하나의 scope에 대한 동기화 작업에 보통 쓰인다.
//             // std::lock_guard<std::mutex> lock(m);
//             // num을 int가 아닌, atomic_int로 설정해주면 해당 값에 대한 작업이 진행될 때
//             // 변수에 대한 atomic한 연산을 cpu가 지원해주기 때문에 동기성이 유지된다.
//             num++;
//         }
//     };
//     num.is_lock_free(); // 이런 녀석도 있는데, 이녀석이 true여야 atomic한 연산을 제공하는 것이다.
//     // 만약 true가 아니라면, 별도의 동기화 매커니즘을 통해 작업을 진행해야 한다.

//     std:: thread th0(func);
//     std:: thread th1(func);

//     th0.join();
//     th1.join();

//     std::cout << num << std::endl;
// }


// 생성자 : 특정 job을 계속 만드는 녀석
#include <queue>
// mutex를 공유, condition_variable을 공유, job을 담은 queue를 공유하는 함수
void produce(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue) {
    while (true) {
        // 한 쓰레드에서 100ms마다 jobQueue에 1이라는 job을 넣어준다.
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> lock(m);
            jobQueue.push(1);
            std::cout << "produce: " << jobQueue.size() << std::endl;
        }
        // job이 만들어지면, 조건변수에게 알려준다.
        // 조건변수를 가지고 wait하고 있던 녀석들이 깨어난다.
        cv.notify_one();
    }
}

void longTimeJob() {
    std::this_thread::sleep_for(200ms);
}

// 소비하는 녀석 -> 같은 mutex를 공유하고, 조건변수 wait를 할 때 mutex를 넘겨줘야 한다.
void consume(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue, const char* name) {
    while(true) {
        {
            std::unique_lock<std::mutex> lock(m);

            // lost wakeup -> wait 전에 notify를 보낼 수 있다. 이런 경우 wait를 하면 받은 notify가 무시된다.
            // 이런 경우를 대비하여 notify가 없더라도 wait을 하기 전에 한 번 더 확인을 해주는 로직
            if (jobQueue.empty()) {
                cv.wait(lock);
            } 

            // squrious wakeup -> 실제로 notify가 오지 않았는데 깨어나는 경우도 있다.
            // 이런 경우를 방지하기 위해 깨어났다 하더라도 empty인지 다시 한 번 확인해주는 로직
            if (jobQueue.empty()) {
                continue;
            }

            int result = jobQueue.front();
            jobQueue.pop();

            std::cout << name << "  " << "consume: " << jobQueue.size() << std::endl;
        }
        longTimeJob();
    }
}


int main() {
    std::mutex m;
    std::condition_variable cv;
    std::queue<int> jobQueue;

    std::thread producer(produce, std::ref(m), std::ref(cv), std::ref(jobQueue));
    std::thread consumer0(consume, std::ref(m), std::ref(cv), std::ref(jobQueue), "consumer0");
    std::thread consumer1(consume, std::ref(m), std::ref(cv), std::ref(jobQueue), "consumer1");

    producer.join();
    consumer0.join();
    consumer1.join();
}