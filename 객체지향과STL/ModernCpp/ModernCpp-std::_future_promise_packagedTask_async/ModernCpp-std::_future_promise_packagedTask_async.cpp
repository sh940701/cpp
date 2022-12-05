#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;

// int main() {
//     // <보낼 값 타입>
//     std::promise<int> pro;
//     // <받을 값 타입> -> 여기서 만든 future객체는, pro라는 promise객체와 연동이 되어있다.
//     std::future<int> fut = pro.get_future();

//     // thread에 promise 객체를보내고, thread에서 내부적으로 promise에 대한 처리를 해준다.
//     std::thread th([](std::promise<int> pro) {
//         std::this_thread::sleep_for(2s);
//         // set은 한번만 가능하다.
//         pro.set_value(10);
//         // promise 객체는 복사가 안되기 때문에 std::move(pro)로 인자값을 넘겨준다.
//     }, std::move(pro));

//     // get 함수를 통해서 프로미스가 보낸 값 받기 -> get도 한번만 가능하다(move를 하기 때문)
//     std::cout << fut.get() << std::endl;
//     th.join();
// }


// int main() {
//     std::promise<int> pro;
//     std::future<int> fut = pro.get_future();

//     std::thread th([](std::promise<int> pro) {
//         try
//         {
//             // 만약 thread에서 작업중 error가 났다?
//             throw std::runtime_error("err");
//         }
//         catch(...)
//         {
//             // current exception의 정보를 가져와서 exception_ptr 객체에 넣어준다.
//             std::exception_ptr e = std::current_exception();
//             // exception의 정보가 담긴 e 라는 객체를 promise객체의 set_exception함수에 넣어준다.
//             // 이를 통해 tuture 객체는 e 라를 객체를 받게 된다.
//             pro.set_exception(e);
//         }
//     }, std::move(pro));

//     // future 객체에서 get()을 실행할 때, exception이 넘어오게 된다.
//     try
//     {
//         std::cout << fut.get() << std::endl;
//     }
//     catch(const std::runtime_error& err)
//     {
//         std::cout << err.what() << std::endl; // err
//     }
//     th.join();
// }



// package_task
// int main() {
//     // promise의 경우에는, promise객체를 만들고, thread에 함수 객체를 넘겨주며
//     // 객체의 인자값으로 promise 객체를 넘겨주었어야 했다. 그러나 packaged_task의 경우에는
//     // 이를 더 추상화하여 아예 task 객체를 만들 때 함수 객체를 함께 넘겨준다.
//     std::packaged_task<int(int)> task([](int value){
//         std::this_thread::sleep_for(1s);
//         if (value < 0) {
//             throw std::runtime_error("err");
//         }
//         // 원래는 promise 객체에 value를 세팅해줬어야 한다.
//         // 그러나 package_task에서는 이를 더 추상화하여, return을 해주면 된다.
//         return value;
//     });

//     // promise 객체와 같이 get_future()함수를 사용하여 future 객체를 만들 수 있다.
//     std::future<int> fut = task.get_future();

//     // promise에서는 thread에 함수 객체를 넘겨주고 그 인자값으로 promise 객체를 주었는데
//     // packaged_task에서는 task객체와, 들어갈 인자값을 넘겨준다.
//     std::thread th(std::move(task), -1);

//     // package_task를 사용해주면 내부적으로 exception을 핸들링하여 넘겨준다.
//     // 따라서 위와같이 promise객체애 대한 try & catch를 따로 해줄 필요 없이
//     // future 객체에서 get() 함수를 실행할 때에 있어서만 try & catch를 실행해주면 된다.
//     try
//     {
//         std:: cout << fut.get() << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     th.join();
// }



// async
// async 객체는, 명시적으로 thread를 만들고 join하는 과정과 promise 객체를 만들어서 이에 값을
// 할당하는 과정을 추상화한 역할을 한다. 이 때 새로운 thread를 만들어서 연산을 진행할지는
// async 객체를 만드는 순간 스스로 판단한다. 이를 std::launch::deferred, async로 컨트롤 해 줄 수 있다.
// deferred는, 아래에서 fut.get()을 만날 때까지 함수실행을 지연시킨다. -> 그래서 main쓰레드에서 같이 진행하는건가?
// async는, 비동기적으로 실행한다는 의미이고 아마도 그래서 무조건 다른 쓰레드에서 진행하게 되는 것 같다.

int main() {
    // std::launch::deferred X -> 0x1e4972500
    // std::launch::deferred O -> 0x1e4972500
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl; 

    // async 객체도 callable한 녀석을 인자로 넣어줘야 한다.
    std::future<int> fut = std::async(std::launch::deferred, [](int value) {
        // std::launch::deferred X -> 0x16b9b7000
        // std::launch::deferred O -> 0x1e4972500
        std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

        // std::async 또한 excepcion 처리를 따로 해주지 않아도 내부적으로 처리하여 반환해준다.
        if (value < 0) {
            throw std::runtime_error("err");
        } return value;

    // callable한 객체와 함께 인자값도 넣어주어 바로 실행시켜야 한다.
    }, 100);

    // futuer 객체로 get() 함수를 실행할 때만 exception 처리를 해주면 된다.
    try
    {
        std::cout << fut.get() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}