#include <iostream>
#include <vector>

using std::cout;
using std::endl;


// Test 타입의 인자값이 들어오면 다르게 동작하도록 함수 템플릿 특수화하기
// class Test {};

// template<typename T>
// void swap (T& x, T& y) {
//     cout << "swap" << endl;
//     T temp = x;
//     x = y;
//     y = temp;
// }

// // Test type에 대한 템플릿 특수화
// template<> // 아래와 같이 완벽하게 추론이 된 녀석은 좌측의 template<이곳>에 타입을 넣지 않는다.
// void swap<Test>(Test& x, Test& y) { // 여기서 <Test>는 빼줘도 컴파일러가 암시적으로 추론한다.
//     cout << "swap<Test>" << endl;
// }

// int main() {
//     Test t0, t1;
//     swap(t0, t1);
// }

// class Test {};

// template<typename T>
// void swap (T& x, T& y) {
//     cout << "swap" << endl;
//     T temp = x;
//     x = y;
//     y = temp;
// }

// // 아래 상황에서, 포인터를 넘겨줬을 때, x와 y가 바뀌게 하고 싶어 템플릿 특수화
// // 그런데 아래와 같은 경우는, 원래 swap함수와 특수화 관계라고 할 수 없다.
// // 파라미터의 타입이 다르기 때문이다. 템플릿 함수가 특수화 관계에 놓이려면
// // 두 함수의 프로토타입이 같아야 한다.(파라미터 타입, 개수 등)
// template<typename T>
// void swap (T* x, T* y) {
//     cout << "swap pointer" << endl;
//     T temp = *x;
//     *x = *y;
//     *y = temp;
// }

// // 이전 스왑함수를 그대로 유지하고 실행했을 때, 아래 x와 y의 값은 바뀌지 않는다.
// // 사실 이는, 포인터인 px와 py가 가리키는 값이 바뀐 것이다. 무슨 말이냐면
// // 포인터를 넣어서 서로 값을 바꿔줬기 때문에, px는 &y를 가리키게 되는 것이고
// // px는 &y를 가리키게 되는 것이다.
// int main() {
//     int x = 10, y = 20;
//     int *px = &x, *py = &y;
//     swap(px, py);

//     cout << x << endl; // 10
//     cout << y << endl; // 20

//     cout << *px << endl; // 20
//     cout << *py << endl; // 10
// }

// template<typename T, typename S>
// class Test {
// public:
//     T num0;
//     S num1;
// };

// // 위 class와 아래 class는 template 파라미터의 개수가 다르기 때문에 서로 다른 녀석이다.
// template<typename T>
// class Test {};

// // 클래스 템플릿 완전 특수화
// template<> // 완전 특수화는 template<이 안에> typename을 넣어주지 않아도 된다.
// // Test<이 안에> 타입이 다 정해져서 나왔다. -> 완전 특수화
// class Test<int, float> {};

// template<typename T>
// // 타입이 모두 완전히 정해지진 않았음 -> 부분 특수화
// class Test<T, T> {};

// template<typename T>
// // 이 또한 타입이 모두 완전히 정해지진 않았음 -> 부분 특수화
// class Test<T, int> {};

// int main() {
//     Test<int, int> t0; // 맨 위 클래스로 간다.
//     Test<int, float> t1; // 두번째 클래스로 간다.
// }

// int main() {
//     std::vector<int> v;
//     std::vector<float> fv;
//     // 이 경우, boolean의 template만 특수화가 되어있다.
//     // boolean의 데이터는 1byte인데, 이는 사실 8개의 t/f를 담을 수 있는 크기이다.
//     // 이런 부분에 있어 최적화를 진행하기 위해 특수화가 되어있는 것이다.
//     std::vector<bool> bv;
// }


// 템플릿 클래스의 멤버함수에 대해서만 특수화를 진행해보기
template<typename T>
class Queue {
private:
    std::vector<T> _items;

public:
    void push(T item) {
        _items.push_back(item);
    }
};

// 원래 함수를 외부화 할 때의 구조
// 지금은 위에도 있기 때문에 이렇게 하면 이중정의가 되어 컴파일 불가하다.
// template<typename T>
// void Queue<T>::push(T item) {}

// int type에 대해서만 다른 처리를 해주고 싶을 때의 특수화
template<>
void Queue<int>::push(int item) {
cout << "int" << endl;
}

int main() {
    Queue<float> q0;
    q0.push(1.f);
    Queue<int> q1;
    q1.push(1); // int
}