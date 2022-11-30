#include <iostream>
#include <memory>

// int main() {
//     int num = 10;
//     // 일반 포인터에 동적 할당을 해줄 때, 해제를 해줘야 한다.
//     int* p = new int(10);
//     delete p;

//     int* num0 = new int(10);
//     int* num1 = num0;
//     // 이럴 때는 어떤 녀석을 해제해줘야할까? -> 두 개 다 하면 내부적으로 에러 발생
//     delete num0;
//     delete num1;

//     // 포인터간 여러가지 할당이나 해제 등과 같은 부분을 더 쉽게 해주는 스마트포인터
// }


// struct Test {
//     int num;
//     Test(int num) : num(num) {
//         std::cout << "Construct: " << num << std::endl;
//     }

//     ~Test() {
//         std::cout << "Destruct: " << num << std::endl;
//     }
// };

// int main() {
//     Test* test = new Test(0);
//     // 스코프를 벗어나면 동적할당을 해제해주는 unique_ptr
//     std::unique_ptr<Test> p0(test);
//     std::unique_ptr<Test> p1(new Test(1)); // 이녀석은 한번만 할당될 수 있기 때문에 더 안전
//     auto p2 = std::make_unique<Test>(2);

//     // 이 녀석들을 일반 포인터처럼 사용할 수 있다.
//     test->num;
//     p0->num;

//     // 다만 unique_ptr은 같은 타입으로도 복사가 안 된다. -> 독점 소유권
//     Test* t = test; // 정상
//     std::unique_ptr<Test> t0 = p0; // error -> 포인터가 unique해야 하기 때문
//     // 아래와 같이는 가능하다. 대신 이후 p0는 무효한 상태가 된다.
//     std::unique_ptr<Test> t0 = std::move(p0); // 정상
// }



// struct Test {
//     int num;
//     Test(int num) : num(num) {
//         std::cout << "Construct: " << num << std::endl;
//     }

//     ~Test() {
//         std::cout << "Destruct: " << num << std::endl;
//     }
// };

// // 방법 1: unique_ptr은 복사가 안 되기 때문에 받을 때, 아예 소유권이 foo함수 안으로 넘어와야 한다.
// // main 함수에서 더이상 파라미터로 넘어오는 p 스마트 포인터를 사용하지 않는다.
// // 여기 넘어온 파라미터는 함수 실행 이후 foo 함수 밖에서 사용할 수 없다.
// void foo(std::unique_ptr<Test> p){
//     p.reset(new Test(39));
// }

// // 방법 2: 가리키는 녀석을 바꾸거나, 리셋시키고 싶은 경우, 레퍼런스로 넘길 수 있다.
// // 여기 넘어온 파라미터는 함수 실행 이후 함수 밖에서 다시 사용할 수 있다.
// void foo(std::unique_ptr<Test>& p){
//     p.reset(new Test(30));
// }

// // 방법 3: 만약, 소유권을 넘기는 것이 아니고, 데이터에 대한 변경도 없으면 그냥 포인터로 넘겨줘도 된다.
// // 원시 포인터를 가져오기 때문에, 변경이나 삭제가 가능하지만, unique_pointer가 포인터를 소유한 채로
// // 넘겨준 것이기 때문에 함부로 삭제나 변경을 했을 시, 추후 문제가 생길 수 있기 때문에
// // read-only로 사용하는 것이 좋다.
// void foo(Test* p){
//     std::cout << p->num << std::endl;
// }

// int main() {
//     Test* test = new Test(0);
//     std::unique_ptr<Test> p0(new Test(1));

//     // 아예 foo 함수 안으로 포인터의 소유권을 넘겨주는 방법 -> move를 이용
//     foo(std::move(p0));

//     // 레퍼런스로 넘기면, 함수 안에서 포인터가 가리키는 주소의 data를 컨트롤할 수 있다.
//     foo(p0);

//     // 포인터로 넘기면 소유권 이전이나 데이터 변경은 하지 않는 것이 좋다.
//     foo(p0.get());
// }



// struct Test {
//     int num;
//     Test(int num) : num(num) {
//         std::cout << "Construct: " << num << std::endl;
//     }

//     ~Test() {
//         std::cout << "Destruct: " << num << std::endl;
//     }
// };

// // 함수 객체를 생성하여, 어떻게 삭제할 것인지 정해줄 수 있다.
// struct Deleter
// {
//     void operator()(Test* test) const {
//         std::cout << "delete: " << test->num << std::endl;
//         delete test;
//     }
// };

