#include <iostream>
#include <vector>

using std::cout;
using std::endl;


// template<typename T>
// class Queue {
// private:
//     // 현재 들어있는 데이터의 수
//     size_t _size;
//     // 담을 수 있는 데이터의 양
//     size_t _capacity;
//     // 담고자 하는 데이터타입의 포인터(배열)
//     T* _items;

// public:
//     Queue() 
//         : _size(0)
//         , _capacity(4)
//         // 허용되는 _capacity크기의 T 타입 동적 배열을 _items에 넣어준다.
//         // 결국 뭐 char* _items = new char[4]; 이런 느낌인 것이다.
//         , _items(new T[_capacity]) {}

//     ~Queue() {
//         // 동적할당된 배열은 해제를 해준다.
//         delete[] _items;
//     }

//     void push(T item) {
//         // 현재 size(들어있는 수)가 _capacity(허용량)보다 작다면
//         if (_size < _capacity) {
//             // _items[_size]에 item을 넣고 _size는 1 증가시킨다.(다음을 위해)
//             _items[_size++] = item;
//         }
//         // 현재 들어있는 수가 허용량보다 작지 않다면(같다면) 
//         else {
//             // 새로운 capacity를 담을 변수 _capacity의 2배로 초기화
//             size_t newCapacity = _capacity * 2;
            
//             // 이전 _items 주소를 가리키는 oldItems 포인터를 만들어준다.
//             T* oldItems = _items;
//             // newCapacity 크기의 새로운 동적 배열을 만들어준다.
//             T* newItems = new T[newCapacity];

//             // 현재 _items에 담겨있는 모든것들을 newItems로 복사해준다.
//             std::copy(oldItems, oldItems + _capacity, newItems);
            
//             // _capacity(허용량) 업데이트
//             _capacity = newCapacity;
//             // _items를 newItems로 바꿔준다.
//             _items = newItems;

//             // 지난 _items에 대한 포인터를 해제해준다.
//             delete[] oldItems;

//             // 재귀 기능을 활용하여, 현재 있는 push 함수를 다시 호출해준다.
//             push(item);
//         }
//     }

//     void pop() {
//         --_size;
//     }

//     T& top() {
//         return _items[_size-1];
//     }
// };

// int main() {
//     Queue<int> q0;
//     q0.push(1);
//     q0.push(2);
//     q0.push(4);
//     cout << q0.top() << endl; // 4
//     q0.pop();
//     cout << q0.top() << endl; // 2

//     Queue<std::string> q1;
//     q1.push("abcd");
//     q1.push("cdef");
//     cout << q1.top() << endl; // cdef
//     q1.pop();
//     cout << q1.top() << endl; // abcd
// }


// Queue의 사이즈를 정한 상태로 만들어보자(동적배열 없이)
// template<typename T, int N>
// class Queue {
// private:
//     size_t _size;
//     T _items[N];

// public:
//     Queue() 
//         : _size(0)
//         , _items{} {

//         }

//     void push(T item) {
//         if (_size < N) {
//             _items[_size++] = item;
//         } else {
//             throw std::out_of_range("overflow");
//         }
//     }

//     void pop() {
//         if (_size == 0) {
//             throw std::out_of_range("underflow");
//         }
//         --_size;
//     }

//     T& top() {
//         return _items[_size-1];
//     }
// };

// int main() {
//     Queue<int, 3> q0;
//     q0.push(1);
//     q0.push(2);
//     q0.push(4);
//     cout << q0.top() << endl; // 4
//     q0.pop();
//     cout << q0.top() << endl; // 2

//     Queue<std::string, 1> q1;
//     q1.push("abcd");
//     try {
//         q1.push("cdef");
//     } catch (std::out_of_range& e) {
//         cout << e.what() << endl;
//     }
    
//     cout << q1.top() << endl; // cdef
//     q1.pop();
//     cout << q1.top() << endl; // abcd
// }


// 함수의 구현을 분리해보자
// template<typename T, int N>
// class Queue {
// private:
//     size_t _size;
//     T _items[N];

// public:
//     Queue();
//     void push(T item);
//     void pop();
//     T& top();
// };

// template<typename T, int N>
// Queue<T, N>::Queue() 
//     : _size(0)
//     , _items{} {

//     }

// template<typename T, int N>
// void Queue<T, N>::push(T item) {
//     if (_size < N) {
//         _items[_size++] = item;
//     } else {
//         throw std::out_of_range("overflow");
//     }
// }

// template<typename T, int N>
// void Queue<T, N>::pop() {
//     if (_size == 0) {
//         throw std::out_of_range("underflow");
//     }
//     --_size;
// }

// template<typename T, int N>
// T& Queue<T, N>::top() {
//     return _items[_size-1];
// }

// int main() {
//     Queue<int, 3> q0;
//     q0.push(1);
//     q0.push(2);
//     q0.push(4);
//     cout << q0.top() << endl; // 4
//     q0.pop();
//     cout << q0.top() << endl; // 2

//     Queue<std::string, 1> q1;
//     q1.push("abcd");
//     try {
//         q1.push("cdef");
//     } catch (std::out_of_range& e) {
//         cout << e.what() << endl;
//     }
    
//     cout << q1.top() << endl; // cdef
//     q1.pop();
//     cout << q1.top() << endl; // abcd
// }


// 동적 배열을 사용할 때, vector를 사용해보자
template<typename T>
class Queue {
private:
    // 상위 template parameter를 하위(여기에선 vector) template parameter로 넘겨줄 수도 있다.
    std::vector<T> _items;

public:
    Queue();
    void push(T item);
    void pop();
    T& top();
};

template<typename T>
Queue<T>::Queue() 
    : _items{} {}

template<typename T>
void Queue<T>::push(T item) {
    _items.push_back(item);
}

template<typename T>
void Queue<T>::pop() {
    if (_items.size() == 0) {
        throw std::out_of_range("underflow");
    }
    _items.pop_back();
}

template<typename T>
T& Queue<T>::top() {
    return _items.back();
}

int main() {
    Queue<int> q0;
    q0.push(1);
    q0.push(2);
    q0.push(4);
    cout << q0.top() << endl; // 4
    q0.pop();
    cout << q0.top() << endl; // 2

    Queue<std::string> q1;
    q1.push("abcd");
    q1.push("cdef");
    cout << e.what() << endl;
    cout << q1.top() << endl; // cdef
    q1.pop();
    cout << q1.top() << endl; // abcd
}