#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Queue를 만든다. 이 queue는 멤버로 vector를 가지고 있다.
// 이 때 Queue와 vector v와 Queue의 관계는 has a 관계이다.
// 이와같이 어떤 클래스의 멤버변수로서 has a 관계를 나타내는 것을 containment라고 부른다.
// class Queue {
// private:
//     vector<int>  v;
// public:
//     void push(int value) {
//         v.push_back(value);
//     }
//     void pop() {
//         v.pop_back();
//     }
//     int top() {
//         return v.back();
//     }
// };

// int main() {
    
// }

// // vector를 private상속 받았다.
// // 일반적으로 우리가 아는 상속은 부모(vector)의 모든 녀석들을 받는것이다.
// // 마찬가지로 Queue라는 class는 vector의 모든 멤버함수들을 갖고있게 된다.
// class Queue : private vector<int> {
// public:
//     Queue() {}
//     void push(int value) {
//         // this->push_back()이 아니라 그냥 push_back()을 해준다.
//         // 이 부분이 조금 헷갈리긴 하는데, 이 Queue를 어떤 멤버변수가 있는 class라기보다
//         // 그냥 vector 그 자체라고 생각하면 편할 것 같다.
//         // 그냥 vector에 있는 기능들을 사용해 내가 customize하여 원하는 형태를 만드는 것이다.
//         // 예를 들어 Queue라는 자료형을 만들기 위해 vector를 private 상속받고
//         // 내부적으로 원하는 기능만 사용하여 원하는 자료형을 만들 수 있는 것이다.
//         push_back(value);
//     }
//     void pop() {
//         pop_back();
//     }
//     int top() {
//         return back();
//     }
// };

// int main() {
//     Queue queue;

//     // 아래에서 함수를 실행할 때, vector를 public으로 받았는가, private으로 받았는가의 차이가 생긴다.
//     // public으로 받은 경우, 외부에서 queue에 대해 부모 class인 vector의 모든 public 멤버에 접근할 수 있다.
//     // private으로 받은 경우, 외부에서 queue에 대해 Queue의 public 멤버함수에만 접근할 수 있다.
//     queue.push(10);
//     cout << queue.top() << endl; // 10

//     queue.push(20);
//     cout << queue.top() << endl; // 20

//     queue.pop();
//     cout << queue.top() << endl; // 30

//     // 아래와 같이 선언했을 때, public 상속이면 Queue에서 부모인 vector의 모든 public, protected 멤버를
//     // Queue의 public으로 받아져 사용할 수 있기 때문에 정상적으로 가리킬 수 있게 된다.
//     // 그런데 private 상속이면 Queue에서 부모인 vector의 모든 public, protected 멤버를
//     // Queue의 private으로 받아지기 때문에 Queue 내부에서는 다룰 수 있지만 외부에서 접근이 불가하다.
//     // 따라서 vector<int>* 포인터로 Queue를 가리켰을 때, vector와 동일시할 수 없기 때문에
//     // 아래와 같은 선언이 불가하다.
//     vector<int>* vp = new Queue(); // public 상속시 정상 -> private 상속시 error
// }

// class Queue : private vector<int> {
// public:
//     Queue() {}
//     void push(int value) {

//         push_back(value);
//     }
//     void pop() {
//         pop_back();
//     }
//     int top() {
//         return back();
//     }
// };

// // 이번에는 Queue를 상속받는 자식 클래스를 만들어보자
// // 아래 자식 클래스에서는 vector 멤버함수에 접근할 수 없고, Queue의 멤버함수에만 접근할 수 있다.
// // 이는 vector의 멤버가 Queue에만 private으로 상속되었기 때문에
// // Queue의 private 멤버에 그 자식 클래스가 접근할 수 없는 것이다.
// class PriorityQueue : public Queue {
// public:
//     void func() {
//         this->pop(); // 위 세 개만 가능
//     }
// };

// int main() {
//     Queue queue;

//     queue.push(10);
//     cout << queue.top() << endl; // 10

//     queue.push(20);
//     cout << queue.top() << endl; // 20

//     queue.pop();
//     cout << queue.top() << endl; // 30
// }


// protected 상속을 알아보자
// vector를 Queue에 protected로 상속해준다.
class Queue : protected vector<int> {
public:
    Queue() {}
    virtual void push(int value) {

        push_back(value);
    }
    virtual void pop() {
        pop_back();
    }
    virtual int top() {
        return back();
    }
    virtual ~Queue(){}
};

// vector의 public, protected 멤버들이 Queue의 protected 멤버로 상속되었기 때문에
// Queue를 public으로 상속받는 PriorityQueue는 vector의 public, protected 멤버를
// 사용할 수 있다.
// 다만, Queue가 vector를 protected로 받았기 때문에, PQ가 Queue를 public으로 받았지만
// PQ를 통해 vector의 모든 멤버에 접근할 수 있는 것은 아니다. 아마도 PQ에 protected로 받아지는 것 같다.
class PriorityQueue : public Queue {
public:
    virtual void push(int value) override {
        Queue::push(value);
        // vector에 있는 메소드
        push_heap(begin(), end());
    }
    virtual void pop() override {
        // vector에 있는 메소드
        pop_heap(begin(), end());
        Queue::pop();
    }
    virtual int top() override {
        return front();
    }
};

int main() {
    // max heap -> 큰 순서대로 높은 곳에 있음
    PriorityQueue pq;
    Queue& q = pq; // 이렇게 선언하고 q에 대해서 아래 연산들을 실행해도 잘 된다.
    pq.push(10);
    pq.push(100);
    pq.push(0);

    cout << pq.top() << endl; // 100
    pq.pop();

    cout << pq.top() << endl; // 10
    pq.pop();
    
    cout << pq.top() << endl; // 0
    pq.pop();
}