// int main() {
//     std::unique_ptr<Test, Deleter> p0(new Test(0));

//     Test* test = p0.release();
//     // std::cout << p0->num << std::endl; // error -> 비어있음
//     std::cout << test->num << std::endl; // 0

//     delete test; // release를 통해 소유권을 넘겨줬으므로, 수동으로 삭제해줘야한다.

//     // delete 함수 객체를 사용하여 RAII의 포인터 해제를 customize할 수 있다.
//     std::unique_ptr<Test, Deleter> p0(new Test(0));
// }




// struct Test {
//     int num;
//     Test(int num) : num(num) {
//         std::cout << "Construct: " << num << std::endl;
//     }

//     ~Test() {
//         std::cout << "Destruct: " << num << std::endl;
//     }
// };

// struct Deleter
// {
//     void operator()(Test* test) const {
//         std::cout << "delete: " << test->num << std::endl;
//         delete test;
//     }
// };

// int main() {
//     auto p = std::make_unique<Test>(0);
//     // 이 상황에서 p를 p0로 move하면, p가 비게 되고 가리키던 녀석은 p0의 소유가 된다.
//     // 그렇게 되면 p0는 shared_ptr이므로 p0가 가리키는 녀석(p가 가리키던 녀석)에 대해 공유가 된다.

//     // shared_ptr은 함께 소유하는 것이 가능하다.
//     // 이녀석들은 같은 자원을 공유하는데, 그럼 해제는 어떻게 할까?
//     // 이 경우에는 reference count라는 것을 기준으로 해제를 하게 된다.
//     std::shared_ptr<Test> p0(new Test(0));
//     std::cout << p0.use_count() << std::endl; // 1

//     std::shared_ptr<Test> p1 = p0;
//     std::cout << p0.use_count() << std::endl; // 2
//     std::cout << p1.use_count() << std::endl; // 2

//     // p0에 대해서 reset을 진행해줬기 때문에 p0은 더이상 가리키고 있지 않다.
//     p0.reset();
//     std::cout << p0.use_count() << std::endl; // 0
//     std::cout << p1.use_count() << std::endl; // 1

//     // 아래와 같이 생성해줄 수도 있다.
//     std::shared_ptr<Test> p2 = std::make_shared<Test>(0);
// }



// struct Test {
//     int num;
//     Test(int num) : num(num) {
//         std::cout << "Construct: " << num << std::endl;
//     }

//     ~Test() {
//         std::cout << "Destruct: " << num << std::endl;
//     }
// };

// struct Deleter
// {
//     void operator()(Test* test) const {
//         std::cout << "delete: " << test->num << std::endl;
//         delete test;
//     }
// };

// int main() {
//     // 그렇다면 shtred_ptr에서 p1 = p0의 형식이 아니라 하나의 포인터를 둘이서 가리키면
//     // 위와 같이 정상적으로 작동할까? -> 그렇지 않다.
//     // p0 입장에서는 p1을, p1 입장에서는 p0를 알 방법이 없다.
//     // 이 녀석들이 처음으로 가리키게 되는 상황이 될 때, 내부적으로 제어블록이라는 것을 만든다.
//     Test* test = new Test(0);
//     // Delete 함수 객체를 넣어줄 수도 있다. 다만 이는 초기 생성에서만 가능하다.
//     std::shared_ptr<Test, Deleter()> p0(test);
//     // std::shared_ptr<Test> p1(test);
//     // 아래와 같이 할당을 해주면 문제가 발생하지 않는다.
//     std::shared_ptr<Test> p1(p0);

//     std::cout << p0.use_count() << std::endl;
//     std::cout << p1.use_count() << std::endl;
// }
// p0와 p1에 test를 직접 할당해주게 되면 control block을 아래와 같이 따로 생성하게 되면서 문제가 생긴다.
// control block(1) <- p0
// control block(1) <- p1

// 그러나 p0에 할당해준 후 p1에 p0을 할당해주면, 같은 control block을 가리키게 된다.
// control block(2) <- p0
//                  <- p1



// struct Test {
//     int num;
//     Test(int num) : num(num) {
//         std::cout << "Construct: " << num << std::endl;
//     }

//     ~Test() {
//         std::cout << "Destruct: " << num << std::endl;
//     }
// };

// struct Deleter
// {
//     void operator()(Test* test) const {
//         std::cout << "delete: " << test->num << std::endl;
//         delete test;
//     }
// };

// int exception() {
//     throw std::runtime_error("err");
// }

// void foo(int, std::shared_ptr<Test>) {
    
// }

// int main() {
//     try
//     {
//         // 함수 호출의 경우, 내부 실행 순서가 보장되지 않는다.
//         // 아래와 같이 호출하게 되면, 포인터를 만들고 런타임 에러가 발생하여
//         // 파괴자는 호출이 되지 않아 누수가 생길 수 있다.
//         foo(exception(), std::shared_ptr<Test>(new Test(0)));
//         // 위와 같은 상황을, 아래와 같이 makc_shared를 통해 해결 할 수 있다.
//         foo(exception(), std::make_shared<Test>(0));
//     }
//     catch(...)
//     {
//         std::cout << "catch" << std::endl;
//     }   
// }


// 순환참조로 인한 문제 -> 서로가 서로를 가리키고 있을 때
// struct B;
// struct A {
//     A() {std::cout << "Construct A" << std::endl;}
//     ~A() {std::cout << "Destruct A" << std::endl;}
//     // 순환참조 문제를 해결하기 위해선, 한쪽에서 weak_ptr을 사용해준다.
//     // std::shared_ptr<B> b;
//     std::weak_ptr<B> b;
// };

// struct B {
//     B() {std::cout << "Construct B" << std::endl;}
//     ~B() {std::cout << "Destruct B" << std::endl;}
//     std::shared_ptr<A> a;
// };

// int main() {
//     auto a = std::make_shared<A>();
//     auto b = std::make_shared<B>();

//     // 아래와 같이 실행하면, Desructed가 호출이 안 된다.
//     // 서로가 서로를 가지고있기 때문에 스마트포인터는 지워지지만
//     // 내부적으로 갖고 있는 A의 b, B의 a는 지워지지 않는 것이다.
//     // 순환참조로 인해 발생하는, 일종의 Deadlock 상황이라고 할 수 있다.
//     a->b = b;
//     b->a = a;

//     // a는 원래 있던 b와 할당된 b, 두 개의 use_count를 갖고 있다. b도 마찬가지이다.
//     // 그래서 원래 스마트포인터가 지워졌지만, count가 1씩 남아서 Destruct되지 않은 것이다.
//     // 그러나 weak_ptr을 사용하면, 사용한 포인터는 숫자가 2로 증가하지 않는다.
//     std::cout << a.use_count() << std::endl; // 2
//     std::cout << b.use_count() << std::endl; // 2
// }

// a <-> b
// a -> b(1)
// b -> a(1)



struct Test {
    int num;
    Test(int num) : num(num) {
        std::cout << "Construct: " << num << std::endl;
    }

    ~Test() {
        std::cout << "Destruct: " << num << std::endl;
    }
};


struct B;
struct A {
    A() {std::cout << "Construct A" << std::endl;}
    ~A() {std::cout << "Destruct A" << std::endl;}
    // 순환참조 문제를 해결하기 위해선, 한쪽에서 weak_ptr을 사용해준다.
    // std::shared_ptr<B> b;
    std::weak_ptr<B> b;
};

struct B {
    B() {std::cout << "Construct B" << std::endl;}
    ~B() {std::cout << "Destruct B" << std::endl;}
    std::shared_ptr<A> a;
};

int main() {
    // weak_ptr을 사용해보자.
    auto p = std::make_shared<Test>(0);
    // weak_ptr은 얕은복사? 같은 느낌이다. 잠시 빌려오는 것이다.
    std::weak_ptr<Test> w = p;
    // 만약 이 상황에서 p.reset()을 선언하면, 아래 shared는 empty가 된다.
    // weak_ptr은 삭제에 대한 권한이 없기 때문이다.
    // p.reset();

    // weak_ptr을 만들어줘도 use_count는 올라가지 않는다.
    std::cout << p.use_count() << std::endl; // 1

    // weak_ptr을 사용하려면 .lock()함수를 사용해줘야 한다.
    // w->num; // error

    // 이제서야 사용이 가능하다.
    auto shared = w.lock();
    // 이 때는 p.reset()을 해도 shared가 존재한다. shared는 이제 하나의 shared_ptr이기 때문이다.
    if (shared) {
        std::cout << (shared->num) + 10 << std::endl;
    }

    std::cout << p.use_count() << std::endl; // 2
}